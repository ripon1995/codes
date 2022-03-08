#include<bits/stdc++.h>
using namespace std;

//this is also called fixed length window
void maxSumWithSlidingWindwoWithGivenLength(vector<int>nums,int k)
{
    int windowSum=0;
    for(int i=0;i<k;i++)windowSum+=nums[i];

    int maxSum=windowSum;
    for(int i=k;i<nums.size();i++)
    {
        windowSum+= nums[i]-nums[i-k];
        maxSum=max(maxSum,windowSum);
    }

    cout<<maxSum<<endl;
}

//variable length window
void minimumSizeSubArraySumEqualToTarget(int target,vector<int>nums)
{
    int windowSum=0;
    int windowLength=0;

    int fastWindow=0;
    int slowWindow=0;

    int ans=INT_MAX;
    for(fastWindow=0;fastWindow<nums.size();fastWindow++)
    {
        if(windowSum<target)
        {
            windowSum+=nums[fastWindow];
            windowLength++;
        }
        if(windowSum>target)
        {
            windowSum-=nums[slowWindow++];
            windowLength--;
            //cout<<"Target: "<<target<<" targetWindowLength: "<<windowLength<<endl;
        }
        if(windowSum==target)
        {
            //cout<<"Target: "<<target<<" targetWindowLength: "<<windowLength<<endl;
            ans=min(ans,windowLength);
            slowWindow=fastWindow;
            windowLength=1;
            windowSum=nums[fastWindow];
        }
        //cout<<"SUM: "<<windowSum<<endl;
        //cout<<"Len: "<<windowLength<<endl;

        //windowSum+=(nums[fastWindow]-nums[fastWindow-windowLength]);
    }
    if(ans==INT_MAX)cout<<"Not found any array"<<endl;
    else cout<<"Minimum length: "<<ans<<endl;
}

//variable length window
void minimumSizeSubArraySumGreaterOrEqualToTarget(int target,vector<int>nums)
{
    int fastWindow=0;
    int slowWindow=0;
    int windowLength=0;
    int ans=INT_MAX;
    int windowSum=0;
    
    while(fastWindow>=slowWindow)
    {
        if(windowSum>=target)
        {
            cout<<"windowSum: "<<windowSum<<" len: "<<windowLength<<endl;
            ans=min(ans,windowLength);
            windowSum-=nums[slowWindow++];
            windowLength--;
        }
        if(windowSum<target)
        {
            if(fastWindow>=nums.size())break;
            windowSum+=nums[fastWindow++];
            windowLength++;
        }
    }
    if(ans==INT_MAX)cout<<"No ans"<<endl;
    else cout<<"Minimum len: "<<ans<<endl;
}

int main()
{
    vector<int>nums={1,1,1,1,1,1,1,1,1};
    int k=11;
    minimumSizeSubArraySumGreaterOrEqualToTarget(k,nums);
    return 0;
}