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
    bool ans=false;
    void tree_sum(TreeNode* root,int sum,int t){
        if(root==nullptr){
            return;
        }
        if((sum+root->val)==t && root->right==nullptr && root->left==nullptr){
            ans=true;
        }
        
        tree_sum(root->right,sum+root->val,t);
        tree_sum(root->left,sum+root->val,t);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return ans;
        }
        tree_sum(root,0,targetSum);
        return ans;
    }
};