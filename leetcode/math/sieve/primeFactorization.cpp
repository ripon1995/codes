#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n,vector<int>primes) {
    vector<int>pf;
    for(auto p:primes) {
        if(p*p > n) {
            break;
        }
        while(n%p == 0) {
            pf.push_back(p);
            n /= p;
        }
    }

    if(n>1) {
        pf.push_back(n);
    }
    return pf;
}

vector<int> sieve(int n) {
    vector<int>primes;
    vector<bool>isPrime(n+1,true);

    for(int i=4;i<=n;i+=2) {
        isPrime[i] = false;
    }

    primes.push_back(2);
    for(int i=3;i*i<=n;i+=2) {
        if(isPrime[i] == true) {
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for(auto p:primes) {
        cout << p << " ";
    }
    cout << endl;
    return primes;
}

int main() {
    vector<int>primes = sieve(252);
    for(auto p:primes) cout << p <<" ";
    cout << endl;
    vector<int>pf = primeFactors(252,primes);
    for(auto p:pf) cout << p << " ";
    return 0;
}