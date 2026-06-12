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
    
    int checker(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lefty=checker(root->left);
        int righty=checker(root->right);
        if(lefty==-1 || righty==-1){
            return -1;
        }
        if (abs(lefty - righty) > 1) {
            return -1;
        }
        return 1+max(lefty,righty);
    }
    bool isBalanced(TreeNode* root) {
        int ans=checker(root);
        if(ans==-1) return false;
        return true;
    }
};
