// Apply the concept of Linked list and write code to Insert and Delete an element at the beginning and atend in Doubly and Circular Linked List.
#include <bits/stdc++.h>
using namespace std;

struct DoublyNode
{
    int val;
    struct DoublyNode *next;
    struct DoublyNode *prev;
    DoublyNode(int value) : val(value), next(nullptr), prev(nullptr) {}
};

struct CircularNode
{
    int val;
    struct CircularNode *next;

    CircularNode(int x) : val(x), next(nullptr) {}
};

void insertBegDoublyList(DoublyNode *&head, int val)
{
    DoublyNode *temp = new DoublyNode(val);
    temp->next = head;
    if (head != nullptr)
        head->prev = temp;
    head = temp;
    cout << "beg" << head->val;
}

void insertEndDoublyList(DoublyNode *head, int val)
{
    DoublyNode *cur = head;
    if (cur == nullptr)
        return insertBegDoublyList(head, val);

    while (cur->next != nullptr)
        cur = cur->next;

    DoublyNode *temp = new DoublyNode(val);
    temp->prev = cur;
    cur->next = temp;
}

void deleteBegDoublyList(DoublyNode *head)
{
    if (head == nullptr)
        return;

    DoublyNode *t = head;
    delete t;
    head = head->next;
    head->prev = nullptr;
}

void deleteEndDoublyList(DoublyNode *head)
{
    if (head == nullptr)
        return;
    DoublyNode *cur = head;
    while (cur->next != nullptr)
        cur = cur->next;

    cur->next = nullptr;
    DoublyNode *t = cur->next;
    delete t;
}

void printDoublyList(DoublyNode *head)
{
    DoublyNode *cur = head;
    cout << "Doubly Linked List: ";
    while (cur != nullptr)
    {
        cout << cur->val << " ";
    }
    cout << endl;
}

int main()
{

    DoublyNode *dl = nullptr;
    insertBegDoublyList(dl, 21);
    // insertBegDoublyList(dl, 2);
    // insertEndDoublyList(dl, 1);
    // insertEndDoublyList(dl, 5);
    // deleteBegDoublyList(dl);
    // printDoublyList(dl);
    // deleteEndDoublyList(dl);
    printDoublyList(dl);

    return 0;
}