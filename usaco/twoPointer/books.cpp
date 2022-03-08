#include<bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    vector<int> books(n);
    for(int i=0;i<n;i++) {
        cin >> books[i] ;
    }

    int fast = 0 ;
    int slow = 0 ;

    int totalTime=0;
    int ans=0;

    for(fast=0;fast<n;fast++) {
        totalTime+=books[fast];
        if(totalTime>m) {
            //remove slow pointing time
            totalTime-=books[slow];
            //update slow
            slow++;
        }
        if(totalTime<=m) {
            //cout<<fast<<" "<<slow<<endl;
            ans=max(ans,(fast-slow+1));
        }

    }

    cout<<ans<<endl;

    return 0;

}

/*

4 5
3 1 2 1

*/