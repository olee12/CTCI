#include <bits/stdc++.h>
using namespace std;
const int maxn = 0;
struct Node {
    int val;
    int subTreeSize;
    Node *left;
    Node *right;
    Node(int val) {
        this->val = val;
        this->left = this->right = NULL;
        subTreeSize = 0;
    }
    Node() {
    }
};



int calculateSubTreeSize(Node *root) {
    if(root==NULL) return 0;
    root->subTreeSize+= calculateSubTreeSize(root->left);
    root->subTreeSize+= calculateSubTreeSize(root->right);
    return root->subTreeSize;
}

int flag = 0;

Node *found;
int totsize = 0;
int findSubTree(Node *root,Node *ptr) {

    if(root==NULL && ptr==NULL) return 1;
    if(root==NULL || ptr==NULL) return 0;

    if(root->subTreeSize==ptr->subTreeSize && root->val == ptr->val) {
        if(findSubTree(root->left,ptr->left) && findSubTree(root->right,ptr->right)) {
            if(totsize==ptr->subTreeSize) {
                flag = 1;
                found = root;
            }
            return 1;
        }else return 0;
    } else {
        return findSubTree(root->left,ptr) ||
               findSubTree(root->right,ptr);
    }

}
void preOrder(Node *root) {
    if(root==NULL) return;
    printf("%c ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
    Node *root = new Node('z');
    root->left = new Node('x');
    root->left->left = new Node('a');
    root->left->left->right = new Node('c');
    root->left->right = new Node('b');
    root->right = new Node('e');
    root->right->right = new Node('k');

    Node *ptr = new Node('x');
    ptr->left = new Node('a');
    ptr->left->right = new Node('c');
    ptr->right = new Node('b');
    calculateSubTreeSize(root);
    calculateSubTreeSize(ptr);
    printf("Subsum : %d %d\n",root->subTreeSize,ptr->subTreeSize);
    printf("Found : %d\n",findSubTree(root,ptr));
    preOrder(found);
}
