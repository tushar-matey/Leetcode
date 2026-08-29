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
     
    int r1(TreeNode* r, unordered_map<TreeNode*,int>&m){
        if(!r){
            return 0;
        }
        if(m.find(r)!=m.end()){
            return m[r];
        }
        int take=r->val;
        int notTake=0;
        if(r->left){
            take+=r1(r->left->left,m)+r1(r->left->right,m);
            notTake+=r1(r->left,m);
        }
        if(r->right){
            take+=r1(r->right->left,m)+r1(r->right->right,m);
            notTake+=r1(r->right,m);
        }
        m[r]=max(take,notTake);
        return max(take,notTake);
    }
    int rob(TreeNode* r) {
        unordered_map<TreeNode*,int>m;
        return r1(r,m);
        // if(!r){
        //     return 0;
        // }
        // int take=r->val;
        // int notTake=0;
        // if(r->left){
        //     take+=rob(r->left->left)+rob(r->left->right);
        //     notTake+=rob(r->left);
        // }
        // if(r->right){
        //     take+=rob(r->right->left)+rob(r->right->right);
        //     notTake+=rob(r->right);
        // }
        // return max(take,notTake);
        
        // while(!q.empty()){
        //     TreeNode* f=q.front();
        //     q.pop();
        //     int c=0;
        //     int p1=0;
        //     int p2=0;
        //     if(f->left){
        //         c=f->left->val;
        //         if(f->left->left && f->left->right){
        //             p1=f->left->left->val+f->val;
        //         }
        //         else if(f->left->left){
        //             p1=f->left->left->val+f->val;
        //         }
        //         else if(f->left->right){
        //             p2=f->left->right->val+f->val;
        //         }
        //     }
        // }

    }
};