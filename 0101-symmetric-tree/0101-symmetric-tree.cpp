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
    bool fnc(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL)return true;
        if(left==NULL || right==NULL)return false;
        return fnc(left->left,right->right)&& fnc(left->right,right->left) && (left->val==right->val);
    }
    bool isSymmetric(TreeNode* root) {
        return fnc(root->left,root->right);
    }
};