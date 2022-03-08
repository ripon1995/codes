#include<bits/stdc++.h>
using namespace std;

void subStringOfSizeThreeWithDistinctCharacters(string s)
{
    for(int i=0;i<s.length()-2;i++)
    {
        set<char>data;
        for(int j=i;j<i+3;j++)
        {
            data.insert(s[j]);
        }
    }
}

void containsDuplicate2(vector<int>nums,int k)
{
    set<int>data;
    int fastWindow=0,slowWindow=0;
    bool duplicateFound=false;
    for(fastWindow=0;fastWindow<nums.size();fastWindow++)
    {
        if(data.find(nums[fastWindow])!=data.end())
        {
            duplicateFound=true;
            break;
        }
        data.insert(nums[fastWindow]);
        if(data.size()>k)
        {
            data.erase(nums[fastWindow-k]);
        }

        cout<<"Size: "<<data.size()<<endl;
    }
    cout<<duplicateFound<<endl;
}
void  numberofSubArraysofSizeKandAverageGreaterThanorEqualtoThreshold(vector<int>arr,int k,int threshold)
{
    int fastWindow=0;
    int slowWindow=0;
    int windowSum=0;
    int ans=0;
    for(fastWindow=0;fastWindow<k;fastWindow++)windowSum+=arr[fastWindow];
    cout<<windowSum<<endl;
    if(windowSum/k >=threshold)ans++;
    for(fastWindow=k;fastWindow<arr.size();fastWindow++)
    {
        windowSum+=(arr[fastWindow]-arr[fastWindow-k]);
        if(windowSum/k >=threshold)ans++;    
    }
    cout<<ans<<endl;
}

void kRadiusSubArrayAverage(vector<int>nums,int k)
{
    vector<int>res(nums.size(),-1);
    int fastWindow=0;
    int slowWindow=0;
    long long int windowSum=0;
    int windowSize=((2*k)+1);
    int windowMark=k;
    for(fastWindow=0;fastWindow<windowSize;fastWindow++)windowSum+=nums[fastWindow];
    res[windowMark++]=windowSum/windowSize;

    for(fastWindow=windowSize;fastWindow<nums.size();fastWindow++)
    {
        windowSum+=(nums[fastWindow]-nums[fastWindow-windowSize]);
        res[windowMark++]=windowSum/windowSize;
    }

    for(auto r:res)cout<<r<<" ";
}

void minimumSizeSubArraySum(int target,vector<int>nums)
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
        }
        if(windowSum==target)
        {
            //cout<<"Target: "<<target<<" targetWindowLength: "<<windowLength<<endl;
            ans=min(ans,windowLength);
            slowWindow=fastWindow;
            windowLength=1;
            windowSum=nums[fastWindow];
        }
    }
    if(ans==INT_MAX)ans=0;
    cout<<ans<<endl;
}

void longestOnes(vector<int>nums,int k)
{
    // 1 1 1 0 0 0 1 1 1 1 0
    int fastWindow=0;
    int slowWindow=0;

    while(fastWindow<nums.size())
    {
        cout<<fastWindow<<" "<<slowWindow<<endl;
        if(nums[fastWindow]==0)
        {
            k--;
        }
        if(k<0)
        {
            if(nums[slowWindow]==0)k++;
            slowWindow++;
        }
        fastWindow++;
    }
    cout<<fastWindow-slowWindow<<endl;
}

// 0 1 2 3 4 5 6 7 8
// a a a b b b c c c

void numberOfSubstringsContainingAllThreeCharacters(string s)
{
    int fastWindow=0,slowWindow=0;
    map<char,int>mp;
    int windowCount=1;
    int res=0;
    for(fastWindow=0;fastWindow<s.length();fastWindow++)
    {
        char ch=s[fastWindow];
        mp[ch]++;

        while(slowWindow<s.length() && mp['a']>0 && mp['b']>0 && mp['c']>0) {
            mp[s[slowWindow]]--;
            slowWindow++;
        }
        res+=slowWindow;
    }
    cout<<res<<endl;
}

void longestSubarrayOf1AfterDeletingOneElement(vector<int>nums)
{
    int zero=1;
    int fast=0;
    int slow=0;
    int res=INT_MIN;
    for(fast=0;fast<nums.size();fast++) {
        if(nums[fast]==0)zero--;
        while(zero<0) {
            res=max(res,(fast-slow-1));
            if(nums[slow]==0)zero++;
            slow++;
        }
    }
    cout<<res<<endl;
}


void countNumberOfNiceSubarrays(vector<int>nums,int k) {
    int fast=0;
    int slow=0;
    int ans=0;
    vector<int>windowHook;
    for(fast=0;fast<nums.size();fast++)  {
        if(nums[fast]%2==1) {
            k--;
            windowHook.push_back(fast);
        }

        //update hook
        //shrink window
        if(k<0) {
            slow=windowHook[0]+1;
            windowHook.erase(windowHook.begin()+0);
            k++;
        }

        if(k==0) {
            ans+=windowHook[0]-slow+1;
            //cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
}

void maximumNumberOfVowelsInaSubstringOfGivenLength(string s,int k) {
    set<char>vowelsDictonary={'a','e','i','o','u'};
    
    int fast=0;
    int slow=0;

    int vowelCount=0;
    for(fast=0;fast<k;fast++) {
        bool isFound = vowelsDictonary.find(s[fast])!=vowelsDictonary.end();
        if(isFound==true) {
            vowelCount++;
        }            
    }

    int ans=vowelCount;
    for(fast=k;fast<s.length();fast++) {
        //check last position is vowel or not
        bool lastChar =vowelsDictonary.find(s[fast-k])!=vowelsDictonary.end();
        if(lastChar==true) {
            vowelCount--;
        }

        //check new position is vowel or not
        bool firstChar=vowelsDictonary.find(s[fast])!=vowelsDictonary.end();
        if(firstChar==true){
            vowelCount++;
        }
        ans=max(ans,vowelCount);
    }
    cout<<ans<<endl;
}

int main()
{
    string s="bbbbbb";
    maximumNumberOfVowelsInaSubstringOfGivenLength(s,3);
    return 0;
}