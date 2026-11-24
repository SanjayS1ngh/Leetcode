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


    void solve(TreeNode*root,vector<int>&count,int &ans){
        if(root==NULL)return;
        count[root->val]++;
        if(root->left==NULL&&root->right==NULL){
            int odd=0;
            for(int i=1;i<10;i++){
                if(count[i]%2!=0){
                    odd++;
                    if(odd>1)break;
                }
            }
            if(odd<=1)ans++;
        }
        solve(root->left,count,ans);
        solve(root->right,count,ans);
        count[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int>count(10,0);
        solve(root,count,ans);
        return ans;
    }
};