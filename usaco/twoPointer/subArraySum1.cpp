#include<bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    vector<int> data(n);
    for(int i=0;i<n;i++) {
        cin >> data[i] ;
    }

    int fast = 0 ;
    int slow = 0 ;

    int sum = 0;
    int ans = 0;

    for(fast = 0 ; fast < n ; fast++) {
        sum += data[fast] ;
        
        if(sum > m) {
            //update slow till sum is less or equal m
            while(sum > m) {
                sum -= data[slow] ; 
                slow++;
            }
        }

        if(sum == m) {
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;

}

/*

5 7
2 4 1 2 7

*/