/*
题目描述：
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/*
给出2维平面上的n个点，找出同在一条直线上的最大点数
使用斜率来判断三个点在不在同一直线上
这里使用map容器实现斜率到点数的映射
*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXPOINTS = 505;

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        map<double, int> gradient;
        int maxNumber = 0;
        int maxSameX = 0;                                       //斜率不存在的最多点数
        for( int i = 0; i < points.size(); i++)
        {
            int sameX = 1;                                      //保存斜率不存在的点
            int samePoint = 1;                                  //保存相同的点
            gradient.clear();
            for( int j = i + 1; j < points.size(); j++)
            {
                if ( (points[i].x == points[j].x) && (points[i].y == points[j].y))    //同一个点
                {
                    samePoint++;
                    continue;
                }

                if( points[i].x != points[j].x)                 //斜率存在
                {
                    double k = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    gradient[k]++;
                }
                else                                            //斜率不存在
                    sameX++;
            }

            int tmp = 0;
            map<double, int>::iterator iter = gradient.begin(); //迭代器
            while( iter != gradient.end() )                     //注意如果点全部相同，则容器为空
            {
                if( tmp < iter->second)
                    tmp = iter->second;
                iter++;
            }
            tmp += samePoint;
            if( maxNumber < tmp)
                maxNumber = tmp;

            if( maxSameX < sameX)                               //求解斜率不存在的最多点数
                maxSameX = sameX;
        }
        if( maxNumber < maxSameX)
            maxNumber = maxSameX;

        return maxNumber;
    }
};

int main()
{
    int i, j, x, y, n;
    vector<Point> points;

    while(scanf("%d", &n) != EOF)
    {
        points.clear();
        for( i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            Point pnt(x, y);
            points.push_back(pnt);
        }
        class Solution solution;
        int result = solution.maxPoints(points);
        printf("%d\n", result);
    }
    return 0;
}



