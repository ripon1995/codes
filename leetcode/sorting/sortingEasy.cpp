#include<bits/stdc++.h>
using namespace std;


void checknAndItsDoubleExist(vector<int>data)
{
    bool ans=false;
    sort(data.begin(),data.end());
    for(auto d:data)
    {
        int val=2*d;
        int lb=lower_bound(data.begin(),data.end(),val)-data.begin();
        int ub=upper_bound(data.begin(),data.end(),val)-data.begin();
        cout<<lb<<" "<<ub<<endl;
        
        if(ub-lb>=2 && d==0)
        {
            ans=true;
        }

        if(lb!=ub && d!=0)
        {
            ans=true;
            break;
        }
    }

    cout<<ans<<endl;
}

bool sortingTheSentenceComparator(pair<int,string>p1,pair<int,string>p2)
{
    return p1.first<p2.first;
}

void sortingTheSentence(string s)
{
    vector<pair<int,string>>data;
    string temp="";
    for(auto ch : s )
    {
        if(isdigit(ch))
        {
            data.push_back(make_pair(ch-'0',temp));
            temp="";
        }
        else if(isalpha(ch)) temp+=ch;
    }

    sort(data.begin(),data.end(),sortingTheSentenceComparator);
    
    string res="";
    for(auto d:data)
    {
        res+=d.second;
        res+=' ';
    }
    res.pop_back();
    cout<<res<<endl;
}

void findTargetElementsAfterSortingArrayElements(vector<int>nums,int target)
{
    sort(nums.begin(),nums.end());
    int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

    cout<<lb<<" "<<ub<<endl;

    vector<int>res;
    for(int i=lb;i<ub;i++)res.push_back(i);

    for(auto r:res)cout<<r<<" ";
}

// 1 4 7 9
// 1 4==>3
// 1 7==>6
// 1 9==>8
// 4 7==>3
// 4 9==>5
// 7 9==>2


int main()
{
    vector<int>v={1,2,5,2,3};
    int target=6;
    findTargetElementsAfterSortingArrayElements(v,target);
    return 0;
}