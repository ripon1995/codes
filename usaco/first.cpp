#include<bits/stdc++.h>
using namespace std;

bool cmp (pair<int,int>p,pair<int,int>q) {
    if(p.first == q.first) return p.second < q.second ;
    return p.first < q.first ;
}

int main() {

    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> nums;
    int p;
    for(int i=0;i<n;i++) {
        cin >> p ;
        nums.push_back({p,i+1});
    }
    sort(nums.begin(),nums.end(),cmp);
    
    bool isFound=false;

    for(int i=0;i<n;i++) {
        int target = m - nums.at(i).first ;

        int leftPointer = 0; int rightPointer = n-1;

        while(leftPointer < rightPointer) {
            if(leftPointer == i ) {
                leftPointer++ ;
                continue ;
            }
            if(rightPointer == i ) {
                rightPointer-- ;
                continue ;
            }
            if(nums.at(leftPointer).first+nums.at(rightPointer).first == target) {
                cout<< nums.at(i).second << " " <<nums.at(leftPointer).second << " " << nums.at(rightPointer).second << endl;
                isFound=true;
                break;
            }
            if(nums.at(leftPointer).first + nums.at(rightPointer).first < target) {
                leftPointer++;
            }
            if(nums.at(leftPointer).first + nums.at(rightPointer).first > target) {
                rightPointer--;
            }
        }
        if(isFound==true) {
            break ;
        }
    }

    if(isFound == false) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;

}

/*

7 5
1 2 1 2 2 1 1

*/