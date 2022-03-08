#include<bits/stdc++.h>
using namespace std;

void seive(int n,vector<bool>& isPrime) {
    for(int i=4;i<=n;i+=2) {
        isPrime[i] = false;
    }
    for(int i=3;i*i<=n;i+=2) {
        if(isPrime[i] == true) {
            for(int j=i*i;j<=n;j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<bool>isPrime(n+1,true);
    isPrime[0] = isPrime[1] = false;
    seive(n,isPrime);

    for(int i=1;i<=n;i++) {
        cout << i <<" ";
        (isPrime[i] ? cout<<"Prime"<<endl : cout << "Not Prime" << endl);
    }

    return 0;
}