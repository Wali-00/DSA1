/*A linked list is a fundamental data structure
that consists of a sequence of nodes, where each node contains data and a reference (or pointer) to the next node in the sequence. This structure allows for efficient insertion and deletion of elements, as well as dynamic memory allocation. Linked lists can be singly linked (where each node points to the next node) or doubly linked (where each node points to both the next and previous nodes). They are commonly used in various applications such as implementing stacks, queues, and other abstract data types.
*/

/*we can only traverse the list in one direction which is from head to tail,we can't traverse backwards.but in doubly linked lists, we can traverse both forward and backward.*/

/*
important thing is we need to find the head of the list first*/

/*array vs linked list

linked list provides dynamic memory allocation while array has fixed size

deletion in linked list is more efficient than in array

wastage of memory in array is less than linked list*/

#include<bits/stdc++.h>
using namespace std;


 //creating a node structure for linked list
    struct Node{
        int data;
        Node* next;
    };

    Node* head = NULL; //initialize the head of the linked list to null

//create a function to create a new node
Node* createNode(int data){ 
    Node* newNode = new Node;//dynamically allocate memory for a new node
    newNode->data = data;//assign the data to the new node
    newNode->next = NULL;//initialize the next pointer to null
    return newNode;//return the pointer to the new node
}


//function to insert a new node at the first position of the linked list
void insertAtHead(int data){
    Node* newNode = createNode(data);//create a new node with the given data
    if(head == NULL){ //if the linked list is empty, make the new node the head
        head = newNode;
        return;
    }
    newNode->next = head; //point the next of the new node to the current head
    head = newNode; //update the head to the new node
}

//function to insert a new node at the end of the linked list
void insertAtTail(int data){
    Node* newNode = createNode(data);//create a new node with the given data
    if(head == NULL){ //if the linked list is empty, make the new node the head
        head = newNode;
        return;
    }
    Node* temp = head; //start from the head of the linked list
    while(temp->next != NULL){ //traverse to the end of the linked list
        temp = temp->next;
    }
    temp->next = newNode; //point the next of the last node to the new node
}

//function to insert a new node at a specific position in the linked list
void insertAtPosition(int data, int position){
    Node* temp = head; //start from the head of the linked list
    while(temp != NULL ){ //traverse the linked list to find the position
        if(temp->data == position){ //if the current node's data matches the position
            Node* newNode = createNode(data); //create a new node with the given data
            newNode->next = temp->next; //point the next of the new node to the next of the current node
            temp->next = newNode; //point the next of the current node to the new node
            return;
        }
        temp = temp->next; //move to the next node
    }
    cout << "Position not found in the linked list." << endl;
}

// Helper to print list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//delete a node from head
void deleteAtHead(){
    if(head == NULL){ //if the linked list is empty, return
        cout << "Linked list is empty." << endl;
        return;
    }
    Node* temp = head; //store the current head in a temporary variable
    head = head->next; //update the head to the next node
    delete temp; //deallocate memory for the old head
}

//delete a node from tail
void deleteAtTail(){
    if(head == NULL){ //if the linked list is empty, return
        cout << "Linked list is empty." << endl;
        return;
    }
    if(head->next == NULL){ //if there is only one node in the linked list, delete it and set head to null
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head; //start from the head of the linked list
    while(temp->next->next != NULL){ //traverse to the second last node of the linked list
        temp = temp->next;
    }
    delete temp->next; //deallocate memory for the last node
    temp->next = NULL; //set the next of the second last node to null
}

//delete a node from a specific position in the linked list
void deleteAtPosition(int position){
    if(head == NULL){ //if the linked list is empty, return
        cout << "Linked list is empty." << endl;
        return;
    }
    if(head->data == position){ //if the head node's data matches the position, delete the head node
        deleteAtHead();
        return;
    }
    Node* temp = head; //start from the head of the linked list
    while(temp->next != NULL){ //traverse the linked list to find the position
        if(temp->next->data == position){ //if the next node's data matches the position
            Node* nodeToDelete = temp->next; //store the node to be deleted in a temporary variable
            temp->next = temp->next->next; //point the next of the current node to the next of the node to be deleted
            delete nodeToDelete; //deallocate memory for the node to be deleted
            return;
        }
        temp = temp->next; //move to the next node
    }
    cout << "Position not found in the linked list." << endl;
}

int main(){
   

insertAtHead(10); // Insert 10 at the head
    insertAtTail(20); // Insert 20 at the tail
    insertAtPosition(15, 10); // Insert 15 after the node with data 10

    printList();
    return 0;


}