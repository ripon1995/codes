#include<bits/stdc++.h>
using namespace std;

int mem[20][20];

void printMem(int n,int r)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=r;j++) cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}


int combination(int n,int r)
{
    for(int i=0;i<=r;i++)mem[0][i]=0;
    for(int i=0;i<=n;i++)mem[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=r;j++)
        {
            if(j>i) mem[i][j]=mem[i-1][j];
            else
            {
                int include=mem[i-1][j-1];
                int exclude=mem[i-1][j];
                int ans = include + exclude;
                mem[i][j]=ans;
            }
        }
    }
    return mem[n][r];

}


int main()
{
    int n=5;
    int r=3;
    cout<<combination(50,30)<<endl;
    return 0;
}
