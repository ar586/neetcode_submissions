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
    int maxisum(TreeNode* root,int &maxi){
        if(!root){
            return 0;
        }
        int leftsum=maxisum(root->left,maxi);
        int rightsum=maxisum(root->right,maxi);

        maxi=max(maxi,root->val+leftsum+rightsum);
        int maxi1=max(root->val+leftsum,root->val+rightsum);
        int maxi2=max(0,root->val);
        return max(maxi1,maxi2);
    }
    int maxPathSum(TreeNode* root) {
      int maxi=INT_MIN;
      maxisum(root,maxi);
      return maxi;
    }
};
