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
    int helper(TreeNode* root,bool &correct){
        if(root==NULL){
            return 0;
        }
        int left=helper(root->left,correct);
        int right=helper(root->right,correct);
        if(abs(left-right)>1){
            correct=false;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool correct=true;
        helper(root,correct);
        return correct;
    }
};
