bool isbalanced(Node *root, int *ht)
{
    if(root==NULL) return true;
    int lh = 0, rh = 0;
    if(isbalanced(root->left,&lh)==false) return false;
    if(isbalanced(root->right,&rh)==false) return false;
    
     *ht = max(lh,rh)+1;
    if(abs(lh - rh)<=1) return true;
    else return false;
    
}

bool isBalanced(Node* root){
    int height = 0;
    int ans = isbalanced(root,&height);
}
