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
    bool sameTree(TreeNode* root, TreeNode* sub){
        if(!root && ! sub)
            return 1;
        if(!root || !sub)
            return 0;
        if(root->val != sub->val){
            return 0;
        }
        return sameTree(root->left , sub->left) 
                && sameTree(root->right , sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!sub)
            return 1;
        if(!root)
            return 0;

        if(sameTree(root , sub))
            return 1;

        return (isSubtree(root->left, sub) 
                    || isSubtree(root->right, sub));
    }
};
