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
    int depth(TreeNode* c,int d){
        if(!c) return d;
        int x =  depth(c->left,d + 1);
        int y =  depth(c->right,d + 1);
        return max(x,y);
    }
    int maxDepth(TreeNode* root) {
        return depth(root,0);
    }
};
