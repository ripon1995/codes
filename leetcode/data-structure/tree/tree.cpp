#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000000

vector<int>tree[MAX_SIZE];

void addEdge(int x,int y) {
    tree[x].push_back(y);
    tree[y].push_back(x);
}

void printTree(int node) {
    for(int i=1;i<=node;i++) {
        cout<<i<<" ";
        for(auto t:tree[i]) {
            cout<<t<<" ";
        }
        cout<<endl;
    }
}

void printParents(int source,int parent) {
    if(parent == 0) {
        cout<<source<<" : "<<"Root-->"<<endl;
    }
    else {
        cout<<source<<" ===> "<<parent<<endl; 
    }

    for(auto t:tree[source]) {
        if(t != parent) {
            printParents(t,source);
        }
    }
}

void printChildren(int root) {
    vector<bool>visited(MAX_SIZE,false);
    
    queue<int>data;
    data.push(root);
    visited[root] = true;
    while(!data.empty()) {
        int front = data.front();
        cout<<front<<" --> ";
        data.pop();
        for(auto t:tree[front]) {
            if(visited[t] == false) {
                cout<<t<<" ";
                data.push(t);
                visited[t] = true;
            }
        }
        cout<<endl;
    }
}


int main() {
    int node = 7;
    int root = 1;
    
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(4, 7);

    printTree(node);

    cout<<endl<<endl;
    printParents(root,0);
    cout<<endl<<endl;
    printChildren(root);

    return 0;
}