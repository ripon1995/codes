#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> sieve(ll n) {
    vector<ll>primes;
    int lim = sqrt(n);
    vector<bool>isPrime(lim+1,true);
    for(int i=4;i<=lim;i+=2) {
        isPrime[i] = false;
    }

    primes.push_back(2);
    for(int i=3;i<=lim;i+=2) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<=lim;j+=i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

vector<ll> segmentSieve(ll left,ll right,vector<ll>primes) {
    vector<bool>isPrime(right-left+1,true);
    for(auto p:primes) {
        for(ll j = max(p*p,(left+p-1)/p * p);j<=right;j+=p) {
            isPrime[j-left] = false;
        }
        if(left == 1) {
            isPrime[0] = false;
        }
    }

    vector<ll>res;
    for(ll i=0;i<isPrime.size();i++) {
        if(isPrime[i] == true) {
            res.push_back(left+i);
        }
    }
    return res;
}

int main() {
    ll left = 2147483647;
    ll right = 2147483900;
    vector<ll>primes = sieve(right);
    for(auto p:primes) cout << p <<" ";
    cout << endl;
    vector<ll>range = segmentSieve(left,right,primes);
    for(auto r:range) cout << r << " ";
    cout << endl;
    return 0;
}