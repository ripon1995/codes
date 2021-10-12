#include<bits/stdc++.h>
using namespace std;

bool mem[20][100];

void printMem(int w,int sz)
{
    for(int i=0;i<=sz;i++)
    {
        for(int j=0;j<=w;j++) cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}

//each coin can be used only one time
bool isSubsetSum(int w,vector<int>coin)
{
    for(int j=0;j<=w;j++)mem[0][j]=false;
    for(int i=0;i<=coin.size();i++)mem[i][0]=true;

    for(int i=1;i<=coin.size();i++)
    {
        for(int j=1;j<=w;j++)
        {
            //if(i==0)mem[i][j]=0;
            //else if(j==0)mem[i][j]=1;
            if(coin[i-1]>j)mem[i][j]=mem[i-1][j];
            else
            {
                int include=mem[i-1][j-coin[i-1]];
                int exclude=mem[i-1][j];
                int ans = include || exclude;
                mem[i][j]=ans;
            }
        }
    }
    return mem[coin.size()][w];
}

//each coin can be used multiple time
bool mem2[20][100];
bool isSubsetSum2(int w,vector<int>coin)
{
    for(int j=0;j<=w;j++)mem2[0][j]=false;
    for(int i=0;i<=coin.size();i++)mem2[i][0]=true;

    for(int i=1;i<=coin.size();i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(coin[i-1]>j)mem2[i][j]=mem2[i-1][j];
            else
            {
                int include=mem2[i][j-coin[i-1]];
                int exclude=mem2[i-1][j];
                int ans = include || exclude;
                mem2[i][j]=ans;
            }
        }
    }
    return mem2[coin.size()][w];
}



int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 9;
    cout<<"Using coin one time: "<<isSubsetSum(w,v)<<endl;
    cout<<"Using coin multiple time: "<<isSubsetSum2(w,v)<<endl;
    return 0;
}

