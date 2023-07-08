#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};

Node *Head;

//  Pushing value in Stack
void push(int val){
    Node *temp = new Node;
    temp->data = val;

    if(Head==NULL){
        Head = temp;
        return;
    }

    temp->next = Head;
    Head = temp;
}

//  Removing value from Stack
void pop(){
    if(Head==NULL){
        cout<<"Stack is empty";
        return;
    }
    Head = Head->next;

}


// Print all elements present in Stack
void printList(){
    Node *temp  = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//  Impliment top() functionality of Stack
void print_top(){
    if(Head==NULL){
        cout<<"Stack is empty";
        return;
    }
    cout<<Head->data<<endl;
}


int main(){
    Head = NULL;
    push(10);
    push(5);
    push(7);
    printList();

    pop();
    printList();

    print_top();
    return 0;
}