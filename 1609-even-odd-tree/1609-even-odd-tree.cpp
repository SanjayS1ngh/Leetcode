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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool inc=false;
        while(!q.empty()){
            inc=!inc;
            int n=q.size();
            int prev1=INT_MAX;
            int prev2=0;
            while(n--){
                TreeNode*node=q.front();
                q.pop();
                if(inc==true){
                    if(node->val<=prev2||(node->val)%2==0)return false;
                    prev2=node->val;
                }
                if(inc==false){
                    if(node->val>=prev1||(node->val)%2!=0)return false;
                    prev1=node->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return true;
    }
};