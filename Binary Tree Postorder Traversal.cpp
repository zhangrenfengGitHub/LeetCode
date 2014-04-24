/*
题目描述:
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
即不使用递归来实现二叉树的后续遍历
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

 struct TreeNode
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> value;                                              //存储二叉树的后序遍历值
        if( root == NULL)
            return value;

        stack<TreeNode *> postOrder;
        postOrder.push(root);

        TreeNode *topNode = NULL;
        while( !postOrder.empty())
        {
            topNode = postOrder.top();                                  //取栈顶元素
            if( (topNode->left == NULL) && (topNode->right == NULL))    //即为根节点
            {
                value.push_back(topNode->val);                          //加入后序序列
                postOrder.pop();                                        //遍历完后删除
            }
            else                                                        //即该节点不为根节点
            {
                if( topNode->right != NULL)                             //存在右子树
                {
                    postOrder.push(topNode->right);
                    topNode->right = NULL;
                }
                if( topNode->left != NULL)                              //后遍历左子树(栈后进先出)
                {
                    postOrder.push(topNode->left);
                    topNode->left = NULL;                               //将其置为叶子节点
                }
            }
        }

        return value;
    }

    vector<int> preorderTraversal(TreeNode *root)                      //求二叉树的先序遍历
    {
        vector<int> value;
        if( root == NULL)
            return value;

        stack<TreeNode *> preOrder;                                     //线序序列

        TreeNode *topNode = root;
        while( topNode || !preOrder.empty())
        {
            while( topNode )                                            //根节点--->左子树--->右子树
            {
                value.push_back(topNode->val);
                preOrder.push(topNode);
                topNode = topNode->left;
            }
            if( !preOrder.empty())
            {
                topNode = preOrder.top();
                preOrder.pop();
                topNode = topNode->right;
            }
        }
        return value;
    }

    vector<int> inorderTraversal(TreeNode *root)                      //求二叉树的中序遍历
    {
        vector<int> value;
        if( root == NULL)
            return value;

        stack<TreeNode *> inOrder;
        TreeNode *topNode = root;
        while( topNode || !inOrder.empty())
        {
            while( topNode)                                             //一直遍历左子树
            {
                inOrder.push(topNode);
                topNode = topNode->left;
            }
            if( !inOrder.empty())
            {
                topNode = inOrder.top();
                inOrder.pop();
                value.push_back(topNode->val);
                topNode = topNode->right;
            }
        }
        return value;
    }

    void creatBinTree(char *s,TreeNode *&root)                      //创建二叉树，s为形如A(B,C(D,E))形式的字符串
    {
        int i;
        bool isRight=false;

        stack<TreeNode *> s1;                                       //存放结点
        stack<char> s2;                                             //存放分隔符

        TreeNode *p,*temp;
        root->val = s[0];
        root->left = root->right = NULL;
        s1.push(root);

        i=1;
        while( i < strlen(s))
        {
            if( s[i] == '(')
            {
                s2.push(s[i]);
                isRight=false;
            }
            else if( s[i] == ',')
            {
                isRight=true;
            }
            else if( s[i] == ')')
            {
                s1.pop();
                s2.pop();
            }
            else if( isalpha(s[i]))
            {
                p = (TreeNode *)malloc(sizeof(TreeNode));
                p->val = s[i];
                p->left = p->right = NULL;

                temp = s1.top();
                if( isRight == true)
                    temp->right = p;
                else
                    temp->left = p;

                if( s[i + 1] == '(')
                    s1.push(p);
            }

            i++;
        }
    }
};

int main()
{
    char ss[505];
    while(scanf("%s", ss) != EOF)
    {
        class Solution solution;
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        solution.creatBinTree(ss, root);                            //创建二叉树

        vector<int> preResult, inResult, postResult;
        preResult = solution.preorderTraversal(root);
        inResult = solution.inorderTraversal(root);
        postResult = solution.postorderTraversal(root);
        printf("中序遍历序列为：");
        for( int i = 0; i < inResult.size(); i++)
            printf("%c ", inResult[i]);
        printf("\n");
    }
    return 0;
}











