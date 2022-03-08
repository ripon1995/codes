#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using mii= map<int,int>;

int main() {

    int n,x;
    cin>>n>>x;
    vi data(n);
    for(int i=0;i<n;i++) {
        cin>>data[i];
    }
    
    mii mp;
    for(int i=0;i<data.size();i++) {
        bool isPresent = mp.count(x-data[i]);
        if(isPresent) {
            cout << i + 1 << " " << mp[x - data[i]] << "\n";
            return 0;
        }
        mp[data[i]] = i+1;
    }

    cout << "IMPOSSIBLE" << "\n" ;

    return 0;
}