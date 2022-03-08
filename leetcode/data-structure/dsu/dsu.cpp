#include<bits/stdc++.h>
using namespace std;
void makeSet(int size,vector<int>& parent,vector<int>& parentSize) {
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

bool sortByWeight(vector<int>a,vector<int>b) {
    return a[2] > b[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int>parent;
    vector<int>parentSize;
    makeSet(n+1,parent,parentSize);
    vector<vector<int>>graph;
    int u,v,w;
    for(int i=1;i<=m;i++) {
        cin >> u >> v >> w;
        graph.push_back({u,v,w});
    }
    sort(graph.begin(),graph.end(),sortByWeight);
    int weight = -1;
    int count = 0;
    for(auto gg:graph) {
        if(findSet(gg[0],parent) != findSet(gg[1],parent)) {
            count++;
            weight = max(weight,gg[2]);
            unionSet(gg[0],gg[1],parent,parentSize);
            if(count >= n) {
                break;
            }
        }
    }
    cout<< weight << "\n";
    return 0;
}