/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return 0;
        if (root == p && root == q) {
            return root;
        }
        if (root == p || root == q)
            return root;

        TreeNode* right = solve(root->right, p, q);
        TreeNode* left = solve(root->left, p, q);
        if (right && left) {
            return root;
        }
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
    return    solve(root, p, q);
        }
};