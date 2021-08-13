#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>v,int left,int right,int value)
{
    if(left>right)return -1;
    int mid = (left+right)/2;

    if(v[mid]==value)return mid;
    else if(value<v[mid])right = mid-1;
    else if(value>v[mid])left = mid+1;

    return binarySearch(v,left,right,value);
}

int main()
{
    vector<int>v{1,2,3,4,5,6,7,8,9,10};
    int value = 5;
    int res = binarySearch(v,0,9,value);
    cout<<value<<" found at: "<<res<<" Position"<<endl;
    return 0;
}
