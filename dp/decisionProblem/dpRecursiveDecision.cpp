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
// each coin can be taken only one time
int subsetSum(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(mem[i][w]!=-1)return mem[i][w];
    int include = subsetSum(i+1,w-coin[i],coin);
    int exclude = subsetSum(i+1,w,coin);

    mem[i][w] = include||exclude;
    return mem[i][w];
}


//recursive approach. bottom up approach.
//here i starts from 0
//each coin can be taken multiple time
int subsetSumMultiple(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(mem[i][w]!=-1)return mem[i][w];
    int include = subsetSumMultiple(i,w-coin[i],coin);
    int exclude = subsetSumMultiple(i+1,w,coin);

    mem[i][w] = include||exclude;
    return mem[i][w];
}


//recursive approach 2. top down approach.
//here n starts from coin.size()
//each coin can be taken only one time
int subsetSum2(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(mem[n][w]!=-1)return mem[n][w];
    int include = subsetSum2(n-1,w-coin[n-1],coin);
    int exclude = subsetSum2(n-1,w,coin);

    mem[n][w] = include||exclude;
    return mem[n][w];
}

//recursive approach 2. top down approach.
//here n starts from coin.size()
//each coin can be taken multiple time
int subsetSum2Multiple(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(mem[n][w]!=-1)return mem[n][w];
    int include = subsetSum2Multiple(n,w-coin[n-1],coin);
    int exclude = subsetSum2Multiple(n-1,w,coin);

    mem[n][w] = include||exclude;
    return mem[n][w];
}

int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 9;
    init(w,v.size());
    //printMem(w,v.size());
    cout<<"Approach 1==> Possibility to make w using one coin only one time: "<<subsetSum(0,w,v)<<endl;

    init(w,v.size());
    //printMem(w,v.size());
    cout<<"Approach 1==> Possibility to make w using one coin multiple time: "<<subsetSumMultiple(0,w,v)<<endl;


    init(w,v.size());
    //printMem(w,v.size());
    cout<<"Approach 2==> Possibility to make w using one coin only one time: "<<subsetSum2(v.size(),w,v)<<endl;
     //printMem(w,v.size());

     init(w,v.size());
    //printMem(w,v.size());
    cout<<"Approach 2==> Possibility to make w using one coin multiple time: "<<subsetSum2Multiple(v.size(),w,v)<<endl;

    return 0;
}


