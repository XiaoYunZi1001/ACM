#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//����
int n,W;
int w[100],v[100];
//�ӵ�i����Ʒ��ʼ��ѡ ������С��j �Ĳ���

/*******�Ľ�*********/
int dp[101][101];
/*******************/

int rec(int i,int j)
{
    /*******�Ľ�*********/
    if(dp[i][j]>=0)
        return dp[i][j];
    /*******************/
    int res;
    if(i==n)
    {//�Ѿ�û��ʣ����Ʒ
        res = 0;
    }
    else if(j<w[i])
    {//�޷����ɴ���Ʒ
        res = rec(i+1,j);
    }
    else
    {//��ѡ�β���ѡ�Ǹ���ø��ߵļ�ֵ
        res = max(rec(i+1,j),rec(i+1,j - w[i]) + v[i]);
    }
    //���ؼ�ֵ��
    return dp[i][j] = res;
}
int rec1(int i,int j,int sum)
{
    int res;
    if(i == n)
        res = sum;
    else if(j < w[i])
    {
        res = rec1(i+1,j,sum);
    }
    else
    {
        res = max(rec1(i+1,j,sum),rec1(i+1,j-w[i],sum+v[i]));
    }
    return res;
}
int main()
{
    /*******�Ľ�*********/
    //��-1��ʼ��dp�����ʾ��δ����
    memset(dp,-1,sizeof(dp));
    /*******************/
    cin>>n;
    for(int i =0 ;i<n ; i++)
    {
        cin>>w[i];
        cin>>v[i];
    }
    cin>>W;

    cout <<rec(0,W)<< endl;
    cout <<rec1(0,W,0);
    return 0;
}
