//each coin can be used for 1 time
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 20 //maximum number of coin
#define MAX_W 10000 // maximum value of w
#define INF 999999

int mem[MAX_N][MAX_W];

int validCell(int i,int w,vector<int>coin)
{
    if(w<0)return INF;
    if(i==coin.size())
    {
        if(w==0)return 0;
        return INF;
    }
    return mem[i][w];
}

int coinChange(int w,vector<int>coin)
{

    for(int i=coin.size()-1;i>=0;i--)
    {
        for(int j=0;j<=w;j++)
        {
            int res1=1+validCell(i+1,j-coin[i],coin);
            int res2=validCell(i+1,j,coin);
            cout<<"RES1: "<<res1<<"\t"<<"RES2: "<<res2<<endl;
            int ans = min(res1,res2);
            cout<<"ANS: "<<ans<<endl;
            mem[i][j]=ans;

        }
    }

    return mem[0][w];
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
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{

    vector<int>coin={2,5,9,13,15};
    int w=22;
    cout<<"Total coin need: "<<coinChange(w,coin)<<endl;
    return 0;
}


