#include<bits/stdc++.h>
using namespace std;

void subArraySum2() {
    int n,s;
    cin >> n >> s ;
    vector<int>data(n);
    for(int i=0;i<n;i++) {
        cin >> data[i];
    }

    long long prefixSum = 0;
    map<long long int , int>mp;
    mp[0] = 1;
    long long int ans = 0;

    for(int i=0;i<data.size();i++) {
        prefixSum += data[i];
        ans+=mp[prefixSum - s];
        mp[prefixSum]++;
    }
    cout<<ans<<endl;
}

int main() {
    subArraySum2();
    return 0;
}

/*
5 7
2 -1 3 5 -2

*/