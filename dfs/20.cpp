#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int N = 102;
char field[N][N];
bool st[N][N]; // 0未淹没 1淹没
int ans;
const int px[] = {1,1,1,0,0,-1,-1,-1},
        py[] = {1,-1,0,1,-1,1,0,-1}; // 未包括自身的点

void dfs(int x, int y)
{
    for(int i=0; i<=7; i++)
    {
        // 不能是x += px[i]，y += py[i];
        // 因为会改变原来的x，y。而我是for循环，关键在此
        int a = x+px[i], b = y+py[i];
        if(!st[a][b])
        {
            if(field[a][b]=='W' && a>=0 && a<n && b>=0 && b<m)
            {
                st[a][b] = true;
                dfs(a, b);
                // 不能回溯
            }
        }

    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%s", field[i]);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!st[i][j] && field[i][j]=='W')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}