#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000
vector<int>graph[MAX_SIZE];
vector<bool>visited(MAX_SIZE,false);

void addEdge(int x,int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void inputGraph(int node,int edge) {
    for(int i=1;i<=edge;i++) {
        int x,y;
        cin >> x >>y;
        addEdge(x,y);
    }
}

void printGraph(int node) {
    cout<<"Graph: "<<endl;
    for(int i=1;i<=node;i++) {
        cout<<i<<" ===> ";
        for(auto g:graph[i]) {
            cout<<g<<" ";
        }
        cout<<endl;
    }
}

void dfsTraversal(int source) {
    visited[source] = true;
    cout << source << " ";
    for(auto g:graph[source]) {
        //cout<<g<<" ";
        if(visited[g] == false) {
            dfsTraversal(g);
        }
    }
}

int main() {
    int node,edge;
    cout<<"Node: ";
    cin >> node;
    cout<<"Edge: ";
    cin >> edge;
    inputGraph(node,edge);

    printGraph(node);

    cout<<"Dfs from 1: ";
    dfsTraversal(1);
    cout<<endl;
    visited.assign(MAX_SIZE,false);
    cout<<"Dfs from 3: ";
    dfsTraversal(3);
    cout<<endl;
    visited.assign(MAX_SIZE,false);
    cout<<"Dfs from 2: ";
    dfsTraversal(2);
}