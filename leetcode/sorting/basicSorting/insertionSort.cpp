#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &nums)
{
    for(int i=1;i<nums.size();i++)
    {
        int key=nums[i];
        int j=i-1;
        while(j>=0 && nums[j]>key)
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}
int main()
{
    vector<int>v={5,4,3,2,1,3};
    insertionSort(v);
    
    for(auto num:v)cout<<num<<" ";
    cout<<endl;
    return 0;
}