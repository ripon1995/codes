#include<bits/stdc++.h>
using namespace std;


int combination(int n,int r)
{
    if(r>n)return 0;
    if(r==0 || r==n)return 1;
    int include = combination(n-1,r-1);
    int exclude = combination(n-1,r);
    int ans = include+exclude;
    return ans;
}


int main()
{
    cout<<combination(5,3);
    return 0;
}

