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
    TreeNode* finder(TreeNode* root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deletion(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) {

            if (!root->left && !root->right) {
                return nullptr;
            }

            if (!root->left) {
                return root->right;
            }

            if (!root->right) {
                return root->left;
            }

            TreeNode* pred = finder(root);
            root->val = pred->val;
            root->left = deletion(root->left, pred->val);
        }
        else if (key < root->val) {
            root->left = deletion(root->left, key);
        }
        else {
            root->right = deletion(root->right, key);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletion(root, key);
    }
};;