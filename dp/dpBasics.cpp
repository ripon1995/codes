#include<bits/stdc++.h>
using namespace std;

#define SIZE 21
int fibonacciNumbersMemoization[SIZE];


int fibonacciRecursiveApproach(int n)
{
    if(n==0)return fibonacciNumbersMemoization[0];
    if(n==1)return fibonacciNumbersMemoization[1];
    if(fibonacciNumbersMemoization[n]!=-1)
    {
        return fibonacciNumbersMemoization[n];
    }
    fibonacciNumbersMemoization[n] = fibonacciRecursiveApproach(n-1)+fibonacciRecursiveApproach(n-2);
    return fibonacciNumbersMemoization[n];
}

int fibonacciIterativeApproach(int n)
{
    for(int i=2;i<=n;i++)
    {
        fibonacciNumbersMemoization[i]=fibonacciNumbersMemoization[i-1]+fibonacciNumbersMemoization[i-2];
    }
    return fibonacciNumbersMemoization[n];
}

void init()
{
     memset(fibonacciNumbersMemoization,-1,sizeof(fibonacciNumbersMemoization));
     fibonacciNumbersMemoization[0]=0;
    fibonacciNumbersMemoization[1]=1;
}

int main()
{
    init();
    fibonacciRecursiveApproach(6);
    for(int i=0;i<SIZE;i++)cout<<fibonacciNumbersMemoization[i]<<endl;
    init();
    fibonacciIterativeApproach(6);
     for(int i=0;i<SIZE;i++)cout<<fibonacciNumbersMemoization[i]<<endl;

    return 0;
}

