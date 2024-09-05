#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Ans{
    int side;
    int maxValue;
    Ans(int s, int m):side(s),maxValue(m){}
};
Ans calcDia(TreeNode* root){
    if(root == NULL) return  Ans(0,0);
    Ans lt = calcDia(root->left);
    Ans rt = calcDia(root->right);
    return Ans(max(lt.side+1,rt.side+1),max(lt.side+rt.side+1,max(lt.maxValue,rt.maxValue)));
}

int diameterOfBinaryTree(TreeNode* root) {
    return max(0,calcDia(root).maxValue-1);    
}

int calcDiaPtr(TreeNode * root, int * maxValue){
    if(root == NULL) return  Ans(0,0);
    int lt = calcDia(root->left);
    int rt = calcDia(root->right);
    *maxValue = max(lt.side+rt.side+1,max(lt.maxValue,rt.maxValue));
    return max(lt.side+1,rt.side+1);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(5);
    // root->right->left->left = new TreeNode(7);
    // root->right->left->right = new TreeNode(11);
    // root->right->right->right = new TreeNode(15);
    cout << diameterOfBinaryTree(root);
    return 0;
}