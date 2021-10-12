#include<bits/stdc++.h>
#include<cstring>
using namespace std;

#define SZ 20


int lcs(int i, int j,string s,string t)
{
    if(i==s.size() || j==t.size())return 0;
    if(s[i]==t[j])return 1+lcs(i+1,j+1,s,t);
    if(s[i]!=t[j])return max(lcs(i+1,j,s,t),lcs(i,j+1,s,t));
}

int main()
{
    string s="HELLOM";
    string t="HERLL";
    cout<<"Length of longest common  subsequence: "<<lcs(0,0,s,t)<<endl;
    return 0;
}


