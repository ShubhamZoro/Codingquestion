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
    int inorder_search(vector<int>&inorder,int ele){
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode*build(vector<int>& preorder, vector<int>& inorder,int s,int n,int &k,int e){
        if(s>e||k>=n){
            return NULL;
        }
        int ele=preorder[k++];
        int i=inorder_search(inorder,ele);
        TreeNode*tree=new TreeNode(ele);
        tree->left=build(preorder,inorder,s,n,k,i-1);
        tree->right=build(preorder,inorder,i+1,n,k,e);
        return tree;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        int n=inorder.size();
        int k=0;
        TreeNode*head;
        head=build(preorder,inorder,i,n,k,n-1);
        return head;

    }
};
