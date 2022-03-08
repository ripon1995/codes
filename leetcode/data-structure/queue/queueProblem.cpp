#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>>vvi;
typedef vector<char>vc;


void findTheWinnerOfTheCircularGame(int n,int k) {
    queue<int>nums;
    for(int i=1;i<=n;i++) {
        nums.push(i);
    }

    int count = k;
    while(nums.size()>1) {
        count--;
        int p = nums.front();
        if(count == 0) {
            nums.pop();
            count = k;
        }
        else {
            nums.pop();
            nums.push(p);
        }
    }
    cout<<nums.front()<<endl;
}

int main() {
    findTheWinnerOfTheCircularGame(6,5);
    return 0;
}