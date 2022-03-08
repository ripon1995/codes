#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5

vector<int> STACK;

void stackPush(int val) {
    if(STACK.size()>=MAX_SIZE) {
        cout<<"STACK IS FULL"<<endl;
        return;
    }
    STACK.push_back(val);
    cout<<"NEW VALUE INSERTED"<<endl;
}

void stackPop() {
    if(STACK.size()==0) {
        cout<<"STACK IS EMPTY"<<endl;
        return;
    }
    int val = STACK.back();
    cout<<val<<endl;
    STACK.pop_back();
}

void stackSize() {
    cout<<"Stack size: "<<STACK.size()<<endl;
}

void stackTop() {
    int val = STACK.back();
    cout<<"TOP: "<<val<<endl;
}


int main() {
    stackPush(10);
    stackPush(20);
    stackPop();
    stackSize();
    stackTop();
    return 0;    
}