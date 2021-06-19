
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 void leftTraversal(Node* root, vector<int> & v){
     
     if(root==NULL){
         return ;
     }
     
     queue<Node* > q;
     q.push(root);
     
     while(!q.empty()){
         
         int n=q.size();
         for(int i=1; i<=n; i++){
             
             Node* curr = q.front();
             q.pop();
             if(i==1){
                 v.push_back(curr->data);
             }
             
             if(curr->left!=NULL){
                 q.push(curr->left);
             }
             
             if(curr->right!=NULL){
                 q.push(curr->right);
             }
         }
     }
 }
 
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> v;
    leftTraversal(root, v);
    return v;
   // Your code here
}
