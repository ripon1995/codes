#include<bits/stdc++.h>
using namespace std;

#define SZ 20

int mem[SZ];
int nextIndex[SZ];
vector<int>lisData;


int lis(int i,vector<int>v)
{
    if(mem[i]!=-1)return mem[i];
    int ans = 0;
    for(int j=i+1;j<v.size();j++)
    {
        if(v[j]>v[i])
        {
            int res = lis(j,v);
            if(res>ans)
            {
                ans = res;
                nextIndex[i]=j;
            }
        }
    }
    mem[i]=ans+1;
    return mem[i];
}

int findLis(vector<int>v)
{
    memset(mem,-1,sizeof(mem));
    memset(nextIndex,-1,sizeof(nextIndex));

    int ans = 0;
    int startIndex=-1;
    for(int i=0;i<v.size();i++)
    {
        int res = lis(i,v);
        if(res>ans)
        {
            ans = res;
            startIndex = i;
        }
    }

    while(startIndex!=-1)
    {
        lisData.push_back(v[startIndex]);
        startIndex = nextIndex[startIndex];
    }

    return ans;

}

int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Length of longest increasing subsequence: "<<findLis(v)<<endl;
    cout<<"Longest increasing subsequence: ";
    for(int i = 0;i<lisData.size();i++)cout<<lisData[i]<<" ";
    cout<<endl;
    return 0;
}


