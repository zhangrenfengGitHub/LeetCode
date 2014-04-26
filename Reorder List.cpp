/*
题目描述：
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/*
假设数组a[n],即a[0],a[1],...,a[n-2],a[n-1];
则按题意应该生成：a[0],a[n-1],a[1],a[n-2],...,a[i],a[n-1-i],...修改next指针即可得
1) 如果元素个数为偶数，即上图所示:i+1=n-1-i,此时令a[n-1-i]->next=NULL
2) 如果元素个数为奇数，令a[n/2]->next=NULL
*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if( head == NULL)
            return;

        vector<ListNode *> listNodes;
        ListNode *current = head;
        while( current)
        {
            listNodes.push_back(current);
            current = current->next;
        }

        int number = listNodes.size();
        for( int i = 0; i < number / 2; i++)
        {
            int nextPos = number - 1 - i;                     //元素a[i]的下一个元素的小标

            if( i < nextPos)
            {
                listNodes[i]->next = listNodes[nextPos];

                if( (i + 1) < nextPos)                        //判断元素个数是否为偶数
                    listNodes[nextPos]->next = listNodes[i + 1];
                else
                    listNodes[nextPos]->next = NULL;          //元素个数为偶数
            }

        }

        if( number % 2 == 1)                                   //元素个数为偶数
            listNodes[number / 2]->next = NULL;
    }
};

int main()
{
    int n, num;
    ListNode *head, *node, *tmp;

    while( scanf("%d", &n) != EOF)
    {
        head = NULL;
        while( n--)                                             //采用尾插法建立链表
        {
            scanf("%d", &num);

            node = (ListNode *)malloc(sizeof(ListNode));
            node->val = num;
            if( head == NULL)                                   //指定头结点
            {
                head = node;
                tmp = head;
            }
            else
            {
                tmp->next = node;
                tmp = node;
            }
        }
        tmp->next = NULL;

        class Solution solution;
        solution.reorderList(head);
        while( head)
        {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}













