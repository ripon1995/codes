#include<bits/stdc++.h>
using namespace std;


//recursive approach. bottom up approach.
//here i starts from 0
int subsetSum(int i,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(i==coin.size())return 0;
    if(coin[i]>w) return subsetSum(i+1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSum(i+1,w-coin[i],coin);
    int exclude = subsetSum(i+1,w,coin);

    int ans = include+exclude;
    return ans;

}

//recursive approach 2. top down approach.
//here n starts from coin.size()
int subsetSum2(int n,int w,vector<int>coin)
{
    if(w==0)return 1;
    if(n==0)return 0;
    if(coin[n-1]>w) return subsetSum2(n-1,w,coin);//if the coin is greater then the weight then leave the coin
    int include = subsetSum2(n-1,w-coin[n-1],coin);
    int exclude = subsetSum2(n-1,w,coin);
    int ans = include+exclude;
    return ans;
}


int main()
{
    vector<int>v={5,15,3,17,12};
    int w = 20;
    cout<<"Approach 1==> Total way to make w: "<<subsetSum(0,w,v)<<endl<<endl;
    cout<<"Approach 2==> Total way to make w: "<<subsetSum2(v.size(),w,v)<<endl;
    return 0;
}

