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


    void solve(TreeNode*root,int count,int &ans){
        if(root==NULL)return;
        count=count^(1<<root->val);
        if(root->left==NULL&&root->right==NULL){
            if((count & count-1)==0)ans++;
            
        }
        solve(root->left,count,ans);
        solve(root->right,count,ans);
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        // vector<int>count(10,0);
        solve(root,0,ans);
        return ans;
    }
};