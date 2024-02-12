#include <iostream>
#include <string>
using namespace std;
int n, res;
string s;
char c1, c2;
void dfs(int start, string temp) {
    temp+=s[start];
    // 如果子串的长度大于等于 K，并且以 c1 开头 c2 结尾，就计数
    if (temp.size() >= n && temp[0] == c1 && temp.back() == c2) {
        res++;
//        cout<<temp<<endl;
        // 不要在这里返回，继续枚举
    }
    if(temp.size() == s.size())
        return;
    // 枚举 start 之后的相邻字符，加入到子串中
    int i = start + 1; // 只能取 start + 1，不能大于它
    if (i < s.size()) { // 防止越界
        dfs(i, temp + s[i]);
    }
}
int main() {
    cin >> n;
    cin >> s >> c1 >> c2;
    for (int i = 0; i < s.size(); i++) { // 从每个位置开始找子串
        dfs(i, ""); // 空串作为初始子串
    }
    cout << res << endl;
    return 0;
}
