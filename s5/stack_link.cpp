/*
Q1. Analyze if stack is empty or full, and if elements are present return the top element in the stack using template. Also perform push and pop operation in the stack.
*/

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;

bool isEmpty()
{
    return head == nullptr;
}
bool isFull()
{
    return false;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        throw exception();
    }
    Node *cur = head;
    head = cur->next;
    return cur->data;
}

void push(int data)
{
    Node *cur = new Node;
    cur->data = data;
    cur->next = head;
    head = cur;
}

int top()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        throw exception();
    }
    return head->data;
}

int main()
{
    cout << "Empty: " << (isEmpty() ? "True" : "False") << endl;
    push(2);
    push(3);
    cout << pop() << endl;
    push(16);
    cout << top() << endl;
    cout << pop() << endl;
    return 0;
}
