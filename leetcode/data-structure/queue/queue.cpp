#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 5
vector<int>q;

void enqueue(int val) {
    if(q.size() >= MAX_SIZE) {
        cout<<"QUEUE IS FULL"<<endl;
        return;
    }
    q.push_back(val);
}

void dequeue() {
    if(q.size() <= 0) {
        cout<<"QUEUE IS EMPTY"<<endl;
        return;
    }
    q.erase(q.begin()+0);
}

void peek() {
    if(q.size() <= 0) {
        cout<<"QUEUE IS EMPTY"<<endl;
        return;
    }
    cout<<q[0]<<endl;
}

void isEmpty() {
    if(q.size() == 0) {
        cout<<"QUEUE IS EMPTY"<<endl;
    }
    else if(q.size() == MAX_SIZE) {
        cout<<"QUEUE IS FULL"<<endl;
    }
}

int main() {
    isEmpty();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    isEmpty();
    peek();
    
    return 0;
}