
// problem : given a array of nums = {1,2,9,2,6}
// |a1 − x|^c + |a2 - x|^c + ...... + |an - x|^c ==?

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


// |a1-x|+|a2-x|+|a3-x|+.......+|an-x|
//here c = 1
void minimumTotalSumForPowerOne(vi nums) {
    int res = 0;
    sort(nums.begin(),nums.end());
    int midIndex = nums.size()/2;
    int midValue = nums[midIndex];

    for(int i=0;i<nums.size();i++) {
        res += abs(nums[i] - midValue);
    }
    cout << res << endl;
}

// |a1 − x|^c + |a2 - x|^c + ...... + |an - x|^c
// here c = 2

void minimumTotalSumForPowerTwo(vi nums) {
    int sum = 0;
    for(auto n:nums) {
        sum += n;
    }
    int avg = sum/nums.size();
    int res = 0;
    for(auto n:nums) {
        res += ((n-avg) * (n-avg));
    }
    cout << res << endl;
}
int main() {

    vi nums = {1,2,9,2,6};
    minimumTotalSumForPowerTwo(nums);
    return 0;
}