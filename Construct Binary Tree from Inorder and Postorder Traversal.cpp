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
    int find_sol(vector<int>& inorder,int ele,int n){
        for(int i=0;i<n;i++){
            if(ele==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& postorder, vector<int>& inorder,int s,int e,int &k,int n){
        if(k<0||s>e){
            return NULL;
        }
       
        int element=postorder[k--];
        TreeNode *head=new TreeNode(element);
        int pos=find_sol(inorder,element,n);       
        head->right=build(postorder,inorder,pos+1,e,k,n); 
        head->left=build(postorder,inorder,s,pos-1,k,n);
       
       
        return head;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int s=0,n=inorder.size();
        TreeNode*head;
        int k=n-1;
        head=build(postorder,inorder,s,n-1,k,n);
        return head;
    }
};
