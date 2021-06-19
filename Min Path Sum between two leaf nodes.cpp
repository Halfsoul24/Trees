class Solution {
public:

    int maxSum(Node* root, int &res){
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int l = maxSum(root->left, res);
        int r = maxSum(root->right, res);
        
        
        if(root->left!=NULL && root->right!=NULL){
            res = max(res,l+r+root->data);
            
            return max(l,r) + root->data;
       
        
        }
        
        if(root->left!=NULL){
            return root->data+l;
        }
        if(root->right!=NULL)
            return r+root->data;
        // return temp;
    
    }
    int maxPathSum(Node* root)
    {
        int res=INT_MIN;
        int val = maxSum(root, res);
        // res = res+ root
        if(res==INT_MIN){
            return val;
        }
        return res;
    }
};
