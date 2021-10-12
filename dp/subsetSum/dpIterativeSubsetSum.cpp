#include<bits/stdc++.h>
using namespace std;

int mem[20][100];

void printMem(int w,int sz)
{
    for(int i=0;i<=sz;i++)
    {
        for(int j=0;j<=w;j++) cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}

int subsetSum(int w,vector<int>coin)
{
    for(int j=0;j<=w;j++)mem[0][j]=0;
    for(int i=0;i<=coin.size();i++)mem[i][0]=1;

    for(int i=1;i<=coin.size();i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(coin[i-1]>j)mem[i][j]=mem[i-1][j];
            else
            {
                int include=mem[i-1][j-coin[i-1]];
                int exclude=mem[i-1][j];
                int ans = include+exclude;
                mem[i][j]=ans;
            }
        }
    }
    return mem[coin.size()][w];
}

int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 20;
    cout<<"Total ways: "<<subsetSum(w,v)<<endl;
    //printMem(w,v.size());
    return 0;
}
