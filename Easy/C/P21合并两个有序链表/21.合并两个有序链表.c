/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    struct ListNode *rmq_prve = head;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            rmq_prve->next = l1;
            l1 = l1->next;
        }
        else
        {
            rmq_prve->next = l2;
            l2 = l2->next;
        }
        rmq_prve = rmq_prve->next;
    }
    rmq_prve->next = (NULL == l1 ? l2 : l1);
    return head->next;
}
// @lc code=end
