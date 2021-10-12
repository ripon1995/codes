// each coin can be taken only one time
#include<bits/stdc++.h>
using namespace std;

#define INF 999999

int coinChange(int i,int w,vector<int>coin)
{
    if(w<0)return INF;
    if(i==coin.size())
    {
        if(w==0)return 0;
        return INF;
    }
    int res1=1+coinChange(i+1,w-coin[i],coin);
    int res2=coinChange(i+1,w,coin);
    int ans = min(res1,res2);
    return ans;
}

int main()
{
    vector<int>coin={2,5,9,13,15};
    int w=22;
    cout<<"Total coin need: "<<coinChange(0,w,coin)<<endl;
    return 0;
}


