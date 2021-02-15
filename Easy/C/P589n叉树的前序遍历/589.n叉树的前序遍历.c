/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 10240

void travel(struct Node *root, int *res, int *returnSize)
{
    if (root)
    {
        for (int i = 0; i < root->numChildren; i++)
        {
            res[(*returnSize)++] = root->children[i]->val;
            travel(root->children[i], res, returnSize);
        }
    }
}

int *preorder(struct Node *root, int *returnSize)
{
    int *result = (int *)calloc(MAXSIZE, sizeof(int));
    *returnSize = 0;
    if (NULL == root)
        return result;

    result[(*returnSize)++] = root->val;
    travel(root, result, returnSize);
    return result;
}

// @lc code=end
