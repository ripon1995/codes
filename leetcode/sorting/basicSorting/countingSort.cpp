#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>&nums)
{
    int minElement=*min_element(nums.begin(),nums.end());
    int maxElement=*max_element(nums.begin(),nums.end());
    int range=maxElement-minElement+1;
    vector<int>count(range),output(nums.size());

    // minElement=1; maxElement=5;
    //count=[0,0,0,0,0] output=[0,0,0,0,0]

    //count the element
    // nums=[5 3 2 1 5]
    // countTable
    // 0 0 0 0 0
    // 1 1 1 0 2
    for(int i=0;i<nums.size();i++) count[nums[i]-minElement]++;

    // prefixSUm
    //count=[1 1 1 0 2]
    //count=[1 2 3 3 5]
    for(int i=1;i<count.size();i++)count[i]+=count[i-1];

    //nums=  [5 3 2 1 5]
    //count= [0 1 2 2 4]
    //output=[0 0 0 0 0]
    //output=[1 2 3 5 5]
    for(int i=nums.size()-1;i>=0;i--)
    {
        output[count[nums[i]-minElement]-1]=nums[i];
        count[nums[i]-minElement]--;
    }

    for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
    cout<<endl<<endl;
    int maxGap=0;
    for(int i=1;i<output.size();i++)
    {
        maxGap=max(maxGap,abs(output[i]-output[i-1]));
    }
    cout<<maxGap<<endl;
}

int main()
{
    vector<int>v={10,1 };
    countingSort(v);

    return 0;
}
