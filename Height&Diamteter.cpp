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

int Diameter(Node* root, int *height){
    if(root==NULL){
        *height = 0;
        return 0;
    }
    
    int lh =0, rh=0;
    
    int lDiameter = Diameter(root->left, &lh);
    int rDiameter = Diameter(root->right, &rh);
    
    int currDiameter = lh+rh+1;
    *height = max(lh, rh) +1;
    return max(currDiameter, max(lDiameter, rDiameter));
    
}

int height_bt(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int lHeight = height_bt(root->left);
    int rHeight = height_bt(root->right);
    
    return max(lHeight, rHeight)+1;
    
}




main(){
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<Diameter(root, &height)<<endl;
    cout<<height_bt(root)<<endl;
    
}
