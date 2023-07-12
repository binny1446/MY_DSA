/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=INT_MIN;
    int treeSum(TreeNode* root){
        if(root == NULL)return 0;
        
        int ls = max(0,treeSum(root->left));
        int rs = max(0,treeSum(root->right));
        
        res = max(res, ls+rs + root->val);    
        return root->val + max(ls, rs);    
    }
    int maxPathSum(TreeNode* root) {
        treeSum(root);  
        return res;
    }
};