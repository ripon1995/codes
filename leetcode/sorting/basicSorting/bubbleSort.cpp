#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&nums)
{
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums.size()-i-1;j++)
        {
            if(nums[j]>nums[j+1])swap(nums[j],nums[j+1]);
        }
    }
}
int main()
{
    vector<int>v={5,4,3,2,1};
    bubbleSort(v);
    for(auto d:v)cout<<d<<" ";
    cout<<endl;
    return 0;
}