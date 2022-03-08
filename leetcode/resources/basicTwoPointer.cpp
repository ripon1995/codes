#include<bits/stdc++.h>
using namespace std;

// 1 3 5 7 9 11

void isPairSum(vector<int>numbers,int target)
{
    int firstIndex=-1; int secondIndex=-1;
    bool possible=false;
    int i=0,j=numbers.size()-1;
    while(i<j)
    {
        if(numbers[i]+numbers[j]==target)
        {
            firstIndex=i;
            secondIndex=j;
            possible=true;
            break;
        }
        else if(numbers[i]+numbers[j]>target)j--;
        else i++;
    }
    if(possible)
    {
        cout<<numbers[i]<<" + "<<numbers[j]<<" = "<<target<<endl;
    }
    else cout<<"Not possible"<<endl;
}
//  -4  -1  0  3   10
//  16   1  0  9  100
// 0 1 9 16 100

//   0 1 9 16 100

// -7  -3  2  3  11
// 49  9  4   9  121

//  4 9 49
void squaresOfASortedArray(vector<int>nums)
{
    vector<int>res;
    for(auto n:nums)
    {
        if(res.size()==0)
        {
            res.push_back(n*n);
            continue;
        }

        if(n*n<res[0])
        {
            //insert first
            res.insert(res.begin(),n*n);
        }
        if(n*n>res[res.size()-1])
        {
            //insert last
            res.push_back(n*n);
        }
        
    }

    for(auto r:res)cout<<r<<" ";
    cout<<endl;
}

int main()
{
    vector<int>v={-4,-1,0,3,10};
    squaresOfASortedArray(v);
    return 0;
}