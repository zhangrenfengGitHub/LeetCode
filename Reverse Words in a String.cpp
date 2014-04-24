/*
题目描述：
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

/*
1) 单词的组成中没有空格字符;
2) 输入字符串中可能包含有前置和后置空格,但是反转字符串不需要前置和后置空格
3) 两个单词之间可能包含有多个空格，但是反转字符串中只用一个空格代替
*/

/*
在LeetCode中提交代码时，只需提交相应的函数代码即可
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

void reverseWords(string &s)                    //函数reverseWords实现对字符串s中单词的反转
{
    int i, j, k, len, begin, end;
    string words, reverseStrings;

    len = s.length();
    for( begin = 0; s[begin] == ' '; )           //去除前置空格
        begin++;
    for( end = len - 1; s[end] == ' '; )         //去除后置空格
        end--;

    words = reverseStrings = "";
    for( i = end; i >= begin; )                  //扫描字符串
    {
        if( s[i] != ' ')                         //不是空格字符
        {
            j = i;
            while( (s[j] != ' ') && (j >= begin))
                j--;
            for( k = j + 1; k <= i; k++)
                words += s[k];
            i = j;
        }
        else
        {
            reverseStrings += words;
            reverseStrings += ' ';              //单词之间添加空格
            words = "";
            while( s[i] == ' ')                 //去除连续空格
                i--;
        }
    }
    reverseStrings += words;                    //最后一个字符串

    s = reverseStrings;
}

int main()
{
    string str;

    while( getline(cin, str) )
    {
        reverseWords(str);                          //反转单词
        cout<<str<<endl;
    }

    return 0;
}

