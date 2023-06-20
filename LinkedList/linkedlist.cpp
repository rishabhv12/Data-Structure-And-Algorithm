#include<bits/stdc++.h>
using namespace std;


// Linkedlist structure
struct Node{
    int data;
    Node *next;
};


//  Print the linkedlist

void printList(Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
    cout << "\n";
}


// Insert value at begin

void beginInsert(Node** Head, int val){
    Node* curr = new Node();
    curr->data = val;
    curr->next = *Head;

    *Head = curr; 
}


// Insert value at end
void endInsert(Node** Head, int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if(*Head == NULL) {
        *Head = temp;
        return;
    }

    Node* curr = *Head;
    while(curr->next != NULL){
        curr = curr->next; 
    }
    curr->next = temp;

}


// Insert value at any position

void posInsert(Node** Head, int pos, int val){
    Node* temp = new Node();
    temp->data = val;

    Node* curr = *Head;

    if(pos == 1){
        temp->next = *Head;
        *Head = temp;
        return;
    }

    --pos;
    while(--pos){
        curr = curr->next;
    }
    
    temp->next = curr->next;
    curr->next = temp;

}


// Delete value of given place 

void deleteByPlace(Node** Head,int pos){
    Node* curr = *Head;
    if(pos == 1){
        // curr = curr->next;
        *Head = (*Head)->next;
        
    }
    for(int i=0;i<pos-2;i++){
        curr = curr->next;
    }

    curr->next = curr->next->next;
}

// Reverse a linkedlist

void reverse(Node** Head){
    Node *curr,*next,*prev;

    curr = *Head;
    prev = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *Head = prev;
}



int main(){
    Node* Head = NULL;
    int val;

    //  Insert at begining 

    // val = 5;
    // beginInsert(&Head,val);
    // val = 6;
    // beginInsert(&Head,val);
    // printList(Head);


    // Inster at end

    val = 7;
    endInsert(&Head,val);
    val = 6;
    endInsert(&Head,val);
    val = 5;
    endInsert(&Head,val);
    val = 4;
    endInsert(&Head,val);
    printList(Head);

    
    // Insert at any position

    val = 10;
    posInsert(&Head,3,val);
    val = 11;
    posInsert(&Head,6,val);
    printList(Head);


    // Delele value at given position 

    // deleteByPlace(&Head,2);
    // printList(Head);


    // Reverse a linked list by  Iterative approch

    reverse(&Head);
    printList(Head);



    return 0;
}