#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/******/
//��д�ݹ飬ֱ�����õ���ʽ�������ֵ����������򵥵����ö���ѭ���������
/*******/
int dp[101][101];
int n,W;
int w[100],v[100];
int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i =0 ;i<n ; i++)
    {
        cin>>w[i];
        cin>>v[i];
    }
    cin>>W;
    for(int i= n-1;i>=0;i--)
    {
        for(int j = 0;j <=W;j++)
        {
            if(j < w[i])
            {
                dp[i][j] = dp[i+1][j];
            }
            else
            {
                dp[i][j]= max (dp[i+1][j] , dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout <<dp[0][W]<< endl;
    return 0;
}
