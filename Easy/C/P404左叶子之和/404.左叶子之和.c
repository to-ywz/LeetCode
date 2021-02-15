/*
 * @lc app=leetcode.cn id=404 lang=c
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode *root)
{
    if (NULL == root)
        return 0;
    return sumOfLeftLeaves(root->left) 
        + sumOfLeftLeaves(root->right) 
        + (root->left != NULL && root->left->left == NULL && root->left->right == NULL ? root->left->val : 0);
}

// @lc code=end
