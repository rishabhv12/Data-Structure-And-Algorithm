// Reverse Linkedlist using stack

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};

Node *Head;

//  Print the linkedlist
void printList()
{
    Node *node = Head;
    while (node != NULL) {
        cout<< node->data<<" ";
        node = node->next;
    }
    cout << "\n";
}

// Insert value at begin
void beginInsert(int val){
    Node* curr = new Node();
    curr->data = val;
    curr->next = Head;

    Head = curr; 
}

// Reverse Linkedlist using stack
void reverse_list(){
    
    stack<struct Node*> st;

    Node *temp = Head;
    while(temp){
        st.push(temp);
        temp = temp->next;
    }

    temp = st.top();
    Head = temp;
    st.pop();

    // Adjusting addresses
    while(!st.empty()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}


int main(){
    Head = NULL;
    beginInsert(2);
    beginInsert(5);
    beginInsert(7);
    beginInsert(9);

    printList();
    reverse_list();
    printList();
    return 0;
}