//any coin can be taken unlimited time
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 20 //maximum number of coin
#define MAX_W 10000 // maximum value of w
#define INF 999999

int mem[MAX_N][MAX_W];

int coinChange(int i,int w,vector<int>coin)
{
    if(w<0)return INF;
    if(i==coin.size())
    {
        if(w==0)return 0;
        return INF;
    }
    if(mem[i][w]!=-1)
    {
        return mem[i][w];
    }
    int res1=1+coinChange(i,w-coin[i],coin);
    int res2=coinChange(i+1,w,coin);
    int ans = min(res1,res2);
    mem[i][w]=ans;
    return ans;
}

void init(int n,int w)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)mem[i][j]=-1;
    }
}

void printDpTable(int n,int w)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<w;j++)cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{

    vector<int>coin={2,5,9,13,15};
    int w=30;
    init(coin.size(),w);
    cout<<"Total coin need: "<<coinChange(0,w,coin)<<endl;
    return 0;
}



