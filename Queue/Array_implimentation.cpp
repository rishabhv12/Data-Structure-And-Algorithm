#include<bits/stdc++.h>
using namespace std;

//  Initializing values 
#define size 10
int ar[size];
int front = -1;
int rear = -1;


// Print the queue
void print_list(){
    cout<<front<<" "<<rear<<endl;
    for(int i=front;i<=rear;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

// Pushing value in queue
void enque_list(int val){
    
    if((rear+1)%size == front){
        cout<<"Queue is full"<<endl;
        return;
    }
    if(front ==-1 && rear == -1){
        front=0; 
        rear=0;
    }
    else {
        rear = (rear+1)%size;
    }
    ar[rear] = val;
}

// Removing value from queue
void deque_list(){
    if(front ==-1 && rear == -1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    front = (front+1)%size;
}


int main(){
    
    enque_list(5);
    enque_list(8);
    enque_list(2);
    print_list();

    deque_list();
    print_list();

    return 0;
}