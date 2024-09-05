#include <iostream>
struct Node {
int data;
Node *left, *right;
Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
bool searchTree(Node* root, int target) {
return (root && (root->data == target || (target < root->data ? searchTree(root->left, target) : searchTree(root->right, target))));
}
int main() {
Node* root = new Node(10);
root->left = new Node(7);
root->left->left = new Node(5);
root->left->right = new Node(8);
root->right = new Node(15);
root->right->left = new Node(12);
root->right->right = new Node(18);
int target = 8;
std::cout << (searchTree(root, target) ? "Found" : "Not Found") << std::endl;
return 0;
}