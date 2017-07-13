#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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

struct Result {
    Node *node;
    bool isAncestor;
    Result(Node *node,bool isAncestor) {
        this->node = node;
        this->isAncestor = isAncestor;
    }
};
Result* ancestorHelper(Node *root,Node *p,Node *q);

Node* commonAncestor(Node *root,Node *p,Node *q) {
    Result *rx = ancestorHelper(root,p,q);
    if(rx->isAncestor) return rx->node;
    return NULL;
}

Result* ancestorHelper(Node *root,Node *p,Node *q) {
    if(root==NULL) return new Result(NULL,false);
    if(root == p && root == q) return new Result(root,true);

    Result *rx = ancestorHelper(root->left,p,q);
    if(rx->isAncestor) return rx;
    Result *ry = ancestorHelper(root->right,p,q);
    if(ry->isAncestor) return ry;

    if(rx->node != NULL && ry->node != NULL) {
        return new Result(root,true);
    } else if(root==p || root == q) {
        bool isAnc = rx->node != NULL || ry->node != NULL;
        return new Result(root,isAnc);
    } else {
        return new Result(rx->node != NULL ? rx->node : ry->node,false);
    }
}

int main() {

    Node *root = new Node('z');
    Node *q = root->left = new Node('x');
    root->left->left = new Node('a');
    Node *p =  root->left->left->right = new Node('c');
    root->left->right = new Node('b');
    root->right = new Node('e');
    root->right->right = new Node('k');

    Node *anc = commonAncestor(root,p,q);
    printf("%c\n",anc->val);
}
