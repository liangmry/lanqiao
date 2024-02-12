#include "bits/stdc++.h"
using namespace std;

// 排列
int n;
const int N = 12;
bool st[N]; // true选过  false未选
int arr[N];

void func(int x) // x位置  num该位置的数字
{
    if(x > n) // 剪枝
    {
        for(int i = 1; i <= n; i++)
        {
            cout << "    " << arr[i];
        }
        cout << endl;
        return ;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            arr[x] = i;
            func(x+1);

            //恢复状态
            st[i] = false;
            arr[x] = 0;
        }
    }

}

int main()
{
    cin >> n;
    func(1);
    
    return 0;
}