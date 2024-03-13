// 背包问题求具体方案 https://www.acwing.com/problem/content/12/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1002;
int n, V;
int v[N], w[N]; // 体积 价值
int f[N];
vector<int> ans[N]; // 这里优化了一次空间
// 原本： int f[N][N]; vector<int> ans[N][N];

int main() {
    cin >> n >> V;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = n; i >= 1; i--) {
        // 01背包优化了一维
        for(int j = V; j >= v[i]; j--) {
            if(f[j-v[i]] + w[i] >= f[j]) { // 有讲究的 要求最小的字典序
                f[j] = f[j-v[i]] + w[i];
                ans[j] = ans[j-v[i]]; // 矩阵 赋值运算
                ans[j].push_back(i);
            } else {
                f[j] = f[j];
                ans[j] = ans[j];
            }
        }
    }
    for(int i = ans[V].size()-1; i >= 0; i--) {
        cout << ans[V][i] << ' ';
    }

    return 0;
}

// 错误回顾
/*
 * map<int, set<int>> term;
 *
 * for(int i = n; i >= 1; i--) {
for(int j = 0; j <= V; j++) {
if(j < v[i]) {
f[i][j] = f[i+1][j];
if(!term[f[i+1][j]].empty())
for(auto &t: term[f[i+1][j]]) {
        term[f[i][j]].insert(t);    ***这里的中括号里是f[][],这是个 int数，那他去做搜索 是不行的
                                    ***起码应该开个 二维的 以此做索引 保存搜索路径
}
。。。。
for(auto &t: term[f[1][V]]) {
cout << t << ' ';
}
 */