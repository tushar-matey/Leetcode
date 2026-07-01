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

    struct custom{
        size_t operator()(const pair<TreeNode*,int>&p)const{
            size_t h1=hash<TreeNode*>{}(p.first);
            size_t h2=hash<int>{}(p.second);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
    
    
    //NEED_RIGHT 1,
    //NEED_LEFT 0,
    //START 2
    unordered_map<pair<TreeNode*,int>,int,custom>m;
    int re(TreeNode* r, int f){
        if(!r){
            return 0;
        }
        if(!r->left && !r->right){
            return 0;
        }
        if(m.find({r,f})!=m.end()){
            return m[{r,f}];
        }
        int path=0;
        if(r->right && (f==1 || f== 2) ){
            path=1+re(r->right,0);
        }
        if(r->left && (f==0 || f== 2)){
            path=max(path,1+re(r->left,1));
        }
        m[{r,f}]=path;
        return path;
    }
    int ans=0;
    // void l(TreeNode* root){
    //     if(!r){
    //         return;
    //     }
    //     if(r->right){
    //         l(root->right);
    //     }
    //     if(r->left){
    //         l(root->left);
    //     }
    //     ans=max(ans,re(root,0));
    //     ans=max(ans,re(root,1));
    // }

    int longestZigZag(TreeNode* root) {
        if(!root){
            return 0;
        }
        return max({re(root,2),longestZigZag(root->right),longestZigZag(root->left)});
    }
};