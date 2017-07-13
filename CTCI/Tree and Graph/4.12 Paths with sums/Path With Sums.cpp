#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
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
void incrementMap(map<int,int> &pathCount,int key,int flag);
int countPathsWithSum(Node *root,int targetSum);
int countPathsWithSum(Node *root,int targetSum,int currentSum, map<int,int> &pathCount);
int countPathsWithSum(Node *root,int targetSum)
{
    map<int,int> pathCount;
    return countPathsWithSum(root,targetSum,0,pathCount);

}

int countPathsWithSum(Node *root,int targetSum,int currentSum, map<int,int> &pathCount){
    if(root==NULL) return 0;
    currentSum = currentSum + root->val;
    int totalPaths = pathCount[currentSum - targetSum];
    if(currentSum==targetSum) totalPaths++;
    incrementMap(pathCount,currentSum,1);
    totalPaths+= countPathsWithSum(root->left,targetSum,currentSum,pathCount);
    totalPaths+= countPathsWithSum(root->right,targetSum,currentSum,pathCount);
    incrementMap(pathCount,currentSum,0);
    return totalPaths;

}
void incrementMap(map<int,int> &pathCount,int key,int flag){
    if(flag) pathCount[key]++;
    else {
        pathCount[key]--;
        if(pathCount[key]==0) pathCount.erase(key);
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->left->right = new Node(10);
    root->left->left->right->right = new Node(2);
    root->left->left->left = new Node(0);
    root->left->left->left->left = new Node(10);
    printf("Path Sum : %d\n",countPathsWithSum(root,12));
    return 0;
}
