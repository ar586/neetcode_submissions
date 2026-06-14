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
    TreeNode* finder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        if (root->val > min(p->val, q->val) && root->val < max(p->val, q->val)) {
            return root;
        }
        if (root->val > p->val && root->val > q->val) {
            return finder(root->left, p, q);
        } else {
            return finder(root->right, p, q);
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return finder(root, p, q);
    }
};
