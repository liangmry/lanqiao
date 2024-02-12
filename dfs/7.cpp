#include <iostream>
#include <string>
using namespace std;
long long k, res;
string s;
char c1, c2;
void countAbbrSubstrings(char c1, char c2) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c1)
        {
            count++;
        }
        if(s[i+k-1]==c2)
        {
            res+=count;
        }
    }
}
int main() {
    cin >> k;
    cin >> s >> c1 >> c2;
    countAbbrSubstrings(c1, c2);
    cout << res << endl;
    return 0;
}
