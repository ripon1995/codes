#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void primeFactors(int n)
{
    printf("Prime factors are: ");
    while(n%2==0)
    {
        printf("2 ");
        n/=2;
    }

    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i == 0)
        {
            printf("%d ", i);
            n/=i;
        }
    }
    if(n>2)
    {
        printf("%d",n);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    primeFactors(n);
    return 0;
}

