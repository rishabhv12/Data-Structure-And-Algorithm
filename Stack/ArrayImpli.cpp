#include<bits/stdc++.h>
#define SIZE 10

using namespace std;

//  Initialise Stack
int arr[SIZE];
int top = -1;


// Pushing data in stack
void push(int val){
    if(top==SIZE-1){
        cout<<"Stck is overflow"<<endl;
        return;
    }
    top += 1;
    arr[top] = val;
}


// Remove data from top of stack
void pop(){
    if(top==-1){
        cout<<"Stck is empty"<<endl;
        return;
    }
    top -=1;
}


// Print the stack
void print(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// Impliment top() function
void top_stack(){
    if(top==-1){
        cout<<"Stck is empty"<<endl;
        return;
    }
    cout<<arr[top]<<endl;
}



int main(){
    push(10);
    push(3);
    push(5);

    print();
    pop();

    print();
    top_stack();
    
    return 0;
}