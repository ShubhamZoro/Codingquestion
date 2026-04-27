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
    void  Inorder(TreeNode*root,vector<int>&r){
        if(root==NULL){
            return ;
        }
        Inorder(root->left,r);
        r.push_back(root->val);
        Inorder(root->right,r);
       

    }
    bool isValidBST(TreeNode* root) {
        vector<int>r;
        Inorder(root,r);
        int n=r.size();
        for(int i=0;i<n-1;i++){
            if(r[i]>=r[i+1]){
                return false;
            }
        }
        return true;
    }
};
