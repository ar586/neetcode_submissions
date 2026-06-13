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
    int finder(TreeNode* root, int &maxheight) {
        if (!root) return 0;
        int lh = finder(root->left, maxheight);
        int rh = finder(root->right, maxheight);
        maxheight = max(maxheight, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxheight = 0;
        finder(root, maxheight);
        return maxheight;
    }
};