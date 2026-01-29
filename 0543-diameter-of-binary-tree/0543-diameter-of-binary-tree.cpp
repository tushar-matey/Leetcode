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

    int max_=INT_MIN;
    int height(TreeNode* r){
        if(!r){
            return 0;
        }
        int right=height(r->right);
        int left=height(r->left);
        max_=max(max_,right+left);
        return max(right,left)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return max_;
    }
};