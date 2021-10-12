#include<bits/stdc++.h>
using namespace std;

#define SZ 20

int mem[SZ][SZ];

int lcs(int i, int j,string s,string t)
{
    if(i==s.size() || j==t.size())return 0;
    if(mem[i][j]!=-1)return mem[i][j];
    int ans=0;
    if(s[i]==t[j])
    {
        ans= 1+lcs(i+1,j+1,s,t);
    }
    if(s[i]!=t[j])
    {
        ans= max(lcs(i+1,j,s,t),lcs(i,j+1,s,t));
    }
    mem[i][j]=ans;
    return mem[i][j];
}

void init()
{
    for(int i=0;i<SZ;i++)
    {
        for(int j=0;j<SZ;j++)mem[i][j]=-1;
    }
}

int main()
{
    init();
    string s="HELLOM";
    string t="HLL";
    cout<<"Longest common subsequence: "<<lcs(0,0,s,t)<<endl;
    return 0;
}


