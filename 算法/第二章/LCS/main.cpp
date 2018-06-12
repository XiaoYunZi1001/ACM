#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[1000],t[1000];
int dp[1001][1001];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<m;i++)
        cin>>t[i];
    for(int i=0;i<n;i++)
        cout<<s[i];
    for(int i=0;i<m;i++)
        cout<<t[i];
    cout<<endl;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i] == t[j])
            {
                dp[i+1][j+1] = dp[i][j] +1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }


    cout << dp[n][m]<< endl;
    return 0;
}
