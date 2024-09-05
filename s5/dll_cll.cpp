#include <bits/stdc++.h>
using namespace std;

struct DoublyNode
{
    int val;
    DoublyNode *next;
    DoublyNode *prev;
    DoublyNode(int value) : val(value), next(nullptr), prev(nullptr) {}
};

struct CircularNode
{
    int val;
    CircularNode *next;
    CircularNode(int x) : val(x), next(nullptr) {}
};

// Doubly Linked List Operations
void insertBegDoublyList(DoublyNode *&head, int val)
{
    DoublyNode *temp = new DoublyNode(val);
    temp->next = head;
    if (head != nullptr)
        head->prev = temp;
    head = temp;
}

void insertEndDoublyList(DoublyNode *&head, int val)
{
    if (head == nullptr)
    {
        insertBegDoublyList(head, val);
        return;
    }
    DoublyNode *cur = head;
    while (cur->next != nullptr)
        cur = cur->next;
    DoublyNode *temp = new DoublyNode(val);
    temp->prev = cur;
    cur->next = temp;
}

void deleteBegDoublyList(DoublyNode *&head)
{
    if (head == nullptr)
        return;
    DoublyNode *temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

void deleteEndDoublyList(DoublyNode *&head)
{
    if (head == nullptr)
        return;
    DoublyNode *cur = head;
    if (cur->next == nullptr)
    {
        delete cur;
        head = nullptr;
        return;
    }
    while (cur->next != nullptr)
        cur = cur->next;
    cur->prev->next = nullptr;
    delete cur;
}

void printDoublyList(DoublyNode *head)
{
    DoublyNode *cur = head;
    // cout << "Doubly Linked List: ";
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Circular Linked List Operations
void insertBegCircularList(CircularNode *&head, int val)
{
    CircularNode *temp = new CircularNode(val);
    if (head == nullptr)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        CircularNode *cur = head;
        while (cur->next != head)
            cur = cur->next;
        temp->next = head;
        cur->next = temp;
        head = temp;
    }
}

void insertEndCircularList(CircularNode *&head, int val)
{
    CircularNode *temp = new CircularNode(val);
    if (head == nullptr)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        CircularNode *cur = head;
        while (cur->next != head)
            cur = cur->next;
        cur->next = temp;
        temp->next = head;
    }
}

void deleteBegCircularList(CircularNode *&head)
{
    if (head == nullptr)
        return;
    CircularNode *cur = head;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        while (cur->next != head)
            cur = cur->next;
        CircularNode *temp = head;
        head = head->next;
        cur->next = head;
        delete temp;
    }
}

void deleteEndCircularList(CircularNode *&head)
{
    if (head == nullptr)
        return;
    CircularNode *cur = head;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        while (cur->next->next != head)
            cur = cur->next;
        CircularNode *temp = cur->next;
        cur->next = head;
        delete temp;
    }
}

void printCircularList(CircularNode *head)
{
    if (head == nullptr)
        return;
    CircularNode *cur = head;
    // cout << "Circular Linked List: ";
    do
    {
        cout << cur->val << " ";
        cur = cur->next;
    } while (cur != head);
    cout << endl;
}

int main()
{
    // Doubly Linked List Operations
    cout << "Doubly Linked List" << endl;
    DoublyNode *dl = nullptr;
    insertBegDoublyList(dl, 21);
    insertEndDoublyList(dl, 42);
    insertBegDoublyList(dl, 2);
    insertEndDoublyList(dl, 84);
    cout << "After Insertion " << endl;
    printDoublyList(dl);
    deleteBegDoublyList(dl);
    cout << "Begin Delete " << endl;
    printDoublyList(dl);
    deleteEndDoublyList(dl);
    cout << "End Delete " << endl;
    printDoublyList(dl);
    cout << endl
         << endl;

    // Circular Linked List Operations
    cout << "Circular Linked List" << endl;
    CircularNode *cl = nullptr;
    insertBegCircularList(cl, 5);
    insertEndCircularList(cl, 10);
    insertEndCircularList(cl, 20);
    cout << "After Insertion " << endl;
    printCircularList(cl);
    deleteBegCircularList(cl);
    cout << "Begin Delete " << endl;
    printCircularList(cl);
    deleteEndCircularList(cl);
    cout << "End Delete " << endl;
    printCircularList(cl);

    return 0;
}