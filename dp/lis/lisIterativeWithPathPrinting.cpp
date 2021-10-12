#include<bits/stdc++.h>
using namespace std;

#define SZ 20

int mem[SZ];
int nextIndex[SZ];
vector<int>lisData;

int findLis(vector<int>v)
{
    memset(mem,-1,sizeof(mem));
    memset(nextIndex,-1,sizeof(nextIndex));

    for(int i =v.size()-1;i>=0;i--)
    {
        int ans = 0;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]>v[i])
            {
                if(mem[j]>ans)
                {
                    ans = mem[j];
                    nextIndex[i]=j;
                }
            }
        }
        mem[i]=ans+1;
    }
    int finalAns = 0;
    int startIndex=-1;
    for(int i = 0;i<v.size();i++)
    {
        if(mem[i]>finalAns)
        {
            finalAns = mem[i];
            startIndex = i;
        }
    }

    while(startIndex!=-1)
    {
        lisData.push_back(v[startIndex]);
        startIndex = nextIndex[startIndex];
    }

    return finalAns;
}

int main()
{
    vector<int>v={5,0,9,2,7,3,4};
    cout<<"Length of longest increasing subsequence: "<<findLis(v)<<endl;
    cout<<"Longest increasing subsequence: ";
    for(int i=0;i<lisData.size();i++)cout<<lisData[i]<<"\t";
    cout<<endl;
    return 0;
}


