#include<bits/stdc++.h>
using namespace std;


int longestIncreasingSubsequences(vector<int>v)
{
    int maxLen=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            int finalAns=1;
            if(v[j]>v[i])
            {
                int next=v[j];
                int ans=0;
                for(int k=j+1;k<v.size();k++)
                {
                    if(v[k]>next)
                    {
                        next=v[k];
                        ans++;
                    }
                    else next=v[j];
                }
                finalAns+=ans;
                maxLen=max(maxLen,finalAns);
            }

        }

    }

    return maxLen+1;
}


int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Longest increasing subsequence: "<<longestIncreasingSubsequences(v)<<endl;
    return 0;
}

