#include<bits/stdc++.h>
using namespace std;

struct ListNode *head = NULL;

struct ListNode { 
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int val):val(val),next(nullptr){};
    ListNode(int val, ListNode *next): val(val),next(next){}
};

void initializeHeadNode() {
    head = new ListNode();
    head ->val = -1;
    head ->next = nullptr;
}

void traverseList() {
    ListNode *temp = head;

    cout<<"Traverse: ";
    while(temp != nullptr) {
        cout<<temp ->val <<" ";
        temp = temp->next;
    }
}

int main() {
    string s = "101";
    int data = stoi(s,0,2);
    cout << data <<endl;      
    return 0;
}