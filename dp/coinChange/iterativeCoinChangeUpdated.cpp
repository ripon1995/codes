#include<bits/stdc++.h>
using namespace std;
#define MAX_N 6 //maximum number of coin
#define MAX_W 1000 // maximum value of w
#define INF 999999

int mem[MAX_N][MAX_W];

int coinChange(int w,vector<int>coin)
{

    for(int i=0;i<=coin.size();i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0)mem[i][j]=INF;
            else if(j==0)mem[i][j]=0;
            else if(j-coin[i-1]<0)mem[i][j]=mem[i-1][j];
            else
            {
                int include=1+mem[i][j-coin[i-1]];
                int exclude=mem[i-1][j];
                int ans = min(include,exclude);
                mem[i][j]=ans;
            }

        }
    }

    return mem[coin.size()][w];
}

int main()
{

    vector<int>coin={1,5,10,20,100};
    int w=4;
    cout<<"Total coin need: "<<coinChange(w,coin)<<endl;
    return 0;
}



