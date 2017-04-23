#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node{
    int key;
    node *left;
    node *right;
    node(){}
    node(int key){
        this->key = key;
        this->left = this->right = NULL;
    }
    static void inorder(node* root);
    static node* minValueNode(node *root);
    static node* insert(node* root,int key);
    static node* search(node* root,int key);
    static node* deleteNode(node* root,int key);


};

void node::inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

node* node::minValueNode(node *root) {
    node *current = root;
    while(current->left != NULL)
        current = current->left;
    return current;
}

node* node::insert(node* root,int key){
    if(root==NULL) return new node(key);
    if(key < root->key)
        root->left = insert(root->left,key);
    else if(key > root->key)
        root->right = insert(root->right,key);
    return root;
}

node* node::search(node* root,int key){
    if(root==NULL || key == root->key) return root;

    if(key < root->key) return search(root->left,key);
    else if(key > root->key) return search(root->right,key);
}

node* node::deleteNode(node* root,int key){
    if(root==NULL) return root;

    if(key < root->key)
        root->left = deleteNode(root->left,key);
    else if(key > root->key)
        root->right = deleteNode(root->right,key);
    else{
        if(root->left == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }else if(root->right==NULL){
            node *tmp = root->left;
            delete root;
            return tmp;
        }

        node *tmp = minValueNode(root->right);
        root->key = tmp->key;
        root->right = deleteNode(root->right,tmp->key);

    }
    return root;
}

int main(){
    node *root = NULL;
    root = node::insert(root,51);
    root = node::insert(root,20);
    root = node::insert(root,30);
    root = node::insert(root,10);
    root = node::insert(root,12);
    root = node::insert(root,15);
    root = node::insert(root,57);
    root = node::insert(root,60);
    root = node::insert(root,6);
    root = node::insert(root,3);
    root = node::insert(root,11);
    root = node::insert(root,14);
    root = node::insert(root,34);

    node::inorder(root);
    printf("\n");
    root = node::deleteNode(root,20);
    node::inorder(root);
    printf("\n");
    root = node::deleteNode(root,51);
    node::inorder(root);
    printf("\n");

    node *res = node::search(root,15);
    if(res!=NULL) printf("Found : %d\n",res->key);
    else printf("Not Found\n");
    res = node::search(root,51);
    if(res!=NULL) printf("Found : %d\n",res->key);
    else printf("Not Found\n");
    return 0;
}
