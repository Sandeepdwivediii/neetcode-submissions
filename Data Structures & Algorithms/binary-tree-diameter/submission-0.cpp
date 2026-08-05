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
    int ans;
    int solve(TreeNode* root , int results){
        if(root== nullptr) return 0;

        int left = solve(root->left , results);
        int right = solve(root->right , results);

        ans = max(ans , left+right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         ans = 0 ;
        if(!root) return ans;
        solve(root , 0);
        return ans;
    }
};
