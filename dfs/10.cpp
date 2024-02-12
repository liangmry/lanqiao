#include <iostream>
using namespace std;

int n, k; // n������ѡk��
const int N = 22;
int arr[N]; // ��ѡ������
int res[N]; // ѡ����������
int cnt; // �������

bool isPrime(int *a) // �ж��Ƿ�������
{
    int sum = 0;
    for(int i = 1; i <= k; i++)
    {
        sum += a[i];
    }
    if(sum <= 1)
        return false;
    for(int i = 2; i * i <= sum; i++)
    {
        if(sum % i == 0)
            return false;
    }
    return true;
}

void dfs(int x, int start) // x��ǰλ��  start��ǰλ�ôӼ���ʼö��
{
    //��֦
    if(x > k)
    {
        if(isPrime(res))
            cnt++;
        return ;
    }

    for(int i = start; i <= n; i++)
    {
        //��x��λ��ѡ��ǰö������arrӳ��
        res[x] = arr[i];
        dfs(x+1, i+1);
        // �ָ�״̬(��дҲ��)
        res[x] = 0;
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    dfs(1, 1);
    cout << cnt;
    return 0;
}