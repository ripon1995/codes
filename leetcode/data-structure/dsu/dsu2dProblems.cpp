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
    //cout<<a <<" "<<b<<endl;
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
        cout<<p<<"  ";
    }
    cout<<endl;
    cout<<"  Size: ";
    for(auto p:parentSize) {
        cout<<p<<"  ";
    }
}

int main() {
    vector<vector<int>> grid = {
        {1,1,0,0},
        {0,0,0,0},
        {0,0,1,1}
    };

    int row = grid.size();
    int col = grid[0].size();
    vector<int> parent;
    vector<int> parentSize;
    makeSet(row*col,parent,parentSize);

    // full row    
    for(int i=0;i<grid.size();i++) {
        bool isFound = false;
        int startVal;
        for(int j=0;j<grid[i].size();j++) {
            if(grid[i][j] == 0) {
                continue;
            }
            if(isFound == false && grid[i][j] == 1) {
                startVal = i*col + j;
                isFound = true;
            }

            if(isFound == true) {
                int currentVal = i*col + j;
                unionSet(startVal,currentVal,parent,parentSize);
            }
            
        }
    }
    //printParent(parent,parentSize);

    // full column
    for(int i=0;i<grid[0].size();i++) {
        bool isFound = false;
        int startVal;
        for(int j=0;j<grid.size();j++) {
            if(grid[j][i] == 0) {
                continue;
            }
            if(isFound == false && grid[j][i] == 1) {
                startVal = j*col + i;
                isFound = true;
            }
            if(isFound == true) {
                int currentVal = j*col + i;
                unionSet(startVal,currentVal,parent,parentSize);
            }
        }
    }

    map<int,int>count;
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[i].size();j++) {
            if(grid[i][j] == 0) continue;
            int val = i*col + j;
            val = findSet(val,parent);
            count[val]++;
        }
    }

    printParent(parent,parentSize);
}