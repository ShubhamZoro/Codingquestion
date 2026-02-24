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
    void helper(TreeNode*root,long long sum1,vector<long long>&vec){
        if(root==NULL){  
            return;
        }
        sum1=2*sum1+root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            
            vec.push_back(sum1);
            // return ;
        }       
        helper(root->left,sum1,vec);
        helper(root->right,sum1,vec);
    }
    int sumRootToLeaf(TreeNode* root) {
        long long sum1=0;
        vector<long long> vec;
        helper(root,sum1,vec);
        int sum2=0;
        for(auto temp:vec){
            sum2+=temp;
        }
        return sum2;
    }
};
