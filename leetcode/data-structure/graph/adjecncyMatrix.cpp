#include<bits/stdc++.h>
using namespace std;

/*
input: 
3 3
1 2
2 3
3 1
*/

void unweightedDirectionalGraph() {
    int node,edge;
    cin >> node >> edge;
    int graph[node+1][node+1];
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=edge;i++) {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
    }

    for(int i=1;i<=node;i++) {
        for(int j=1;j<=node;j++) {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
input: 
3 3
1 2
2 3
3 1
*/

void unweightedBiDirectionalGraph() {
    int node,edge;
    cin >> node >> edge;
    int graph[node+1][node+1];
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=edge;i++) {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }

    for(int i=1;i<=node;i++) {
        for(int j=1;j<=node;j++) {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void weightedDirectedGraph() {
    int node,edge;
    cin >> node >> edge;
    int graph[node+1][node+1];
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=edge;i++) {
        int n1,n2,val;
        cin >> n1 >> n2 >> val;
        graph[n1][n2] = val;
    }

    for(int i=1;i<=node;i++) {
        for(int j=1;j<=node;j++) {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void weightedUndirectedGraph() {
    int node,edge;
    cin >> node >> edge;
    int graph[node+1][node+1];
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=edge;i++) {
        int n1,n2,val;
        cin >> n1 >> n2 >> val;
        graph[n1][n2] = val;
        graph[n2][n1] = val;
    }

    for(int i=1;i<=node;i++) {
        for(int j=1;j<=node;j++) {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    weightedDirectedGraph();
    return 0;
}