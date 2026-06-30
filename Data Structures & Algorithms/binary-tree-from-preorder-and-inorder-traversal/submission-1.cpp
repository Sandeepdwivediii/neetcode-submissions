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
    unordered_map<int,int> mp;
    TreeNode* solve(int& idx , int start , int end , vector<int>& preorder){
        if(start > end) return nullptr;

        int root = preorder[idx];
        idx++;
        TreeNode* node = new TreeNode(root);
        int i = mp[root];
        node->left = solve(idx , start , i-1 , preorder);
        node->right = solve(idx , i+1 , end , preorder);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return solve(idx,0,inorder.size()-1,preorder);
    }
};
