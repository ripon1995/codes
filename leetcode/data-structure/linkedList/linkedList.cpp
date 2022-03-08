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

void insertAtLast(int val) {
    ListNode *temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    ListNode *newNode = new ListNode(val);
    temp->next = newNode;
}

void insertAtFront(int val) {
    ListNode *temp = head;
    ListNode *newNode = new ListNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterANode(int key,int val) {
    ListNode *temp = head;
    while(temp->val!=key) {
        temp = temp->next;
    }
    ListNode *newNode = new ListNode(val);
    newNode ->val = val;
    newNode ->next = temp->next;
    temp->next = newNode;
}

void deleteFromLast() {
    ListNode *temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
}

void deleteFromFront() {
    ListNode *temp = head;
    temp->next = temp->next->next;
    free(temp->next);
}

void deleteSpecificNode(int val) {
    ListNode *temp = head;
    while(temp->next->val != val) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next);
}

void deleteIthNode(int nodeNumber) {
    int nodeCount = 0;
    ListNode *temp = head;
    while(temp->next != nullptr) {
        nodeCount++;
        if(nodeCount == nodeNumber) {
            break;
        }
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next);
}

void deleteNodeRange(int a,int b) {
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    int c = 0;
    while(temp1->next != nullptr) {
        c++;
        if(c < a) {
            temp2=temp2->next;
        }
        if(c == b+1) {
            break;
        }
        temp1 = temp1->next;
    }
    cout<<temp2 ->val<<endl;
    cout<<temp1->val<<endl;
    temp2->next = temp1->next;
 }

void traverseList() {
    ListNode *temp = head;

    cout<<"Traverse: ";
    while(temp != nullptr) {
        cout<<temp ->val <<" ";
        temp = temp->next;
    }
}

void rotateList(int n) {
    for(int i=1;i<=n;i++) {
        ListNode *temp = head;
        ListNode *lastNode;
        while(temp->next->next != nullptr ) {
            temp = temp->next;
        }
        lastNode = temp->next;
        temp->next = nullptr;
        
    }
}

int main() {
    initializeHeadNode();
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(40);
    insertAtLast(50);
    rotateList(1);
    traverseList();  
    vector<int>v= {1,1,2,3,3};
    cout<< v.back() <<endl;
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto d:v)cout<<d<<" "; 
    return 0;
}

/*
<View
        android:id="@+id/no_friend_view"
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_marginTop="@dimen/_16sdp"
        android:background="@color/white_lilac"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintTop_toBottomOf="@id/tvFriendList" />

    <androidx.appcompat.widget.AppCompatImageView
        android:id="@+id/ivNoFriend"
        android:layout_width="@dimen/_155sdp"
        android:layout_height="@dimen/_155sdp"
        android:layout_marginTop="@dimen/_24sdp"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="@id/no_friend_view"
        app:srcCompat="@drawable/ic_no_friend" />

    <com.google.android.material.textview.MaterialTextView
        android:id="@+id/tvNoFriend"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="@dimen/_18sdp"
        android:text="@string/you_have_no_friend"
        android:textColor="@color/black"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toBottomOf="@id/ivNoFriend" />
*/