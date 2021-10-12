#include<bits/stdc++.h>
using namespace std;

#define SZ 20

int mem[SZ];

int findLis(vector<int>v)
{
    memset(mem,-1,sizeof(mem));

    for(int i =v.size()-1;i>=0;i--)
    {
        int ans = 0;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]>v[i])
            {
                ans = max(ans,mem[j]);
            }
        }
        mem[i]=ans+1;
    }
    int finalAns = 0;
    for(int i = 0;i<v.size();i++)
    {
        finalAns = max(finalAns,mem[i]);
    }

    return finalAns;
}

int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Length of longest increasing subsequence: "<<findLis(v)<<endl;
    return 0;
}


