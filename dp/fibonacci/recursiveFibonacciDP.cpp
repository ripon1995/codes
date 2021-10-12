#include<bits/stdc++.h>
using namespace std;
#define s 100
int mem[s];

int fib(int i)
{
    if(mem[i]!=-1)return mem[i];
    if(i==0)return  mem[0]=0;
    if(i==1)return mem[1]=1;
    return mem[i]= fib(i-1)+fib(i-2);
}

int main()
{
    memset(mem,-1,sizeof(mem));
    cout<<fib(46)<<endl;
    return 0;
}


