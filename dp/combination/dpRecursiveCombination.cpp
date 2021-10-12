#include<bits/stdc++.h>
using namespace std;

int mem[20][20];

void init(int n,int r)
{
    for(int i=0;i<=n;i++)for(int j=0;j<=r;j++) mem[i][j]=-1;
}

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
    if(r>n)return 0;
    if(r==0 || r==n)return 1;
    if(mem[n][r]!=-1)return mem[n][r];
    int include = combination(n-1,r-1);
    int exclude = combination(n-1,r);
    int ans = include+exclude;
    mem[n][r]=ans;
    return mem[n][r];
}


int main()
{
    int n=5;
    int r=3;
    init(n,r);
    cout<<combination(5,3)<<endl;
    printMem(n,r);
    return 0;
}


