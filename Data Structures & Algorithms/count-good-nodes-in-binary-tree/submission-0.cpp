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
    int isGood(TreeNode* root , int max){
        if(!root)
            return 0;
        if(root->val >= max){
            max = root->val;
            return (1+ isGood(root->left , max) 
                        + isGood(root->right , max));
        }
        return (isGood(root->left , max) 
                        + isGood(root->right , max));
    }

    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int max = root->val;
        return 1 + isGood(root->left , max) 
                    + isGood(root->right , max);
    }
};
