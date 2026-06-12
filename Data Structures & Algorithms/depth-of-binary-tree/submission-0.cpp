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
    int maxi(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lefty=maxi(root->left);
        int righty=maxi(root->right);
        return 1+max(lefty,righty);
    }
    int maxDepth(TreeNode* root) {
        return maxi(root);
    }
};
