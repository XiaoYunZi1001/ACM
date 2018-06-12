#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//输入
int n,W;
int w[100],v[100];
//从第i个物品开始挑选 总重量小于j 的部分

/*******改进*********/
int dp[101][101];
/*******************/

int rec(int i,int j)
{
    /*******改进*********/
    if(dp[i][j]>=0)
        return dp[i][j];
    /*******************/
    int res;
    if(i==n)
    {//已经没有剩余商品
        res = 0;
    }
    else if(j<w[i])
    {//无法容纳此商品
        res = rec(i+1,j);
    }
    else
    {//挑选何不挑选那个获得更高的价值
        res = max(rec(i+1,j),rec(i+1,j - w[i]) + v[i]);
    }
    //返回价值和
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
    /*******改进*********/
    //用-1初始化dp数组表示尚未计算
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
