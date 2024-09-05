#include <iostream>
using namespace std;
#define LIMIT 25

int arr[LIMIT];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
        return;
    }
    else if (isEmpty())
    {
        rear = front = 0;
        arr[front] = value;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }
}
bool isFull()
{
    if (rear >= LIMIT)
        return true;
    return false;
}

bool isEmpty()
{
    if (rear == -1 && front == -1)
        return true;
    return false;
}