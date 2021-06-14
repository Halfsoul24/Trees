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

int countNodes(Node* root){
    
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    
    while(!q.empty()){
        Node* node = q.front();  
       
        q.pop();
        if(node!=NULL){
            count++;
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        else if(!q.empty()){
            q.push(NULL);
        }
        
        return count;
        
    }   
}
int sumAtK(Node* root, int K){
    int sum=0;
    if(root==NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int k=0;
    int count=0;
    
    while(!q.empty()){
        Node* node = q.front();  
       
        q.pop();
        if(node!=NULL){
            if(k==K) sum+=node->data;
            count++;
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        
        else if(!q.empty()){
            q.push(NULL);
            k++;
        }
        
        
    }
    
    cout<<endl<<count<<endl;
    return sum;
}

main(){
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int sum = sumAtK(root,2);
    // int count = countNodes(root);
    cout<<sum<<endl;
}
    
