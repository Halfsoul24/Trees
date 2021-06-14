#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(curr == inorder[i]) return i;
    }
    return -1;
}

Node* BuildTree(int post[], int inorder[], int start, int end){
    if(start>end) return NULL;
    
    static int idx = end;
    int val = post[idx];
    Node *curr = new Node(val);
    idx--;
    if(start==end){      //when no left or right subtree present
        return curr;
    }
    int pos = search(inorder,start,end,val);
    curr->right = BuildTree(post,inorder,pos+1,end);
    curr->left = BuildTree(post,inorder,start,pos-1);
    
    return curr;
    
}

void PrintInorder(Node* root){
    
    if(root==NULL){
        return ;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
    
    
    
}

main(){
    int post[]={4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    Node* root = BuildTree(post, inorder,0,4);
    PrintInorder(root);
    
}
