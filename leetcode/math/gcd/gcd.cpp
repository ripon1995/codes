#include<bits/stdc++.h>
using namespace std;

int getGCDRecursive(int a,int b) {
    if(b==0) {
        return a;
    }
    return getGCDRecursive(b,a%b);
}

int getGCDIterative(int a,int b) {
    while(b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int lcm(int a,int b) {
    int gcd = getGCDRecursive(a,b);
    return (a/gcd)*b;
}

int main() {
    cout << getGCDRecursive(701,358) << endl; 
    cout << lcm(12,15) << endl;
}