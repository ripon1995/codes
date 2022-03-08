#include<bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    multiset<int>ticketPrice;
    int p;
    for(int i=1;i<=n;i++) {
        cin >> p ;
        ticketPrice.insert(p);
    }

    for(int i=1;i<=m;i++) {
        cin >> p ;

        auto it = ticketPrice.upper_bound(p);
        if(it ==  ticketPrice.begin()) {
            cout<< "-1" <<endl;
        }
        else {
            cout << *(--it) << endl;
            ticketPrice.erase(it);
        }
    }

    return 0;

}

/*

5 3
5 3 7 8 5
4 8 3

*/