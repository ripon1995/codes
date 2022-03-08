#include<bits/stdc++.h>
using namespace std;

void splitAStringInBalancedStrings(string s)
{
    int ans=0;
    int counter=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='R')counter--;
        if(s[i]=='L')counter++;
        if(counter==0)ans++;
    }
    cout<<ans<<endl;
}

void maximumNestingDepthOfTheParentheses(string s)
{
    int lp=0;
    int rp=0;
    int res=INT_MIN;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')lp++;
        else if(s[i]==')')rp++;
        else if(isdigit(s[i]))
        {
            res=max(res,(lp-rp));
        }
    }
    cout<<res<<endl;
}

void replaceAllDigitsWithCharacters(string s)
{
    for(int i=1;i<s.length();i+=2)
    {
        int ch=s[i-1];
        int nextCh=s[i]-'0';
        int newCh=ch+nextCh;
        s[i]=(char)newCh;
    }
    cout<<s<<endl;
}

void checkIfTheSentenceIsPangram(string s)
{
    set<char>data;
    for(auto ch:s)data.insert(ch);

    for(auto d:data)cout<<d<<" ";
}

void toLowerCase(string s)
{
    for(int i=0;i<s.length();i++)
    {
        cout<<(char)(s[i]+32);
    }
    
}

void ringsAndRods(string rings)
{
    map<char,set<char>>data;
    for(int i=1;i<rings.length();i+=2)
    {
        data[rings[i]].insert(rings[i-1]);
    }

    int res=0;
    for(auto dd:data)
    {
        if(dd.second.size()==3)res++;
    }

    cout<<res<<endl;
}

int main()
{
    ringsAndRods("B0R0G0R9R0B0G0");
    return 0;
}