#include <bits/stdc++.h>
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


int maxSum(Node *root,int &ret)
{
    if(root==NULL) return 0;

    int lft = maxSum(root->left,ret);
    int rght = maxSum(root->right,ret);

    int path = max(max(lft,rght) + root->val,root->val);
    ret = max(ret,path);
    ret = max(ret,lft+rght+root->val);
    return path;
}

int findMaxSum(Node *root){
    int ret = INT_MIN;
    maxSum(root,ret);
    return ret;
}


int main()
{
     Node *root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
    cout << "Max path sum is " << findMaxSum(root);
}
