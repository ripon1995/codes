// calculate a^n

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll binpow(ll a,ll n) {
    if(n == 0) {
        return 1;
    }
    if(n%2 == 0) {
        return binpow(a,n/2) * binpow(a,n/2);
    }
    else {
        return a * binpow(a,n/2) * binpow(a,n/2);
    }
}

ll binpowIterative(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while(b > 0) {
        if(b&1) {
            res = res * a % m;
        }
        a = a * a % m;
        b = b >> 1;
    }
    return res;
}

int main() {
    int a,b;
    cin >> a >> b;
    cout << binpow(a,b) << endl;
    //cout << binpowIterative(2,2147483647,13) << endl;
    main();
    return 0;
}