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
    TreeNode* it(TreeNode* c){
        if(c->left || c->right){
        TreeNode* temp = c->left;
        c->left = c->right;
        c->right = temp;
        if(c->left) c->left = it(c->left);
        if(c->right) c->right = it(c->right);
        }
        return c;
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* c = root;
        if(c)
        c = it(c);
        return c;
    }
};
