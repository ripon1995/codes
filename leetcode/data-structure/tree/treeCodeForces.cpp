#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    int val;
    struct LinkedList* next;
    LinkedList(): val(0),next(nullptr){}
    LinkedList(int data):val(data),next(nullptr){}
};

void insert(int val, LinkedList* temp) {
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new LinkedList(val);
}

void printLinkedList(LinkedList* temp) {
    while(temp != nullptr) {
        cout<<temp->val<<" ";
        temp =temp->next;
    }
    cout<<endl;
}


LinkedList* getIndex(LinkedList* root,vector<int>& index,int q) {

    if(root->val == q) {
        index.push_back(1);
        return root;    
    }

    int i = 2;
    LinkedList* temp = root;
    while(temp->next->val != q) {
        i++;
        temp = temp->next;
    }
    index.push_back(i);
    LinkedList* newNode = temp->next;
    temp->next = temp->next->next;
    free(temp->next);
    newNode->next = root;
    root = newNode;
    return root;
}


int main() {
    int n,q;
    cin >> n >> q;
    int val;
    struct LinkedList* root;
    struct LinkedList* temp;
    for(int i=1;i<=n;i++) {
        cin >> val;
        if(i==1) {
            root =new LinkedList(val);
            temp = root;
        }
        else {
            temp->next = new LinkedList(val);
            temp =temp->next;
        }
    }
    vector<int>index;
    for(int i=1;i<=q;i++) {
        //printLinkedList(root);
        cin >> val;
        root = getIndex(root,index,val);
    }

    for(auto i:index) {
        cout << i << " ";
    }
}

/*
7 5
2 1 1 4 3 3 1
3 2 1 1 4
*/