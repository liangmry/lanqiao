#include "bits/stdc++.h"
using namespace std;
int n, m;
class cmp{
public:
    bool operator()(const pair<int, int>a, const pair<int, int>b)
    {
        return a.second > b.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> a;

int main()
{
    cin>>n>>m;
    int b[n+2];
    for(int i=1; i<n; i++)
    {
        int value;
        cin>>value;
        a.push({i,value});
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    while(m--)
    {
        auto p=a.top();
        if(b[p.first]<=0)
            break;
        a.pop();
        b[p.first]--;
        p.second++;
        a.push(p);
    }
    auto p=a.top();
    cout << p.second;

    return 0;
}