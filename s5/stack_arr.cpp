/*
Q1. Analyze if stack is empty or full, and if elements are present return the top element in the stack using template. Also perform push and pop operation in the stack.
*/

#include <iostream>
#define MAX_LIMIT 25
using namespace std;

int arr[MAX_LIMIT];
int front = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return front == MAX_LIMIT - 1;
}

void push(int num)
{
    if (isFull())
    {
        cout << "Stack is Full" << endl;
        throw exception();
    }
    front++;
    arr[front] = num;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Empty stack" << endl;
        throw exception();
    }

    return arr[front--];
}

int top()
{
    if (isEmpty())
    {
        cout << "Empty stack" << endl;
        throw exception();
    }

    return arr[front];
}

int main()
{
    cout << "Empty: " << (isEmpty() ? "True" : "False") << endl;
    push(24);
    push(32);
    cout << pop() << endl;
    push(6);
    cout << top() << endl;
    cout << pop() << endl;

    return 0;
}