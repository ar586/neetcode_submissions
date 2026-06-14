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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> qt;
        vector<int> ans;
        qt.push(root);
        while (!qt.empty()) {
            int n = qt.size();
            int temp = -1;
            for (int i = 0; i < n; i++) {
                TreeNode* temp1 = qt.front();
                qt.pop();
                if (temp1->left) qt.push(temp1->left);
                if (temp1->right) qt.push(temp1->right);
                temp = temp1->val;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};