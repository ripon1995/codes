#include<bits/stdc++.h>
using namespace std;

#define SZ 7

int mem[SZ][SZ];

int lcs(int i, int j,string s,string t)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        for(int j=t.size()-1;j>=0;j--)
        {
            if(s[i]==t[j]) mem[i][j]= 1+mem[i+1][j+1];

            if(s[i]!=t[j]) mem[i][j]= max(mem[i+1][j],mem[i][j+1]);
        }
    }
    return mem[0][0];
}

void init(string s,string t)
{
    for(int i=0;i<SZ;i++)for(int j=0;j<SZ;j++)mem[i][j]=-1;
    int n = s.size();
    int m = t.size();
    for (int i = 0;i < n;i++) mem[i][m] = 0;
    for (int j = 0;j < m;j++) mem[n][j] = 0;

}

void printMemData()
{
        for(int i=0;i<SZ;i++)
    {
        for(int j=0;j<SZ;j++)cout<<mem[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{

    string s="HELLOM";
    string t="HRL";
    init(s,t);
    //printData();
    cout<<"Longest common subsequence: "<<lcs(0,0,s,t)<<endl;
    //printMemData();
    return 0;
}


