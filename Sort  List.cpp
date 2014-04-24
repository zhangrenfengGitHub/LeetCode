/*
题目描述：
Sort a linked list in O(n log n) time using constant space complexity.
*/

/*
对链表实现时间复杂度为O(n log n)的排序算法
使用归并排序的思想来进行排序，将链表分为有序的两部分，然后对齐进行合并
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
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
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

    ListNode *mergeSort(ListNode *head)                         //对链表进行归并排序
    {
        if( !head || !head->next)                               //为空或只有一个元素
            return head;

        ListNode *pre = NULL, *current = head, *last = head;
        while( last && (last->next != NULL))              	//将链表分为两部分
        {
            last = last->next->next;                            //每次前进两个节点，快速将链表分成两部分
            pre = current;
            current = current->next;
        }
        pre->next = NULL;

        ListNode *leftSort = mergeSort(head);                   //分别对左右部分进行递归排序
        ListNode *rightSort = mergeSort(current);

        return merge(leftSort, rightSort);                      //将两排序号的链表合并
   }

   ListNode *merge(ListNode *left, ListNode *right)
   {
       ListNode *result, *tmp;
       tmp = (ListNode *)malloc(sizeof(ListNode));
       result = tmp;
       while( left && right)
       {
           if( left->val <= right->val)
           {
               result->next = left;
               left = left->next;
           }
           else
           {
           		result->next = right;
           		right = right->next;
           }
           result = result->next;
       }
       if( left)
            result->next = left;
        else
        	result->next = right;

        result = tmp->next;
        tmp->next = NULL;
        free(tmp);

       return result;
   }
};

int main()
{
    int i, n, num;
    ListNode *head, *node, *tmp, *result;

    while( scanf("%d", &n) != EOF)
    {
    	head = NULL;
    	while( n--)												//利用尾插法建立链表
    	{
    		scanf("%d", &num);

    		node = (ListNode *)malloc(sizeof(ListNode));
    		node->val = num;
    		if( head == NULL)									//指定头结点
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
	   result = solution.sortList(head);
	   while( result)
	   {
	   		printf("%d ", result->val);
	   		result = result->next;
	   }
	   printf("\n");
    }
    return 0;
}













