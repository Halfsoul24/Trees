#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr) return i;
    }
    return -1;
}

Node* BuildTree(int pre[], int inorder[], int start, int end){
    static int idx = 0;
    
    if(start>end){
        return NULL;
    }
    
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    
    
    
    int pos = search(inorder,start,end,curr);
    if(start==end){
        return node;
    }
    
    node->left = BuildTree(pre,inorder,start,pos-1);
    node->right = BuildTree(pre,inorder,pos+1,end);
    
}

void PrintInorder(Node* root){
    if(root==NULL) return ;
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}
main(){
    int pre[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    
    
    Node* root = BuildTree(pre,inorder,0,4);
    PrintInorder(root);
    
}
