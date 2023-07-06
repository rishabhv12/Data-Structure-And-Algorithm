#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *head = NULL;

void printList(){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

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



int main(){
    
    insertHead(5);
    insertHead(8);
    insertHead(2);
    printList();

    insertTail(7);
    insertTail(9);
    printList();
    return 0;
}