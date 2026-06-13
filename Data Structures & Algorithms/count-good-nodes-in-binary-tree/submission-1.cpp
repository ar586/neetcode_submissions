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
    void finder(TreeNode* root,int greatest,int &count){
        if(!root){
            return;
        }
        if(root->val>=greatest){
            count++;
        }
        greatest=max(greatest,root->val);
        finder(root->left,greatest,count);
        finder(root->right,greatest,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int greatest=INT_MIN;
        finder(root,greatest,count);
        return count;
    }
};
