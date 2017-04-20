#include <bits/stdc++.h>
using namespace std;

int findIndex(char *str,char ch,int start,int end);
struct Node {
    int val;
    Node *left;
    Node *right;
};

Node* newNode(int val) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->left = tmp->right = NULL;
}

Node *buildTree(char *inT,char *preT,int &preIndex,int start,int end) {

    if(start > end) return NULL;
    Node *tNode = newNode(preT[preIndex++]);
    if(start==end) return tNode;

    int posInInT = findIndex(inT,tNode->val,start,end);

    tNode->left = buildTree(inT,preT,preIndex,start,posInInT-1);
    tNode->right = buildTree(inT,preT,preIndex,posInInT+1,end);

    return tNode;

}


int findIndex(char *str,char ch,int start,int end) {
    for(int i = start; i<=end; i++) {
        if(str[i]==ch) return i;
    }
    return -1;
}

void preOrder(Node *root) {
    if(root==NULL) return;
    printf("%c ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}


int main() {
    char inT[100],preT[100];

    while(scanf("%s %s",inT,preT)==2) {
        int preIndex = 0;
        Node *root = buildTree(inT,preT,preIndex,0,strlen(inT)-1);
        printf("pre order of new tree : ");
        preOrder(root);
        printf("\n");
    }
    return 0;
}
