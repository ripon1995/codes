#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void coinChangeGreedy(vector<int> coins , int target) {
    vi res;
    int i = coins.size()-1;
    while(target>0) {
        int presentCoinValue = coins[i];
        if(target >= presentCoinValue) {
            int coinNeeded = target/presentCoinValue;
            for(int i=0;i<coinNeeded;i++) {
                res.push_back(presentCoinValue);
            }
            target %= presentCoinValue;
        }
        i--;
    }

    for(auto r:res) {
        cout<<r<<" ";
    }
}

int main() {
    vi coins = {1,2,5,10,20,50,100,200};
    int target = 220;
    coinChangeGreedy(coins,target);
}