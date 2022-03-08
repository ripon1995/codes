#include<bits/stdc++.h>
using namespace std;

typedef vector<int>vi;

void nextGreaterElement(vi nums) {
    // stores the index
    stack<int>mono_dec_stack;

    vector<int>data(nums.size(),-1);
    for(int i=0;i<nums.size();i++) {
        int currentElement = nums[i];
        if(mono_dec_stack.empty()==false && currentElement >= nums[mono_dec_stack.top()]) {
            while(mono_dec_stack.empty()==false && currentElement >= nums[mono_dec_stack.top()]) {
                //data.push_back(nums[i]);
                data[mono_dec_stack.top()] = nums[i];
                mono_dec_stack.pop();
            }
        }
        mono_dec_stack.push(i);
    }
    while(mono_dec_stack.empty() == false) {
        data[mono_dec_stack.top()] = 0;
        mono_dec_stack.pop();
    }

    for(auto d:data) {
        cout<<d<<" ";
    }

}

int main() {
    vi d = {73,74,75,71,69,72,76,73};
    nextGreaterElement(d);
    return 0;
}