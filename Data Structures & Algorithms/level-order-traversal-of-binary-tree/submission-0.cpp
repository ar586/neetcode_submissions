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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> qt;
        qt.push(root);
        vector<vector<int>> ans;
        while (!qt.empty()) {
            int n = qt.size();
            vector<int> temp1;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = qt.front();
                qt.pop();
                temp1.push_back(temp->val);
                if (temp->left) qt.push(temp->left);
                if (temp->right) qt.push(temp->right);
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};
