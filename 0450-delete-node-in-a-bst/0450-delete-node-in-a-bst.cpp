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

    TreeNode* succeser(TreeNode* r){
        while(r->left){
            r=r->left;
        }
        return r;
    }

    void delete_(TreeNode* &root,int val){
        if(!root){
            return ;
        }
        if(root->val==val){
            TreeNode* &r=root;
            if(r->left && !r->right){
                r=r->left;
                return;
            }
            else if(!r->left && r->right){
                
                r=r->right;
                
                return;
            }
            else if(!r->left && !r->right){
                root=nullptr;
                return;
            }
            else{
                TreeNode* succ=succeser(r->right);
                r->val=succ->val;
                delete_(r->right,succ->val);
            }
            
            return;
            
        }
        if(root->val>val && root->left){
            if(root->left->val==val){
                TreeNode* &r=root->left;
                if(r->val == val){
                    if(r->left && !r->right){
                        r=r->left;
                        return;
                    }
                    else if(!r->left && r->right){
                        r=r->right;
                        return;
                    }
                    else if(!r->left && !r->right){
                        root->left=nullptr;
                        return;
                    }
                    else{
                        TreeNode* succ=succeser(r->right);
                        r->val=succ->val;
                        delete_(r->right,succ->val);
                    }
                }
                return;
            }
            else{
                delete_(root->left,val);
            }
        }
        if(root->val<val && root->right){
            if(root->right->val==val){
                TreeNode* &r=root->right;
                if(r->val == val){
                    if(r->left && !r->right){
                        r=r->left;
                        return;
                    }
                    else if(!r->left && r->right){
                        r=r->right;
                        return;
                    }
                    else if(!r->left && !r->right){
                        root->right=nullptr;
                        return;
                    }
                    else{
                        TreeNode* succ=succeser(r->right);
                        r->val=succ->val;
                        delete_(r->right,succ->val);
                    }
                }
                return;
            }
            else{
                delete_(root->right,val);
            }
        }
        


    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        delete_(root,key);
        return root;
    }
};