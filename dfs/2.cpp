/*
 飞机降落
 N 架飞机准备降落到某个只有一条跑道的机场。其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间，即它最早
可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。降落过程需要 Li个单位时间。
一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
请你判断 N 架飞机是否可以全部安全降落。
 */
//深度优先搜索


//法一
/*
#include <bits/stdc++.h>
using namespace std;
class plane{
public:
    int start, keep, down;
    plane(int t,int d,int l)
    {
        start=t;
        keep=d;
        down=l;
    }
};
bool dfs(vector<plane>& ps, vector<bool>& status, int now, int count)
{
    if(count == ps.size())
        return true;
    for(int i=0; i<ps.size(); i++)
    {
        if(!status[i])
        {
            status[i] =1;
            if(now<=ps[i].start)
            {
                if(dfs(ps,status,ps[i].start+ps[i].down, count+1))
                    return 1;
            }
            else if(now<=ps[i].start+ps[i].keep)
            {
                if(dfs(ps,status,now+ps[i].down,count+1))
                    return 1;
            }
            status[i]=0;
        }
    }
    return 0;
}

int main()
{
    int m, n;
    cin >> m;
    while(m--)
    {
        cin>>n;
        int t,d,l;
        vector<plane> ps;
        vector<bool> status(n, false);
        while(n--)
        {

            cin>>t>>d>>l;
            ps.push_back(plane(t,d,l));

        }
        bool f = dfs(ps,status,0,0);
        if(f)
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
    }

    return 0;
}
*/


// 法二

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int t, n;
const int N = 12;
int arrival[N], keep[N], down[N];
bool st[N]; // 0没选 1选
bool ans;

void dfs(int now, int cnt) // 第x个飞机降落
{
    if(cnt == n) // 能排好n个
    {
        ans = true;
        return ;
    }

    for(int i=1; i<=n; i++)
    {
        // 全排列问题
        if(!st[i] && now<=arrival[i]+keep[i]) // 时间要在到达时间加徘徊时间之后
        {
            st[i] = true;
            dfs(max(now, arrival[i])+down[i], cnt+1); // now要更改为now和arrival中较大者
            st[i] = false;
        }
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin>>arrival[i]>>keep[i]>>down[i];

        }
        ans = false;
        dfs(0, 0);
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
