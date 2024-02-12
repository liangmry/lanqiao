#include <iostream>
using namespace std;

const int final_score = 70, nums = 30; // 最终得分  题目数量
int ans;

void dfs(int x, int score) // 第x题， 当前得分
{
    if(x > nums || score >= 100)
    {

        return ;
    }
    if(score == final_score)
    {
        ans++;
    }
    dfs(x+1, score+10);
    dfs(x+1, 0);
}

int main()
{
    // 0 0 而非 1 0.  是因为1的话，没有对第一题进行score+10的操作
    dfs(0,0);
    cout << ans;
    return 0;
}