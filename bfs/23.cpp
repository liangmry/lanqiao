// P2730 [USACO3.2] 魔板 Magic Squares
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
// 可以使用cantor，双向bfs，A* 。 但本问题搜索空间没有太大，可以不用

string board = "12348765";
string goal;
unordered_map<string, bool> vis;

struct node {
    string state;
    int dis;
    vector<int> op;
};

void bfs() {
    queue<node> q;
    vis[board] = true;

    q.push({board, 0, {}});

    while (!q.empty()) {
        node now = q.front();
        q.pop();
        string now_state = now.state;
        int now_dis = now.dis;
        auto now_op = now.op;

        if (now_state == goal) {
            cout << now_dis << endl;
            for(auto &t : now_op) {
                if(t == 0) cout << "A";
                else if(t == 1) cout << "B";
                else cout << "C";
            }
            return ;
        }

        // next.op = now_op; 由于没有清空它，所以next.op会累积之前所有的操作，这会导致操作序列变得比实际长。
        for (int i = 0; i < 3; i++) {
            node next;
            next.state.resize(8);
            next.op = now_op;
            if (i == 0) { // 交换上下两行
                for (int j = 0; j < 4; j++) next.state[j] = now_state[j+4];
                for (int j = 4; j < 8; j++) next.state[j] = now_state[j-4];
                next.op.push_back(i);
            } else if (i == 1) { // 将最右边的一列插入最左边
                char s1 = now_state[3], s2 = now_state[7];
                for(int j = 1; j < 4; j++) next.state[j] = now_state[j-1];
                for(int j = 5; j < 8; j++) next.state[j] = now_state[j-1];
                next.state[0] = s1, next.state[4] = s2;
                next.op.push_back(i);
            } else { // 魔板中央四格作顺时针旋转
                next.state = now_state;
                char s1 = now_state[1], s2 = now_state[2], s3 = now_state[5], s4 = now_state[6];
                next.state[2] = s1, next.state[6] = s2, next.state[1] = s3, next.state[5] = s4;
                next.op.push_back(i);
            }

            if (!vis[next.state]) {
                vis[next.state] = true;
                next.dis = now_dis + 1;
                if(next.state == goal) {
                    cout << next.dis << endl;
                    for(auto & t : next.op) {
                        if(t == 0) cout << "A";
                        else if(t == 1) cout << "B";
                        else cout << "C";
                    }
                    return ;
                }
                q.push(next);
            }
        }
    }
}

int main() {
    goal.resize(8); // 必须预分配空间，不然不能使用下标操控
    // 知道是哪里错了，输入的问题。他是按照顺时针方向读入的
    // md看的半天的bfs，以后长记性吧！！输入也很有可能有问题。检查完实现还不对，就看输入，好好读题

    // 输入的是目标状态，草！！！
    for (int i = 0; i < 4; i++) {
        char x;
        cin >> x;
        goal[i] = x;
        getchar();
    }
    for(int i = 7; i >= 4; i--) {
        char x;
        cin >> x;
        goal[i] = x;
        getchar();
    }
    bfs();
    return 0;
}