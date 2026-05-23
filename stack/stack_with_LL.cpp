#include<bits/stdc++.h>
using namespace std;

//creating a node structure for linked list
struct Node{
    int data;
    Node *next;
};

Node *head = NULL; //initialize the head of the linked list to null

//create a function to create a new node
void createNode(int data){
    Node *newNode=new Node();//dynamically allocate memory for a new node
    newNode->data=data;//assign the data to the new node
    newNode->next=NULL;//initialize the next pointer to null
    
}

//function to insert a new node at the first position of the linked list
void insertAtHead(int data){
    Node *newNode=new Node;//create a new node with the given data
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){ //if the linked list is empty, make the new node the head
        head=newNode;
        return;
    }
    newNode->next=head; //point the next of the new node to the current head
    head=newNode; //update the head to the new node
}

//function to insert a new node at the end of the linked list
void insertAtTail(int data){
    Node *newNode=new Node;//create a new node with the given data
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){ //if the linked list is empty, make the new node the head
        head=newNode;
        return;
    }
    Node *temp=head; //start from the head of the linked list
    while(temp->next!=NULL){ //traverse to the end of the linked list
        temp=temp->next;
    }
    temp->next=newNode; //point the next of the last node to the new node
}

//function to delete a node from head
void deleteAtHead(){
    if(head==NULL){ //if the linked list is empty, return
        cout<<"Linked list is empty."<<endl;
        return;
    }
    Node *temp=head; //store the current head in a temporary variable
    head=head->next; //update the head to the next node
    delete temp; //deallocate memory for the old head
}

//function to push an element onto the stack
void push(int element){
    insertAtHead(element); //push an element onto the stack by inserting it at the head of the linked list
}

//function to pop an element from the stack
void pop(){
    if(head==NULL){ //if the stack is empty, return
        cout<<"Stack underflow. Cannot pop element."<<endl;
        return;
    }
    cout<<"Popped element: "<<head->data<<endl; //print the popped element
    deleteAtHead(); //pop an element from the stack by deleting the head of the linked list
}

//function to peek at the top element of the stack
int peek(){
    if(head==NULL){ //if the stack is empty, return
        cout<<"Stack is empty. Cannot peek element."<<endl;
        return -1; //return -1 to indicate that the stack is empty
    }
    int element=head->data; //get the top element of the stack
    cout<<"Top element: "<<element<<endl; //print the top element
    return element; //return the top element
}

//function to print the elements of the stack
void display(){
    if(head==NULL){ //if the stack is empty, return
        cout<<"Stack is empty. Cannot display elements."<<endl;
        return;
    }
    cout<<"Stack elements: ";
    Node *temp=head; //start from the head of the linked list
    while(temp!=NULL){ //traverse the linked list to print the elements of the stack
        cout<<temp->data<<" "; //print the current element
        temp=temp->next; //move to the next node
    }
    cout<<endl;
}