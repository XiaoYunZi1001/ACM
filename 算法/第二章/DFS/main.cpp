#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[100000000];
int n,k;
int b[100000000];
//�Ѿ���ǰi��õ��˺�sum��Ȼ�����i��֮��Ľ��з�֧
bool dfs(int i,int sum)
{
    //���ǰn�������ˣ��򷵻�sum�Ƿ���k���
    if(i == n) return sum == k;//�������
    //������a[i]�����
    b[i]=0;
    if(dfs(i+1,sum)) return true;
    //����a[i]�����
    b[i]=1;
    if(dfs(i+1,sum+a[i]))
    {
        //b[i]=1;
        return true;
    }
    b[i]=0;
    //�����Ƿ����a[i]�����ܴճ�k�ͷ���false
    return false;
}

bool dfs1(int i,int sum)
{
    //���ǰn�������ˣ��򷵻�sum�Ƿ���k���
    if(i == n) return sum == 0;
    //������a[i]�����
    if(dfs(i+1,sum)) return true;
    //����a[i]�����
    if(dfs(i+1,sum-a[i]))
    {
        //b[i]=1;
        return true;
    }
    //�����Ƿ����a[i]�����ܴճ�k�ͷ���false
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
