/*
题目描述:
Sort a linked list using insertion sort.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
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
    ListNode *insertionSortList(ListNode *head)
    {
        if( !head || !head->next)                                   //为空或只有一个元素
            return head;

        ListNode *current, *pos;

        current = head->next;
        while( current)
        {
            pos = head;                                             //节点pos记录current节点前面小于current节点值的节点
            while( (pos->val <= current->val) && (pos != current))  //查找当前节点前面大于当前节点的节点
                pos = pos->next;

            if( pos != current)                                     //即前面存在大于当前节点的节点
            {
                int currentNum = current->val;                      //当前值
                int frontNum;                                       //前面值

                while( pos != current)                              //只需交换值即可
                {
                    frontNum = pos->val;                            //保存节点pos的值
                    pos->val = currentNum;                          //将current节点值付给pos节点
                    currentNum = frontNum;
                    pos = pos->next;
                }
                current->val = currentNum;
            }
            current = current->next;
        }
        return head;
    }
};

int main()
{
    int n, num;
    ListNode *head, *node, *tmp, *result;

    while( scanf("%d", &n) != EOF)
    {
        head = NULL;
        while( n--)                                                     //使用尾插法建立链表
        {
            scanf("%d", &num);

            node = (ListNode *)malloc(sizeof(ListNode));
            node->val = num;
            if( head == NULL)                                          //指定头结点
            {
                head = node;
                tmp = head;
            }
            else
            {
                tmp->next = node;
                tmp = node;
            }
            tmp->next = NULL;
        }

        class Solution solution;
        result = solution.insertionSortList(head);
        while( result)
        {
            printf("%d ", result->val);
            result = result->next;
        }
        printf("\n");
    }
    return 0;
}












