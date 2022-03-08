#include<bits/stdc++.h>
using namespace std;

int inversionCount=0;

void mergeItems(vector<int> &nums,int l,int m,int r)
{
    int leftPart=m-l+1;
    int rightPart=r-m;
    vector<int>left(leftPart);
    vector<int>right(rightPart);

    for(int i=0;i<leftPart;i++)left[i]=nums[l+i];
    for(int i=0;i<rightPart;i++)right[i]=nums[m+i+1];

    int i=0;
    int j=0;
    int k=l;

    while(i<leftPart && j<rightPart)
    {
        if(left[i]<=right[j])
        {
            nums[k++]=left[i++];
        }
        else 
        {
            nums[k++]=right[j++];
            inversionCount++;
        }
    }

    while(i<leftPart)
    {
        nums[k++]=left[i++];
    }

    while(j<rightPart)
    {
        nums[k++]=right[j++];
    }

}

void mergeSort(vector<int> &nums,int l,int r)
{
    if(l<r  )
    {
        int m=(l+r)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        mergeItems(nums,l,m,r);
    }
}

int main()
{
    vector<int>v={5,4,3,2,1};
    mergeSort(v,0,v.size()-1);

    for(auto d:v)cout<<d<<" ";
    cout<<endl<<endl;
    cout<<inversionCount<<endl;
    return 0;
}