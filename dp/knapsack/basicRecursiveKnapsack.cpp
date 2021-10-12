#include<bits/stdc++.h>
using namespace std;
#define MAX_N 20 //maximum number of coin
#define MAX_W 10000 // maximum value of w
#define INF 999999


int knapsack(int i,int w,vector<int>weight,vector<int>price)
{

    if(i==weight.size()||w==0)return 0;

    if(weight[i]>w)return knapsack(i+1,w,weight,price);

    else
    {

    int res1=price[i]+knapsack(i+1,w-weight[i],weight,price);
    int res2=knapsack(i+1,w,weight,price);

    int ans=max(res1,res2);
    return ans;
    }

}
int main()
{

    vector<int>weight={4,3,2,1};
    vector<int>price={100,150,200,50};
    int w=4;
    cout<<"Maximum profit: "<<knapsack(0,w,weight,price)<<endl;

    return 0;
}


