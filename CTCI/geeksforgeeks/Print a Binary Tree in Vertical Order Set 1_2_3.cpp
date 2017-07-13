#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node *left;
    Node *right;
};

Node* newNode(int v){
    Node *node = new Node;
    node->val = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printVir(Node *root,int dept,map<int , vector<int> > *order){
    if(root==NULL) return ;
    (*order)[dept].push_back(root->val);
    printVir(root->left,dept-1,order);
    printVir(root->right,dept+1,order);
}

void printVirLevelOrder(Node *root,map<int , vector<int> > *order){
    if(root==NULL) return ;

    queue< pair<Node *,int> > q;
    q.push(make_pair(root,0));
    while(q.size()){
        pair<Node *,int> tmp = q.front();
        q.pop();
        Node *cur = tmp.first;
        int dept = tmp.second;
        (*order)[dept].push_back(cur->val);
        if(cur->left!=NULL) q.push(make_pair(cur->left,dept-1));
        if(cur->right!=NULL) q.push(make_pair(cur->right,dept+1));

    }

}


int main(){

    map<int,vector<int> > *hash = new map<int, vector<int> >();

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);

    cout << "Vertical order traversal is \n";
    printVir(root,0,hash);
    for(auto it = (*hash).begin();it!=(*hash).end();it++){
        //printf("-- %d --",(*it).first);
        for(int i = 0;i<it->second.size();i++){
            printf("%d ",it->second[i]);
        }
        printf("\n");
    }

    (*hash).clear();
    cout << "Vertical order traversal is \n";
    printVirLevelOrder(root,hash);
    for(auto it = (*hash).begin();it!=(*hash).end();it++){
        //printf("-- %d --",(*it).first);
        for(int i = 0;i<it->second.size();i++){
            printf("%d ",it->second[i]);
        }
        printf("\n");
    }

}
