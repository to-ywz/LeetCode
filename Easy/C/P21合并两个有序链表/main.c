#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAMP_NUM 50

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
typedef ListNode *List;

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    return l1;
}

int cmp(const void *a, const void *b) { return (*(int *)a) > (*(int *)b) ? 1 : -1; }

int main(void)
{
    // 修改数组大小自动修改链表长度
    ListNode arr1[1] = {0};
    ListNode arr2[3] = {0};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    // * 生成测试样例
    int randomNums1[SAMP_NUM + 2] = {0};
    int randomNums2[SAMP_NUM + 2] = {0};
    // 确保每次生成的数据不一致
    int seed = (int)time(NULL);
    srand(seed);

    // 获取随机数
    for (int i = 0; i < SAMP_NUM + 2; i++)
    {
        // randomNums1[i] = (rand() % 100) + 100; // 100 ~ 200
        randomNums1[i] = rand();
    }
    for (int i = 0; i < SAMP_NUM + 2; i++)
    {
        randomNums2[i] = rand() % 100 + 100;
        // randomNums2[i] = (rand() % 100) + 100;
    }
    qsort(randomNums1, SAMP_NUM + 2, sizeof(randomNums1[0]), cmp);
    qsort(randomNums2, SAMP_NUM + 2, sizeof(randomNums2[0]), cmp);

    // 打印测试样例
    printf("L1: ");
    for (int i = 0; i < len1; i++)
    {
        printf("%d ", randomNums1[i]);
    }
    printf("\nL2: ");
    for (int i = 0; i < len2; i++)
    {
        printf("%d ", randomNums2[i]);
    }
    putchar('\n');

    List res = 0;
    // * 测试数据

    int rad_arr1 = (rand() % len1 / 2),
        rad_arr2 = (rand() % len2 / 2);
    for (int i = 0; i < len1 - 1; i++)
    {
        arr1[i].val = randomNums1[i + rad_arr1];
        arr1[i].next = arr1 + i + 1;
    }
    arr1[len1 - 1].val = randomNums1[len1 - 1 + rad_arr1];
    arr1[len1 - 1].next = NULL;
    for (int i = 0; i < len2 - 1; i++)
    {
        arr2[i].val = randomNums2[i + rad_arr2];
        arr2[i].next = arr2 + i + 1;
    }
    arr2[len2 - 1].val = randomNums2[len2 - 1 + rad_arr2];
    arr2[len2 - 1].next = NULL;

    List l1 = arr1;
    List l2 = arr2;

    res = mergeTwoLists(l1, l2);

    for (List temp = res; temp; temp = temp->next)
    {
        printf("%s%d", (temp != res ? "->" : ""), temp->val);
    }
    putchar('\n');

    return 0;
}