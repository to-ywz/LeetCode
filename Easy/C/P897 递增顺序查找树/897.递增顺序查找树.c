/*
 * @lc app=leetcode.cn id=897 lang=c
 *
 * [897] 递增顺序查找树
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
#define MAXSIZE 1000
typedef struct
{
    struct TreeNode *floor[MAXSIZE];
    int StackTop;
} Stack;
struct TreeNode *inorderTraversal(struct TreeNode *root, int *returnSize);

struct TreeNode *increasingBST(struct TreeNode *root)
{
    int height = 0;
    struct TreeNode *ans = root;
    struct TreeNode *Array = inorderTraversal(ans, &height);
    for (int i = 0; i < height - 1; i++)
    {
        Array[i].left = NULL;
        Array[i].right = &Array[i + 1];
    }
    Array[height - 1].left = Array[height - 1].right = NULL;
    return Array;
}

struct TreeNode *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    if (NULL == root)
    {
        *returnSize = 0;
        return NULL;
    }

    int ResIndex = 0;
    struct TreeNode *inorderArray = (struct TreeNode *)malloc(sizeof(struct TreeNode) * MAXSIZE);
    Stack TreeStack;
    TreeStack.StackTop = 0;

    while (NULL != root || 0 != TreeStack.StackTop)
    {
        while (NULL != root)
        {
            TreeStack.floor[(TreeStack.StackTop)++] = root;
            root = root->left;
        }
        if (0 != TreeStack.StackTop)
        {
            root = TreeStack.floor[--(TreeStack.StackTop)];
            inorderArray[ResIndex++] = *root;
            root = root->right;
        }
    }
    *returnSize = ResIndex;
    return inorderArray;
}
// @lc code=end
