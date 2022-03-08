#include<bits/stdc++.h>
using namespace std;

void displayTableOfFoodOrdersInAResturant(vector<vector<string>>orders)
{
    vector<string>foodName;

    map<int,map<string,int>>data;
    for(auto order:orders)
    {
        foodName.push_back(order[2]);
        bool isPresent = data.find(stoi(order[1]))!=data.end();
        if(isPresent==false)
        {
            map<string,int>mp;
            mp[order[2]]=1;
            data[stoi(order[1])]=mp;
        }
        else
        {
            bool itemPresent=data[stoi(order[1])].find(order[2])!=data[stoi(order[1])].end();
            if(itemPresent==false)
            {
                data[stoi(order[1])][order[2]]=1;
            }
            else
            {
                data[stoi(order[1])][order[2]]++;
            }
        }
    }

    sort(foodName.begin(),foodName.end());
    foodName.erase(unique(foodName.begin(),foodName.end()),foodName.end());
    
    // cout<<endl;
    // for(auto d:data)
    // {
    //     cout<<d.first<<" ";
    //     for(auto dd:d.second)cout<<dd.first<<" "<<dd.second<<" ";
    //     cout<<endl;
    // }

    for(auto f:foodName)cout<<f<<endl;

    vector<vector<string>>res;
    vector<string>r;
    r.push_back("Table");
    for(auto f:foodName)r.push_back(f);
    res.push_back(r);

    for(auto d:data)
    {
        r.clear();
        r.push_back(to_string(d.first));
        for(int i=1;i<res[0].size();i++)
        {
            bool isPresent=d.second.find(res[0][i])!=d.second.end();
            if(isPresent==false)r.push_back("0");
            else r.push_back(to_string(d.second[res[0][i]]));
        }
        res.push_back(r);
    }

    for(auto rr:res)
    {
        for(auto r:rr)cout<<r<<" ";
        cout<<endl;
    }
    
}

bool comparator(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first)return p1.second<p2.second;
    return p1.first<p2.first;
}
void sortIntegersByThePowerValue(int lo,int hi,int k)
{
    vector<pair<int,int>>data;
    for(int i=lo;i<=hi;i++)
    {
        int presentNumber=i;
        int steps=0;
        while(presentNumber!=1)
        {
            if(presentNumber%2==0)presentNumber/=2;
            else presentNumber=(3*presentNumber)+1;

            steps++;
        }
        data.push_back(make_pair(steps,i));
    }
    sort(data.begin(),data.end(),comparator);

    cout<<data[k-1].second<<endl;
}

void threeSum(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    for(int i=0;i<nums.size();i++)
    {
        vector<int>r;
        int val=0-nums[i];
        int stIndex=i+1;
        int endIndex=nums.size()-1;
        while(stIndex<endIndex)
        {
            if(nums[stIndex]+nums[endIndex]==val)
            {
                r.push_back(nums[i]);
                r.push_back(nums[stIndex]);
                r.push_back(nums[endIndex]);
                res.push_back(r);
                r.clear();
                stIndex++;
                endIndex--;
            }
            else if(nums[stIndex]+nums[endIndex]<val)stIndex++;
            else if(nums[stIndex]+nums[endIndex]>val)endIndex--;
        }
        if(r.size()>0)res.push_back(r);
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());

    for(auto rr:res)
    {
        for(auto r:rr)cout<<r<<" ";
        cout<<endl;
    }
}

void threeSumClosest(vector<int>nums,int target)
{
    sort(nums.begin(),nums.end());
    int res=INT_MAX;
    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        int startingPoint=i+1;
        int endingPoint=nums.size()-1;
        int val=target-nums[i];
        while(startingPoint<endingPoint)
        {
            
            int r=nums[i]+nums[startingPoint]+nums[endingPoint];
            if(abs(target-r)<ans)
            {
                res=r;
                ans=abs(target-r);   
            }
            if(nums[startingPoint]+nums[endingPoint]==val)
            {
                startingPoint++;
                endingPoint--;
            }
            if(nums[startingPoint]+nums[endingPoint]<val)
            {
                startingPoint++;
            }
            else if(nums[startingPoint]+nums[endingPoint]>val)
            {
                endingPoint--;
            }
        }
    }
    cout<<res<<endl;
}

void groupAnagrams(vector<string>words)
{
    map<string,vector<string>>mp;
    for(auto word:words)
    {
        string unsortedWord=word;
        sort(word.begin(),word.end());
        mp[word].push_back(unsortedWord);

    }

    for(auto m:mp)
    {
        for(auto data:m.second)cout<<data<<" ";
        cout<<endl;
    }
}

bool mergeIntervalsComparator(vector<int>v1,vector<int>v2)
{
    return v1[0]<v2[0];
}
void mergeIntervals(vector<vector<int>>intervals)
{
    sort(intervals.begin(),intervals.end(),mergeIntervalsComparator);
    for(auto inter:intervals)
    {
        for(auto i:inter)cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    vector<vector<int>>res;
    vector<int>r;
    r.push_back(intervals[0][0]);
    r.push_back(intervals[0][1]);
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[i][0]<=r[1])
        {
            r[1]=max(intervals[i][1],r[1]);
        }
        else
        {
            res.push_back(r);
            r.clear();
            r.push_back(intervals[i][0]);
            r.push_back(intervals[i][1]);
        }
    }

    if(r.size()>0)res.push_back(r);

    for(auto rr:res)
    {
        for(auto r:rr)cout<<r<<" ";
        cout<<endl;
    }
}

bool largestNumberComparator(string a,string b)
{
    return a+b>b+a;
}

void largestNumber(vector<int>nums)
{
    vector<string>data;
    for(auto num:nums)
    {
        string n=to_string(num);
        
        data.push_back(n);
    }
    sort(data.begin(),data.end(),largestNumberComparator);
    string res="";
    if(data[0]=="0")
    {
        res+="0";
    }
    else for(auto d:data)res+=d;
    cout<<res<<endl;
}

void kthLargestElementInTheArray(vector<int>nums,int k)
{
    sort(nums.begin(),nums.end());
    cout<<nums[nums.size()-k];
}

// k t
// 3 0
// 1 2 3 1
// 1 1 2 3

// k t
// 1 2
// 0 1 1 1 1
bool containsDuplicate3Comparator(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first<p2.first;
}
void containsDuplicate3(vector<int>nums,int k,int t)
{
    vector<pair<int,int>>data;
    for(int i=0;i<nums.size();i++)data.push_back(make_pair(nums[i],i));
    sort(data.begin(),data.end(),containsDuplicate3Comparator);
    for(int i=1;i<data.size();i++)
    {
        if(abs(data[i].first-data[i-1].first)<=t && (data[i].second-data[i-1].second)<=k)
        {
            cout<<"true"<<endl;
        }
    }

}

// 1 2 3
// 2 3
//

void majorityElements2(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    int sz=nums.size();
    for(int i=0;i<sz;i++)
    {
        if(nums[i]%2==0)
        {
            cout<<"Done"<<endl;
            nums.erase(nums.begin()+i);
        }
        else cout<<nums[i]<<" ";
    }
}


void hIndex(vector<int>citations)
{
    int sz=citations.size();
    sort(citations.begin(),citations.end());
    for(int i=0;i<citations.size();i++)
    {
        if(abs(sz -i)>=citations[i])
        {
            cout<<citations[i]<<endl;
        }
    }
}

void wiggelSort2(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    vector<int>res;
    int k=0;
    int lastIndex=nums.size()-1;
    int midIndex=lastIndex/2;
    while(k<nums.size())
    {
        if(k%2==1)
        {
            res.push_back(nums[lastIndex--]);
            k++;
        }
        else
        {
            res.push_back(nums[midIndex--]);
            k++;
        }
    }

    for(auto r:res)cout<<r<<" ";
}

bool reduceArraySizetoHalfComparator(pair<int,int>p,pair<int,int>q)
{
    return p.second<q.second;
}

void reduceArraySizetoHalf(vector<int>nums)
{
    map<int,int>mp;
    for(auto num:nums)
    {
        bool isPresent = mp.find(num)!=mp.end();
        if(isPresent==false)mp[num]=1;
        else mp[num]++;
    }

    vector<pair<int,int>>data;
    for(auto m:mp)data.push_back(make_pair(m.first,m.second));
    sort(data.begin(),data.end(),reduceArraySizetoHalfComparator);

    for(auto d:data)cout<<d.first<<" "<<d.second<<endl;
    set<int>s;
    int sz=0;
    for(int i=data.size()-1;i>=0;i--)
    {
        sz+=data[i].second;
        cout<<sz<<endl;
        s.insert(data[i].first);
        if(sz>=nums.size()/2)break;
    }

    cout<<s.size()<<endl;
}

void checkIfAStringCanBreakAnotherString(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    bool res=false;
    int count1=0,count2=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]>=s2[i])count1++;
        if(s2[i]>=s1[i])count2++;
    }

    if(count1%s1.size()==0 || count2%s1.size()==0) res=true;

    cout<<res<<endl;
}

void customSortString(string order,string s)
{
    int startIndex=0;
    for(int i=0;i<order.size();i++)
    {
        for(int j=i;j<s.size();j++)
        {
            if(order[i]==s[j])
            {
                swap(s[j],s[startIndex++]);
                cout<<s<<endl;
            }
        }
    }

    cout<<s<<endl;
}

bool sortCharacterByFrequencyComparator(pair<char,int>p1,pair<char,int>p2)
{
    return p1.second>p2.second;
}
void sortCharacterByFrequency(string s)
{
    string temp=s;
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    vector<pair<char,int>>data;
    for(auto t:temp)
    {
        int cnt=count(s.begin(),s.end(),t);
        data.push_back(make_pair(t,cnt));
    }
    sort(data.begin(),data.end(),sortCharacterByFrequencyComparator);
    string res="";
    for(auto d:data)
    {
        for(int i=0;i<d.second;i++)
        {
            res+=d.first;
        }
    }
    cout<<res<<endl;
}

bool kClosestPointsToOriginComparator(pair<int,double>p,pair<int,double>q)
{
    return p.second<q.second;
}

void kClosestPointsToOrigin(vector<vector<int>>points,int k)
{
    vector<pair<int,double>>data;
    for(int i=0;i<points.size();i++)
    {
        double dis=sqrt(((points[i][0]*points[i][0]))+((points[i][1]*points[i][1])));
        data.push_back(make_pair(i,dis));
    }

    sort(data.begin(),data.end(),kClosestPointsToOriginComparator);
    vector<vector<int>>res;
    int counter=0;
    for(auto d:data)
    {
        if(counter==k)break;
        res.push_back({points[d.first][0],points[d.first][1]});
        counter++;
    }
    for(auto r:res)cout<<r[0]<<" "<<r[1]<<endl;
}

void maxIceCream(vector<int>costs,int coins)
{
    sort(costs.begin(),costs.end());
    int res=0;
    int counter=0;
    for(int i=0;i<costs.size();i++)
    {
        if(res+costs[i]<=coins)
        {
            res+=costs[i];
            counter++;
        }
        else break;
    }
    cout<<counter<<endl;
}

bool rearrangeWordsInASentenceComparator(pair<string,pair<int,int>>p,pair<string,pair<int,int>>q)
{
    if(p.second.second==q.second.second)return p.second.first<q.second.first;
    return p.second.second<q.second.second;
}

void rearrangeWordsInASentence(string text)
{
    vector<pair<string,pair<int,int>>>data;
    string word="";
    int len=0;
    int counter=0;
    for(int i=0;i<text.size();i++)
    {
        if(text[i]==' ')
        {
            data.push_back(make_pair(word,make_pair(counter++,len)));
            word="";
            len=0;
        }
        else 
        {
            word+=tolower(text[i]);
            len++;
        }
    }
    data.push_back(make_pair(word,make_pair(counter,len)));
    sort(data.begin(),data.end(),rearrangeWordsInASentenceComparator);
    for(auto d:data)cout<<d.first<<" "<<d.second.second<<endl;
    string res="";
    for(auto d : data)
    {
        res+=d.first;
        res+=" ";
    }

    res.pop_back();
    res[0]=toupper(res[0]);
    cout<<res<<endl;
}

void reductionOperationToMakeTheArrayElementsEqual(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    vector<int>counter;
    int count=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==nums[i-1])
        {
            count++;
            continue;
        }
        else
        {
            counter.push_back(count);
            count=1;
        }
    }
    counter.push_back(count);

    int res=0;
    for(int i=counter.size()-1;i>0;i--)
    {
        res+=i*counter[i];
    }
    cout<<res<<endl;
}

void compareStringByFrequencyOfTheSmallestCharacter(vector<string>queries,vector<string>words)
{
    vector<int>qCount;
    for(auto q:queries)
    {
        sort(q.begin(),q.end());
        char ch=q[0];
        int c=count(q.begin(),q.end(),ch);
        qCount.push_back(c);
    }

    vector<int>wCount;
    for(auto w:words)
    {
        sort(w.begin(),w.end());
        char ch=w[0];
        int c=count(w.begin(),w.end(),ch);
        wCount.push_back(c);
    }

    sort(wCount.begin(),wCount.end());

    for(auto q:qCount)cout<<q<<" ";
    cout<<endl;
    for(auto w:wCount)cout<<w<<" ";
    cout<<endl;

    vector<int>res;
    for(auto q:qCount)
    {
        int ub=upper_bound(wCount.begin(),wCount.end(),q)-wCount.begin();
        res.push_back(wCount.size()-ub);
    }
    for(auto r:res)cout<<r<<" ";
}


void largestSubMatrixWithReArrangement(vector<vector<int>> matrix)
{
    vector<vector<int>>consecutiveOne(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int i=0;i<matrix[0].size();i++)
    {
        consecutiveOne[0][i]=matrix[0][i];
        for(int j=1;j<matrix.size();j++)
        {
            if(matrix[j][i]==1)consecutiveOne[j][i]=consecutiveOne[j-1][i]+1;
        }
    }

    for(int i=0;i<consecutiveOne.size();i++)
    {
        sort(consecutiveOne[i].begin(),consecutiveOne[i].end());
        reverse(consecutiveOne[i].begin(),consecutiveOne[i].end());
    }
    
    int res=INT_MIN;
    for(int i=0;i<consecutiveOne.size();i++)
    {
        for(int j=0;j<consecutiveOne[i].size();j++)
        {
            res=max(res,consecutiveOne[i][j]*(j+1));
        }
    }
    cout<<res<<endl;
}

bool twoCitySchedulingComparator(vector<int>c1,vector<int>c2)
{
    return (c1[0]-c1[1])<(c2[0]-c2[1]);
}

void twoCityScheduling(vector<vector<int>>costs)
{
    sort(costs.begin(),costs.end(),twoCitySchedulingComparator);
    int res=0;
    for(int i=0;i<costs.size();i++)
    {
        if(i<costs.size()/2)
        {
            res+=costs[i][0];
        }
        else
        {
            res+=costs[i][1];
        }
    }
    cout<<res<<endl;

}

#define MOD_NUMBER 1000000007 

void rangeSumOfSortedSubarraySum(vector<int>nums,int n,int left,int right)
{
    vector<int>data;
    for(int i=0;i<nums.size();i++)
    {
        int sum=0;
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            data.push_back(sum);
        }
    }
    sort(data.begin(),data.end());
    int res=0;
    for(int i=left-1;i<right;i++)
    {
        res=(res+data[i])%(MOD_NUMBER);
    }

    cout<<res<<endl;
}

bool leastNumberOfUniqueIntegersAfterKRemovalsComparator(pair<int,int>p,pair<int,int>q)
{
    return p.second<q.second;
}

void leastNumberOfUniqueIntegersAfterKRemovals(vector<int>arr,int k)
{
    unordered_map<int,int>mp;
    for(auto a:arr)mp[a]++;
    vector<pair<int,int>>data;
    for(auto m:mp)data.push_back(m);
    sort(data.begin(),data.end(),leastNumberOfUniqueIntegersAfterKRemovalsComparator);
    int res=data.size();
    for(auto d:data)
    {
        
        if(d.second<=k)
        {
            k-=d.second;
            res--;
        }
        else break;
    }
    cout<<res<<endl;
}

void kthSmallestElementInASortedMatrix(vector<vector<int>>matrix,int k)
{
    int n=matrix.size();
    int lo=matrix[0][0];
    int hi=matrix[n-1][n-1];
    while(lo<hi)
    {
        int count=0;
        int mid=lo+(hi-lo)/2;
        int j=n-1;
        for(int i=0;i<n;i++)
        {
            while(j>=0 && matrix[i][j]>mid) j--;
            count+=j+1;
        }

        if(count<k)lo=mid+1;
        else hi=mid;
    }

    cout<<lo<<endl;
}


bool rankTeamsByVotesComparator(pair<char,vector<int>>p,pair<char,vector<int>>q)
{
    for(int i=0;i<p.second.size();i++)
    {
        if(p.second[i]==q.second[i])continue;
        return p.second[i]<q.second[i];
    }
    return p.second[0]<q.second[0];
}

void rankTeamsByVotes(vector<string>votes)
{
    map<char,vector<int>>mp;
    for(auto vote:votes)
    {
        for(int i=0;i<vote.length();i++)
        {
            mp[vote[i]].push_back(i+1);
        }
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        sort(it->second.begin(),it->second.end());
    }
    vector<pair<char,vector<int>>>data;
    for(auto it=mp.begin();it!=mp.end();it++)data.push_back({it->first,it->second});

    sort(data.begin(),data.end(),rankTeamsByVotesComparator);
    for(auto d:data)
    {
        cout<<d.first<<" ";
        for(auto i:d.second)cout<<i<<" ";
        cout<<endl;
    }
    string res="";
    for(auto d:data)res+=d.first;
    cout<<res<<endl;
}

bool kStrongestValuesInAnArrayComparator(pair<int,int>p,pair<int,int>q)
{
    if(p.first==q.first)return p.second>q.second;
    return p.first>q.first;
}

void kStrongestValuesInAnArray(vector<int>arr,int k)
{
    sort(arr.begin(),arr.end());
    int median= arr[(arr.size()-1)/2];
    vector<pair<int,int>>data;
    for(auto a:arr)data.push_back({abs(a-median),a});
    sort(data.begin(),data.end(),kStrongestValuesInAnArrayComparator);
    vector<int>res;
    int c=0;
    for(auto d:data)
    {
        if(c==k)break;
        c++;
        res.push_back(d.second);
    }
    for(auto r:res)cout<<r<<" ";
}

bool carPoolingComparator(vector<int>p,vector<int>q)
{
    return p[1]<q[1];
}

void carPooling(vector<vector<int>>trips,int capacity)
{
    sort(trips.begin(),trips.end(),carPoolingComparator);
    for(auto t:trips)cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
    bool res=true;

    // endingtTime person
    vector<pair<int,int>>prev;

    int currentCapacity=capacity-trips[0][0];
    prev.push_back({trips[0][2],trips[0][0]});
    for(int i=1;i<trips.size();i++)
    {
        cout<<currentCapacity<<endl;
        if(currentCapacity<0)break;
        for(int j=0;j<i;j++)
        {
            if(prev[j].first==-1 && prev[j].second==-1)continue;
            if(prev[j].first<=trips[i][1])
            {
                currentCapacity+=prev[j].second;
                prev[j].first=-1;
                prev[j].second=-1;
            }
        }
        currentCapacity-=trips[i][0];
        prev.push_back({trips[i][2],trips[i][0]});
    }
    if(currentCapacity<0)res=false;
    cout<<res<<endl;
}

bool filterRestaurantsComparator(vector<int>p,vector<int>q)
{
    if(p[1]==q[1])
    {
        if(p[0]==q[0])
        {
            if(p[3]==q[3])return p[4]<q[4];
            return p[3]<q[3];
        }
        return p[0]>q[0];
    }
    return p[1]>q[1];
}

void filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
{
    sort(restaurants.begin(),restaurants.end(),filterRestaurantsComparator);
    vector<int>id;
    for(auto res:restaurants)
    {
        if(veganFriendly==1 && res[2]!=1)continue;
        if(res[3]>maxPrice)continue;
        if(res[4]>maxDistance)continue;
        cout<<res[0]<<endl;
    }

}

bool removeCoveredIntervalsComparator(vector<int>p,vector<int>q)
{
    if(p[0]==q[0])return p[1]>q[1];
    return p[0]<q[0];
}

void removeCoveredIntervals(vector<vector<int>>intervals)
{
    sort(intervals.begin(),intervals.end(),removeCoveredIntervalsComparator);
    for(auto i:intervals)cout<<i[0]<<" "<<i[1]<<endl;
    int coveredItem=0;
    for(int i=1;i<intervals.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(intervals[i][1]<=intervals[j][1])
            {
                coveredItem++;
                cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                break;
            }
        }
    }

    cout<<endl<<intervals.size()-coveredItem<<endl;
}

void maximumElementAfterDecreasingAndRearranging(vector<int>arr)
{
    sort(arr.begin(),arr.end());
    if(arr[0]!=1)arr[0]=1;
    for(int i=1;i<arr.size();i++)
    {
        if((arr[i]-arr[i-1])<=1)continue;
        arr[i]=arr[i-1]+1;
    }

    for(auto a:arr)cout<<a<<" ";
    cout<<endl;
}

void minimumMovesToEqualArrayElements2(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    int mid=nums[nums.size()/2];
    int steps=0;
    for(auto n:nums)
    {
        steps+=abs(n-mid);
    }
    cout<<steps<<endl;
}


void divideArrayInSetsOfKConsecutiveNumbers(vector<int>nums,int k)
{
    bool res=true;
    sort(nums.begin(),nums.end());
    int temp=nums[0];
    nums.erase(nums.begin()+0);
    int counter=1;
    while(nums.size()>0)
    {
        if(counter==k)
        {
            if(nums.size()<k)break;
            temp=nums[0];
            nums.erase(nums.begin()+0);
            counter=1;
        }
        int lb=lower_bound(nums.begin(),nums.end(),temp+1)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),temp+1)-nums.begin();
        if(lb==ub)break;
        nums.erase(nums.begin()+lb);
        temp++;
        counter++;
    }

    if(nums.size()!=0)res=false;
    cout<<res<<endl;
}

void minimumDifferenceBetweenLargestAndSmallestInThreeMoves(vector<int>nums)
{
    sort(nums.begin(),nums.end());
    int res=INT_MAX;
    for(int i=1;i<=3;i++)
    {
        res=min(res,nums[nums.size()-4+i]-nums[i]);
    }
    cout<<res<<endl;
}

bool minimumDeletionsToMakeCharacterFrequenciesUniqueComparator(int a,int b)
{
    return a>b;
}

void minimumDeletionsToMakeCharacterFrequenciesUnique(string s)
{

    map<char,int>mp;

    for(auto ch:s)mp[ch]++;
    vector<int>data;
    for(auto m:mp)data.push_back(m.second);
    sort(data.begin(),data.end(),minimumDeletionsToMakeCharacterFrequenciesUniqueComparator);
    int res=0;
    for(int i=0;i<data.size()-1;i++)
    {
        if(data[i]==0)continue;
        for(int j=i+1;j<data.size();j++)
        {
            if(data[j]==0)continue;
            if(data[i]==data[j])
            {
                data[j]--;
                res++;
            }
        }
    }
    for(auto d:data)cout<<d<<endl;

    cout<<res<<endl;
}

bool maximumLengthOfPairChainComparator(vector<int>p,vector<int>q)
{
    if(p[1]==q[1])return p[0]<q[0];
    return p[1]<q[1];
}

void maximumLengthOfPairChain(vector<vector<int>>pairs)
{
    sort(pairs.begin(),pairs.end(),maximumLengthOfPairChainComparator);

    for(auto p:pairs)cout<<p[0]<<" "<<p[1]<<endl;

    int maxLen=INT_MIN;
    for(int i=0;i<pairs.size();i++)
    {
        int currentLen=1;
        int currentEnding=pairs[i][1];
        for(int j=i+1;j<pairs.size();j++)
        {
            if(currentEnding>=pairs[j][0])continue;
            currentEnding=pairs[j][1];
            currentLen++;
        }
        maxLen=max(currentLen,maxLen);
    }
    cout<<maxLen<<endl;
}

void determineIfTwoStringsAreClose(string word1,string word2)
{
    map<char,int>w1;
    map<char,int>w2;

    for(auto w:word1)w1[w]++;
    for(auto w:word2)w2[w]++;

    vector<int>data1;
    vector<char>dataChar1;
    for(auto w:w1)
    {
        dataChar1.push_back(w.first);
        data1.push_back(w.second);
    }
    
    vector<int>data2;
    vector<char>dataChar2;
    for(auto w:w2)
    {
        dataChar2.push_back(w.first);
        data2.push_back(w.second);
    }

    sort(data1.begin(),data1.end());
    sort(data2.begin(),data2.end());

    bool res=true;
    if(data1.size()!=data2.size() || dataChar1.size()!=dataChar2.size())res=false;
    else
    {
        for(int i=0;i<data1.size();i++)
        {
            if(data1[i]==data2[i] && dataChar1[i]==dataChar2[i])continue;
            res=false;
            break;
        }
    }
    
    cout<<res<<endl;

}

bool topKFrequentWordComparator(pair<string,int>p,pair<string,int>q)
{
    if(p.second==q.second)return p.first<q.first;
    return p.second>q.second;
}

void topKFrequentWord(vector<string>words,int k)
{
    map<string,int>mp;
    for(auto w:words)mp[w]++;
    vector<pair<string,int>>data;
    for(auto m:mp)data.push_back({m.first,m.second});
    sort(data.begin(),data.end(),topKFrequentWordComparator);
    vector<string>res;
    for(int i=0;i<k;i++)res.push_back(data[i].first);
    for(auto d:data)cout<<d.first<<" "<<d.second<<endl;
}

void maxNumberOfKSumPairs(vector<int>nums,int k)
{
    sort(nums.begin(),nums.end());
    int i=0;
    int j=nums.size()-1;
    int counter=0;
    while(i<j)
    {
        if((nums[i]+nums[j])==k)
        {
            counter++;
            i++;
            j--;
        }
        else if((nums[i]+nums[j])<k)i++;
        else j--;
    }

    cout<<counter<<endl;
}

bool minimumAreaRectangleComparator(vector<int>p,vector<int>q)
{
    if(p[0]==q[0])return p[1]<q[1];
    return p[0]<q[0];
}

bool minimumAreaRectangleComparator2(vector<int>p,vector<int>q)
{
    if(p[1]==q[1])return p[0]<q[0];
    return p[1]<q[1];
}

void minimumAreaRectangle(vector<vector<int>>points)
{
    sort(points.begin(),points.end(),minimumAreaRectangleComparator);
    
    vector<pair<int,int>>widPoint;
    for(int i=1;i<points.size();i++)
    {
        if(points[i-1][0]==points[i][0])
        {
            widPoint.push_back({points[i-1][0],points[i-1][1]});
            widPoint.push_back({points[i][0],points[i][1]});
            
        }
    }
    sort(points.begin(),points.end(),minimumAreaRectangleComparator2);
    vector<pair<int,int>>lenPoint;
    for(int i=1;i<points.size();i++)
    {
        if(points[i-1][1]==points[i][1])
        {
            lenPoint.push_back({points[i-1][0],points[i-1][1]});
            lenPoint.push_back({points[i][0],points[i][1]});
        }
    }
    cout<<"WidPoints"<<endl;
    widPoint.erase(unique(widPoint.begin(),widPoint.end()),widPoint.end());
    for(auto w:widPoint)cout<<w.first<<" "<<w.second<<endl;
    cout<<"LenPoints"<<endl;
    lenPoint.erase(unique(lenPoint.begin(),lenPoint.end()),lenPoint.end());
    for(auto w:lenPoint)cout<<w.first<<" "<<w.second<<endl;
    cout<<endl<<endl;
    vector<pair<int,int>>data;
    for(auto p:widPoint)
    {
        int present = find(lenPoint.begin(),lenPoint.end(),p)!=lenPoint.end();
        if(present)data.push_back(p);
    }
    
    for(auto d:data)
    {
        cout<<d.first<<" "<<d.second<<endl;
    }

    int minWid=INT_MAX;
    int minLen=INT_MAX;
    for(int i=1;i<data.size();i+=2)
    {
        if(data[i-1].first==data[i].first)minWid=min(minWid,abs(data[i-1].second-data[i].second));
    }
    for(int i=2;i<data.size();i+=2)
    {
        //if(data[i-1].first==data[i].first)minWid=min(minWid,abs(data[i-1].second-data[i].second));
        if(data[i-2].second==data[i].second)minLen=min(minLen,abs(data[i-2].first-data[i].first));
    }

    cout<<minWid*minLen<<endl;
}

int main()
{
    return 0;
}
