#include<bits/stdc++.h>
using namespace std;

void makeSet(int size,vector<int>& parent, vector<int>& parentSize) {
    for(int i=0;i<size;i++) {
        parent.push_back(i);
        parentSize.push_back(1);
    }
}

int findSet(int val,vector<int>& parent) {
    if(val == parent[val]) {
        return val;
    }

    return parent[val] = findSet(parent[val],parent);
}

void unionSet(int a,int b,vector<int>& parent,vector<int>& parentSize) {
    a = findSet(a,parent);
    b = findSet(b,parent);
    if(a != b) {
        if(parentSize[a] < parentSize[b]) {
            swap(a,b);
        }
        parent[b] = a;
        parentSize[a] += parentSize[b];
    }
}


void printParent(vector<int>parent,vector<int>parentSize) {
    cout<<"Parent: ";
    for(auto p:parent) {
        cout<<p<<" ";
    }
    cout<<endl;
    cout<<"  Size: ";
    for(auto p:parentSize) {
        cout<<p<<" ";
    }
    cout<<endl;
}

int main() {
    vector<vector<string>>accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<int>parent;
    vector<int>parentSize;
    makeSet(accounts.size(),parent,parentSize);

    unordered_map<string,int>emailGroup;
    for(int i=0;i<accounts.size();i++) {
        for(int j=1;j<accounts[i].size();j++) {
            string email = accounts[i][j];
            string accountHolder = accounts[i][0];
            if(!emailGroup.count(email)) {
                emailGroup[email] = i;
            }
            else {
                int account = emailGroup[email];
                unionSet(i,account,parent,parentSize);
            }
        }
    }
    printParent(parent,parentSize);
    unordered_map<int,vector<string>> components;
    for(auto e:emailGroup) {
        int accountHolder = findSet(e.second,parent);
        components[accountHolder].push_back(e.first);
    }
    vector<vector<string>>res;
    for(auto c:components) {
        //cout<<c.first<<": ";
        vector<string>data;
        data.push_back(accounts[c.first][0]);
        sort(c.second.begin(),c.second.end());
        for(auto mail:c.second) {
            data.push_back(mail);
        }
        res.push_back(data);
    }


    for(auto rr:res) {
        for(auto r:rr) {
            cout<<r<<" ";
        }
        cout<<endl;
    }

    return 0;
}