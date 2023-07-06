#include<bits/stdc++.h>
using namespace std;

//  Structure of Node
struct Node{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *head = NULL;


//  Print the linkedlist
void printList(){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


// Insert at begining of linkedlist
void insertHead(int val){
    Node *temp = new Node();
    temp->data = val;
    if(head == NULL){
        head = temp;
        return;
    }
    
    temp->next = head;
    head->prev = temp;
    
    head = temp;

}


// Insert at the end of linkedlist
void insertTail(int val){
    Node *temp = new Node();
    temp->data = val;

    if(head == NULL){
        head = temp;
        return;
    }

    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr ->next = temp;
}


// Insert at given position of linkedlist
void insertPos(int val, int pos){
    Node *temp = new Node();
    temp->data = val;

    if(pos == 1) {
        insertHead(val);
        return;
    }
    Node *curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;

}


// Delete at given position in linkedlist
void deletePos(int pos){
    if(pos == 1){
        head ->next->prev = NULL;
        head = head->next;
        return;
    }
    Node *curr = head;
    for(int i=1;i<pos-1;i++){
        curr = curr->next;
    }

    curr ->next = curr->next->next;
    curr->next->prev = curr;

}


int main(){
    
    insertHead(5);
    insertHead(8);
    insertHead(2);
    printList();

    insertTail(7);
    insertTail(9);
    printList();

    insertPos(11, 3);
    printList();

    deletePos(3);
    printList();
    return 0;
}