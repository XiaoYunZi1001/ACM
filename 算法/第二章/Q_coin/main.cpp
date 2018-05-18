#include <iostream>
#include <bits/stdc++.h>>
using namespace std;

//背包问题

const int V[6] = {1,5,10,50,100,500};//硬币面值
//输入
int C[6];//不同面值的硬币数量
int A;//支付的钱

int main()
{
    for(int i=0;i<6;i++)
        cin >>C[i];
    cin >> A;

    int ans = 0;
    for(int i=5; i>=0; i--)
    {
        int t = min(A / V[i] , C[i]); //使用硬币i的枚数
        A -= t * V[i];
        ans +=t;
    }
    cout <<ans<< endl;
    return 0;
}
