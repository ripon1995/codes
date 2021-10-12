#include<bits/stdc++.h>
using namespace std;

int mem[20][100];

void init(int w,int sz)
{
    for(int i=0;i<=sz;i++)for(int j=0;j<=w;j++) mem[i][j]=-1;
}
void printMem(int w,int sz)
{
    for(int i=0;i<=sz;i++)
    {
        for(int j=0;j<=w;j++) cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}
//recursive approach. bottom up approach.
//here i starts from 0
int subsetSum(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(mem[i][w]!=-1)return mem[i][w];
    int include = subsetSum(i+1,w-coin[i],coin);
    int exclude = subsetSum(i+1,w,coin);

    mem[i][w] = include+exclude;
    return mem[i][w];
}

//recursive approach 2. top down approach.
//here n starts from coin.size()
int subsetSum2(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(mem[n][w]!=-1)return mem[n][w];
    int include = subsetSum2(n-1,w-coin[n-1],coin);
    int exclude = subsetSum2(n-1,w,coin);

    mem[n][w] = include+exclude;
    return mem[n][w];
}


int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 20;
    init(w,v.size());
    printMem(w,v.size());
    cout<<"Approach 1==> Total way to make w: "<<subsetSum2(v.size(),w,v)<<endl;
     printMem(w,v.size());
     cout<<endl<<endl<<endl;

     init(w,v.size());
    printMem(w,v.size());
    cout<<"Approach 2==> Total way to make w: "<<subsetSum(0,w,v)<<endl;
     printMem(w,v.size());
    return 0;
}

