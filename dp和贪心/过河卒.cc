/*
    描述
    棋盘上 A点有一个过河卒，需要走到目标
    B点。卒行走的规则：可以向下、或者向右。同时在棋盘上 C
    点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

    棋盘用坐标表示，A 点 (0, 0)、B点(n,m)，同样马的位置坐标是需要给出的。
    现在要求你计算出卒从 A点能够到达
    B点的路径的条数，假设马的位置(x,y)是固定不动的，并不是卒走一步马走一步。

    https://www.nowcoder.com/practice/cc1a9bc523a24716a117b438a1dc5706?tpId=230&tqId=2378812&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D230
*/

#include <vector>
#include <iostream>
#include <set>

using namespace std;

using vv = vector<vector<int>>;

int hash(int x, int y)
{
    return x * 1000 + y;
}



int Solution(int n, int m, int x, int y)
{
    vv array(4, vector<int>(8, 0));
    vv dp(array);
    set<int> horse_kill;

    vector<vector<int>> temp = {
        {-2, -1},
        {-2, 1}, // up
        {-1, -2},
        {1, -2}, // left
        {2, 1},
        {2, -1}, // down
        {1, -2},
        {-1, -2}};

    for (auto i = 0; i < 8; ++i)
    {
        int x0 =
    }
}

int main()
{
    vector<vector<int>> 

}