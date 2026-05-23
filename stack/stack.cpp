#include<bits/stdc++.h>
using namespace std;

//creating a stack class using array

#define stack_size 100
int arr[stack_size];
int top = -1; //initialize the top of the stack to -1

//function to push an element onto the stack
void push(int element){
    if(top+1== stack_size){ //check if the stack is full
        cout << "Stack overflow. Cannot push element." << endl;
        return;
    }
    top++;
    arr[top] = element; //add the element to the top of the stack
}

//function to pop an element from the stack
void pop(){
    if(top==-1){
        cout << "Stack underflow. Cannot pop element." << endl;
        return;
    }
    cout << "Popped element: " << arr[top] << endl; //print the popped element
    top--; //remove the top element from the stack by decrementing the top index
}

//function to peek at the top element of the stack
int peek(){
    if(top==-1){
        cout<< "Stack is empty. Cannot peek element." << endl;
        return -1; //return -1 to indicate that the stack is empty
    }
    int element = arr[top]; //get the top element of the stack
    cout << "Top element: " << element << endl; //print the top element
    return element; //return the top element
}

//function to check if the stack is empty
bool isEmpty(){
    cout << "Stack is " << (top==-1 ? "empty." : "not empty.") << endl; //print whether the stack is empty or not
    return top==-1; //return true if the stack is empty, false otherwise
}

//function to check if the stack is full
bool isFull(){
    cout << "Stack is " << (top+1==stack_size ? "full." : "not full.") << endl; //print whether the stack is full or not
    return top+1==stack_size; //return true if the stack is full, false otherwise
}

//function to print the elements of the stack
void display(){
    if(top==-1){
        cout << "Stack is empty. Cannot display elements." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";//print the elements of the stack from top to bottom
    }
    cout << endl;
}
