class Solution {
public:
    
    TreeNode* buildBST(vector<int> preorder, int *preorderIdx,int n, int key, int min, int max){
        
        if(*preorderIdx>n){
            return NULL;
        }
        TreeNode* root=NULL;
        if(key>min && key<max){
            root = new TreeNode(key);
            *preorderIdx = *preorderIdx+1;
            
            if(*preorderIdx<n){
                root->left = buildBST(preorder, preorderIdx, n , preorder[*preorderIdx], min, key);
            }
            if(*preorderIdx<n){
                root->right = buildBST(preorder, preorderIdx, n, preorder[*preorderIdx], key, max);
            }
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    
        int preorderIdx = 0;
        int key = preorder[0];
        int n = preorder.size();
        TreeNode* root = buildBST(preorder, &preorderIdx, n, key, INT_MIN, INT_MAX);
        return root;
    }
};
