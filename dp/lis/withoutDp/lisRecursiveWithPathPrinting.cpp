#include<bits/stdc++.h>
using namespace std;

int nextIndex[7];
vector<int>path;

int longestIncreasingSubsequence(int i,vector<int>v)
{
    if(i==v.size()-1)return 1;
    int ans=0;
    for(int j=i+1;j<v.size();j++)
    {
        //cout<<"I: "<<i<<" J:"<<j<<endl;
        if(v[j]>v[i])
        {
            //ans = max(ans,longestIncreasingSubsequence(j,v));
            int res=longestIncreasingSubsequence(j,v);
            if(res>ans)
            {
              ans=res;
              nextIndex[i]=j;
            }
            //cout<<ans<<endl;
        }
    }
    return ans+1;
}

int lis(vector<int>v)
{
    int res=0;
    memset(nextIndex,-1,sizeof(nextIndex));
    int startIndex=-1;
    for(int i=0;i<v.size();i++)
    {
        int ans=longestIncreasingSubsequence(i,v);
        //cout<<"RESULT FROM "<<v[i]<<": "<<ans<<endl;
        //res=max(res,ans);
        if(ans>res)
        {
            res=ans;
            startIndex=i;
        }
    }
    while(startIndex!=-1)
    {
        path.push_back(v[startIndex]);
        startIndex=nextIndex[startIndex];
    }
    return res;
}


int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Longest increasing subsequence: "<<lis(v)<<endl;
    cout<<"Solution path: ";
    for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
    cout<<endl;
    return 0;
}


