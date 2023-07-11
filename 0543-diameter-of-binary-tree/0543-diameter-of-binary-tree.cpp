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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
       int res = 0;
        recursion(root, res);
        return res;
    }
    int recursion(TreeNode* root, int &res){
        
        if(!root)return 0;
        
        int left = recursion(root->left, res);
        int right = recursion(root->right, res);
        res = max(res, left+right);
        
        return 1 + max(left, right);
    }
};