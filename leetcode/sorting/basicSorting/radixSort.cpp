#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> & nums,int n,int exp)
{
    vector<int>output(n);
    vector<int>count(10,0);

    for(int i=0;i<n;i++) count[(nums[i]/exp)%10]++;

    for(int i=1;i<10;i++) count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[count[(nums[i]/exp)%10]-1]=nums[i];
        count[(nums[i]/exp)%10]--;
    }
    for(int i=0;i<output.size();i++)nums[i]=output[i];
    
}

void radixSort(vector<int>& nums)
{
    int maxElement = *max_element(nums.begin(),nums.end());
    for(int exp=1;maxElement/exp>0;exp*=10)
    {
        countSort(nums,nums.size(),exp);
    }

    int maxDif=0;
    for(int i=1;i<nums.size();i++)
    {
        maxDif=max(abs(nums[i]-nums[i-1]),maxDif);
    }
    cout<<maxDif<<endl;
}

int main()
{
    vector<int>nums={10};
    radixSort(nums);
    for(auto n:nums)cout<<n<<" ";

    return 0;
}