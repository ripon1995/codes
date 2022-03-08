#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000000

vector<int>graph[MAX_SIZE];
vector<int>visited(MAX_SIZE,false);

void addEdge(int node1,int node2) {
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

void inputGraph(int edge) {
    for(int i=1;i<=edge;i++) {
        int node1,node2;
        cin >> node1 >> node2;
        addEdge(node1,node2);
    }
}

void printGraph(int node) {
    for(int i=1;i<=node;i++) {
        cout << i <<" ===> ";
        for(auto g:graph[i]) {
            cout << g <<" ";
        }
        cout << endl;
    }
}

void bfsTraversal(int source) {
    queue<int>data;
    data.push(source);
    visited[source] = true;
    while(!data.empty()) {
        int front = data.front();
        data.pop();
        cout<<front<<" ";
        for(auto g:graph[front]) {
            if(visited[g] == false) {
                data.push(g);
                visited[g] = true;
            }
        }
    }
}

int main() {
    int node,edge;
    cout<<"Node: ";
    cin >> node;
    cout<<"Edge: ";
    cin >> edge;

    inputGraph(edge);

    printGraph(node);

    cout<<"Bfs from 1: ";
    bfsTraversal(1);
    cout<<endl;

    visited.assign(MAX_SIZE,false);
    cout<<"Bfs from 3: ";
    bfsTraversal(3);
    cout<<endl;

    visited.assign(MAX_SIZE,false);
    cout<<"Bfs from 5: ";
    bfsTraversal(5);

    return 0;
}

/*
5 
6
1 2
1 4
1 5
2 3
2 4
4 5
*/