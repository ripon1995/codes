#include<bits/stdc++.h>
using namespace std;

void unweightedDirectedGraph() {
    int node,edge;
    cin >> node >> edge;
    vector<int>graph[node+1];

    for(int i=1;i<=edge;i++) {
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        
    }

    for(int i=1;i<=node;i++) {
        cout<<i<<" ==>";
        for(auto g:graph[i]) {
            cout<<g<<" ";
        }
        cout<<endl;
    }    
}

void unwightedBidirectionalGraph() {
    int node,edge;
    cin >> node >> edge;
    vector<int>graph[node+1];

    for(int i=1;i<=edge;i++) {
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1;i<=node;i++) {
        cout<<i<<" ==>";
        for(auto g:graph[i]) {
            cout<<g<<" ";
        }
        cout<<endl;
    }
}

void weightedDirectionalGraph() {
    int node,edge;
    cin >> node >> edge;
    vector<int>graph[node+1];
    vector<int>cost[node+1];
    for(int i=1;i<=edge;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        graph[x].push_back(y);
        cost[x].push_back(c);
    }

    for(int i=1;i<=node;i++) {
        for(int j=0;j<graph[i].size();j++) {
            cout<< i <<" ===> "<< graph[i][j] <<" === "<< cost[i][j] <<endl;
        }
    }
}

void weightedBidirectionalGraph() {
    int node,edge;
    cin >> node >> edge;
    vector<int>graph[node+1];
    vector<int>cost[node+1];
    for(int i=1;i<=edge;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x].push_back(c);
        cost[y].push_back(c);
    }

    for(int i=1;i<=node;i++) {
        for(int j=0;j<graph[i].size();j++) {
            cout<< i <<" ===> "<< graph[i][j] <<" === "<< cost[i][j] <<endl;
        }
    }
}

int main() {
    weightedBidirectionalGraph();

    return 0;
}

/*
6 8
1 2 3
1 4 5
2 4 6
2 5 7
4 5 9
5 3 8
3 6 9
6 6 12
*/