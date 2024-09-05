#include <bits/stdc++.h>
using namespace std;

typedef struct MyTree
{
    int value;
    struct MyTree *right;
    struct MyTree *left;

} MyTree;

void inOrderTraverse(MyTree *root)
{
    stack<MyTree *> st;
    if (root == NULL)
        return;
    st.push(root);
    bool down = true;
    MyTree *temp;
    while (!st.empty())
    {
        // if (st.top()->left)
        //     st.push(st.top()->left);
        // if (st.top()->right)
        //     st.push(st.top()->right);
        if (down)
        {
            if (st.top()->left)
                st.push(st.top()->left);
            else
                down = false;
        }
        else
        {
            temp = st.top();
            cout << temp->value << endl;
            st.pop();
            if (temp->right)
            {
                st.push(temp->right);
                down = true;
            }
        }
    }
}

MyTree *createNode(int value)
{
    MyTree *newNode = new MyTree;
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

MyTree *insertNode(MyTree *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main()
{
    MyTree *root = createNode(23);
    root = insertNode(root, 24);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    root = insertNode(root, 19);

    inOrderTraverse(root);
    return 0;
}