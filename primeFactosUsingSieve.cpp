#include<bits/stdc++.h>
#include<cmath>
using namespace std;


#define MAXNUM 1000001

int spf[MAXNUM];

void sieve()
{
    spf[1]=1;
    for(int i=2;i<MAXNUM;i++) spf[i]=i;

    for(int i=4;i<MAXNUM;i+=2)
    {
        spf[i]= 2;
    }
    for(int i=3;i*i<MAXNUM;i+=2)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<MAXNUM;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}

vector<int> getPrimeFactors(int n)
{
    vector<int>primeFactors;
    while(n!=1)
    {
        primeFactors.push_back(spf[n]);
        n/=spf[n];
    }
    return primeFactors;
}

int main()
{
    sieve();
    int n;
    scanf("%d", &n);
    vector<int>primeFactors=getPrimeFactors(n);
    cout<<"Prime factors are: ";
    for(int i=0;i<primeFactors.size();i++)
    {
        cout<<primeFactors[i]<<" ";
    }
    cout<<endl;
    return 0;
}

