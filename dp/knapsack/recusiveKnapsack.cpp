#include<bits/stdc++.h>
using namespace std;
#define MAX_N 20 //maximum number of coin
#define MAX_W 10000 // maximum value of w
#define INF 999999

int mem[MAX_N][MAX_W];

int knapsack(int i,int w,vector<int>weight,vector<int>price)
{

    if(i==weight.size()||w==0)return 0;
    if(mem[i][w]!=-1)return mem[i][w];

    if(weight[i]>w)
    {
        mem[i][w]=knapsack(i+1,w,weight,price);
        return mem[i][w];
    }

    else
    {

    int res1=price[i]+knapsack(i+1,w-weight[i],weight,price);
    int res2=knapsack(i+1,w,weight,price);

    mem[i][w]=max(res1,res2);
    return mem[i][w];
    }

}
int main()
{

    vector<int>weight={4,3,2,1};
    vector<int>price={100,150,200,50};
    int w=4;
    for(int i=0;i<=weight.size();i++)for(int j=0;j<=w;j++)mem[i][j]=-1;
    cout<<"Maximum profit: "<<knapsack(0,w,weight,price)<<endl;

    return 0;
}



