#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtLast(int val)
{
    Node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *traveller = head;

    while (traveller->next != NULL)
    {
        traveller = traveller->next;
    }

    traveller->next = newNode;
}

void deleteHead()
{
    if (head == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node *to_delete = head;
    head = head->next;
    delete to_delete;
}

void enqueue(int element)
{
    insertAtLast(element);
    cout << element << " enqueued" << endl;
}

int frontElement()
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    return head->data;
}

void dequeue()
{
    if (head == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << head->data << " dequeued" << endl;
    deleteHead();
}

void display()
{
    if (head == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *traveller = head;

    cout << "Queue elements: ";

    while (traveller != NULL)
    {
        cout << traveller->data << " ";
        traveller = traveller->next;
    }

    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    cout << "Front element: " << frontElement() << endl;

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue();

    return 0;
}