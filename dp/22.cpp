// P1928 外星密码
#include <iostream>
#include <string>
// 递归题
// md一开始看别人的抄都抄不对，自己跟着感觉随手一写，tmd就对了！！递归真的是玄学，***感觉是咋样就咋写***
using namespace std;

string read() {
    // 需要一个输出结果，字母就加进来，[ 就递归， ] 就返回， 最后回到第一层 返回我的res
    string res;
    char ch;
    while(cin >> ch) {
        if(isalpha(ch)) res += ch;
        else if(ch == '[') {
            int n;
            cin >> n;
            string s = read();
            // 这里不能省略s，使用res += read() 会跟着while多次调用函数，造成结果错误
            while(n --) res += s;
        } else {
            return res;
        }
    }
    return res;
}

int main() {
    cout << read();
    return 0;
}