/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  */

  /*
  求解逆波兰表达式(后缀表达式)的值
  逆波兰表达式的生成算法：
  1) 构造一个运算符栈，此运算符在栈内遵循越往栈顶优先级越高的原则；
  2）读入一个用中缀表示法表示的简单算术表达式，
     为方便起见,认为地在字符串后面加入一个特殊字符“；”，并设其优先级为0；
  3）从左至右扫描该算术表达式的每一个字符，如果该字符是数字，
     则分析到该数字串的结束并将该数字串加入结果字符串，小数点亦算入数字串
  4) 如果该字符是运算符，则按如下操作:
      a> 如果该字符是左括号“（”，则该字符直接压入运算符栈
      b> 如果该字符是右括号“）”，则把运算符栈顶元素弹出直至第一次遇到左括号
      c> 如果该字符是算术运算符且其优先关系高于运算符栈顶的运算符，则将该运算符入栈
      d> 否则，将栈顶的运算符从栈中弹出至结果字符串末尾，
         直至栈顶运算符的优先级低于当前运算符，并将该字符入栈
  5) 重复上述操作（3）-（4）直至扫描完整个简单算术表达式（遇到特殊字符“；”）

  逆波兰表达式求值算法：
  1）循环扫描语法单元的项目。
  2）如果扫描的项目是操作数，则将其压入操作数堆栈，并扫描下一个项目。
  3）如果扫描的项目是一个二元运算符，则对栈的顶上两个操作数执行该运算。
  4）如果扫描的项目是一个一元运算符，则对栈的最顶上操作数执行该运算。
  5）将运算结果重新压入堆栈。
  6）重复步骤2-5，堆栈中即为结果值。
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        if( tokens.empty() )                                //表达式为空
            return 0;

        stack<int> result;                                  //数字栈
        for( int i = 0; i < tokens.size(); i++)
        {
            if( (tokens[i].size() == 1) &&( tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"))
            {
                int secondTerm = result.top();              //取栈顶元素
                result.pop();                               //删除栈顶元素
                int firstTerm = result.top();
                result.pop();

                if( tokens[i] == "+")
                    result.push(firstTerm + secondTerm);    //将运算结果进栈
                else if( tokens[i] == "-")
                    result.push(firstTerm - secondTerm);
                else if( tokens[i] == "*")
                    result.push(firstTerm * secondTerm);
                else
                    result.push(firstTerm / secondTerm);
            }
            else
            {
                int tmp = atoi(tokens[i].c_str());           //const char *c_str();c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同.
                result.push(tmp);
            }
        }
        return result.top();
    }
};

int main()
{
    string str;
    vector<string> expression;

    while( getline(cin, str))
    {
        expression.clear();

        int len = str.length();
        string tmp = "";
        for( int i = 0; i < len; )
        {
            if( str[i] != ' ')
            {
                int j = i;
                while( (str[j] != ' ') && (j < len))
                    j++;
                for( int k = i; k < j; k++)
                    tmp += str[k];
                i = j;
            }
            else
            {
                expression.push_back(tmp);
                tmp = "";
                while( str[i] == ' ')
                    i++;
            }
        }
        expression.push_back(tmp);

        class Solution solution;
        int res = solution.evalRPN(expression);
        printf("%d\n", res);
    }
    return 0;
}















