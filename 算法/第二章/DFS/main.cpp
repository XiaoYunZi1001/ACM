#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[100000000];
int n,k;
int b[100000000];
//已经从前i项得到了和sum，然后对于i项之后的进行分支
bool dfs(int i,int sum)
{
    //如果前n项都计算过了，则返回sum是否与k相等
    if(i == n) return sum == k;//程序出口
    //不加上a[i]的情况
    b[i]=0;
    if(dfs(i+1,sum)) return true;
    //加上a[i]的情况
    b[i]=1;
    if(dfs(i+1,sum+a[i]))
    {
        //b[i]=1;
        return true;
    }
    b[i]=0;
    //无论是否加上a[i]都不能凑成k就返回false
    return false;
}

bool dfs1(int i,int sum)
{
    //如果前n项都计算过了，则返回sum是否与k相等
    if(i == n) return sum == 0;
    //不加上a[i]的情况
    if(dfs(i+1,sum)) return true;
    //加上a[i]的情况
    if(dfs(i+1,sum-a[i]))
    {
        //b[i]=1;
        return true;
    }
    //无论是否加上a[i]都不能凑成k就返回false
    return false;
}

void slove()
{

    if(dfs(0,0)) printf("Yes\n");
    else printf("No\n");
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    dfs(0,0);
    //dfs1(0,k);
    slove();
    if(dfs(0,0))
    {
        printf("%d = ",k);
   // for(int i=0;i<n;i++)
    //    cout<<b[i]<<endl;
        for(int i = 0;i<n;i++)
        {
            if(b[i]==1 && i!=0)
                printf(" + %d",a[i]);
            else if(b[i]==1)
                printf("%d",a[i]);
        }
        printf("\n");
    }

    return 0;
}
