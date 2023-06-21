#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};


Node *head;
void insert(int val){
    Node *curr = new Node();
    if(head == NULL){
        curr->data = val;
        curr->next = NULL;
        head = curr;
        return;
    }
    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    curr->data = val;
    curr->next = NULL;

    temp->next = curr;
}

void printList()
{
    Node* node = head;
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << "\n";
}

// Forward iterating in linkedlist using Recursion

void forward(Node *curr){
    if(curr == NULL) return;

    cout<<curr->data<<" ";
    forward(curr->next);
}

// Backward iterating in linkedlist using Recursion

void backward(Node *curr){
    if(curr == NULL) return;

    
    backward(curr->next);
    cout<<curr->data<<" ";
}

//  Reverse a linkedlist by Recursion 

void reverse(Node *curr){
    if(curr == NULL) return;

    if(curr->next == NULL){
        head = curr;
        return;
    }
    reverse(curr->next);
    Node* p = curr->next;
    p->next = curr;
    curr->next = NULL;
}


int main(){
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);

    printList();

    forward(head);
    backward(head);
    
    // reverse(head);
    // printList();
    return 0;
}