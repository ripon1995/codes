#include<bits/stdc++.h>
using namespace std;

#define SZ 20

int mem[SZ];

int lis(int i,vector<int>v)
{
    if(mem[i]!=-1)return mem[i];
    int ans = 0;
    for(int j=i+1;j<v.size();j++)
    {
        if(v[j]>v[i])
        {
            ans = max(ans,lis(j,v));
        }
    }
    mem[i]=ans+1;
    return mem[i];
}

int findLis(vector<int>v)
{
    memset(mem,-1,sizeof(mem));
    int ans = 0;
    for(int i=0;i<v.size();i++)
    {
        ans = max(ans,lis(i,v));
    }
    return ans;
}

int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Length of longest increasing subsequence: "<<findLis(v)<<endl;
    return 0;
}


