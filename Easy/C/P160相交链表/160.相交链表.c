/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (!(headA && headB))
        return NULL;
    struct ListNode *tp1 = headA, *tp2 = headB;

    while (tp1 != tp2)
    {
        tp1 = tp1 ? tp1->next : headB;
        tp2 = tp2 ? tp2->next : headA;
    }
    return tp1;
}
// @lc code=end
