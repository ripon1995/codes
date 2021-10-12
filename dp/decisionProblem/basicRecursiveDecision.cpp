#include<bits/stdc++.h>
using namespace std;


//recursive approach. bottom up approach.
//here i starts from 0
//each coin can be used one time
int subsetSum(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(coin[i]>w) return subsetSum(i+1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSum(i+1,w-coin[i],coin);
    int exclude = subsetSum(i+1,w,coin);
    int ans = include||exclude;
    return ans;

}



//recursive approach. bottom up approach.
//here i starts from 0
//each coin can be used multiple time
int subsetSumMultiple(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(coin[i]>w) return subsetSumMultiple(i+1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSumMultiple(i,w-coin[i],coin);
    int exclude = subsetSumMultiple(i+1,w,coin);
    int ans = include||exclude;
    return ans;

}

//recursive approach 2. top down approach.
//here n starts from coin.size()
//each coin can be used one time
int subsetSum2(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(coin[n-1]>w) return subsetSum2(n-1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSum2(n-1,w-coin[n-1],coin);
    int exclude = subsetSum2(n-1,w,coin);
    int ans = include||exclude;
    return ans;
}


//recursive approach 2. top down approach.
//here n starts from coin.size()
//each coin can be used multiple time
int subsetSum2Multiple(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(coin[n-1]>w) return subsetSum2Multiple(n-1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSum2Multiple(n,w-coin[n-1],coin);
    int exclude = subsetSum2Multiple(n-1,w,coin);
    int ans = include||exclude;
    return ans;
}


int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 9;
    cout<<"Approach 1==> Possibility to make w using one coin only one time: "<<subsetSum(0,w,v)<<endl;
    cout<<"Approach 1==> Possibility to make w using one coin multiple time: "<<subsetSumMultiple(0,w,v)<<endl;
    cout<<"Approach 2==> Possibility to make w using one coin only one time: "<<subsetSum2(v.size(),w,v)<<endl;
    cout<<"Approach 2==> Possibility to make w using one coin multiple time: "<<subsetSum2Multiple(v.size(),w,v)<<endl;
    return 0;
}


