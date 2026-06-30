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

class n{
    public:
    int sum;
    n* left;
    n* right;
    int leftm;
    int rightm;
    n():sum(0),left(nullptr),right(nullptr),leftm(INT_MIN),rightm(INT_MAX){}
    // n(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int max_;
    void post(TreeNode* root,n* &rn){
        if(!root){
            rn=nullptr;
            return ;
        }
        rn=new n();
        if(root->right){
            rn->right=new n();
            post(root->right,rn->right);
        }
        if(root->left){
            rn->left=new n();
            post(root->left,rn->left);
        }
        if(!root->left && root->right){
            if(rn->right->leftm>root->val){
                rn->sum=rn->right->sum+root->val;
                rn->rightm=rn->right->rightm;
                rn->leftm=root->val;
            }
            
        }
        else if(!root->right && root->left){
            if(rn->left->rightm<root->val){
                rn->sum=rn->left->sum+root->val;
                rn->rightm=root->val;
                rn->leftm=rn->left->leftm;
            }

        }
        else if(!root->right && !root->left){
            rn->sum=root->val;
            rn->rightm=root->val;
            rn->leftm=root->val;
        }
        else{
            if(rn->right->leftm>root->val && rn->left->rightm<root->val){
                rn->sum=rn->right->sum+rn->left->sum+root->val;
                rn->rightm=rn->right->rightm;
                rn->leftm=rn->left->leftm;
            }
        }
        max_=max(max_,rn->sum);
        // cout<<rn->sum<<" "<<root->val<<endl;
    }

    int maxSumBST(TreeNode* root) {
        n* rn=nullptr;
        max_=INT_MIN;
        post(root,rn);
        
        return max_;
    }
};