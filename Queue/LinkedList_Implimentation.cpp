#include<bits/stdc++.h>
using namespace std;


// Structure of Linkedlist
struct Node{
    int data;
    Node *next = NULL;
};

Node* Head;
Node* Last;


// Print the queue
void print_list(){
    Node *temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


// Pushing value in the queue
void enque_list(int val){
    Node *temp = new Node();
    temp->data = val;

    if(Head==NULL){
        Head = temp;
        Last = temp;
        return;
    }
    
    Last->next = temp;
    Last = temp;   
}


// Removing value from the list

void deque_list(){
    if(Head == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(Head->next == NULL){
        Head = NULL;
        return;
    }
    Head = Head->next;
}


int main(){
    Head = NULL;
    Last = NULL;

    enque_list(5);
    enque_list(6);
    enque_list(8);
    print_list();

    deque_list();
    print_list();
    return 0;
}