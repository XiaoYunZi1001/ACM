//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;

//hrz
/*
int flag[50];//每行做标记，除去多于行检测
char **CreatArray(int row, int col)
{
    char **arr= new char *[row];
    for(int i=0;i<row;i++)
    {
        arr[i]= new char [col];
    }

    return arr;

}

void DeleteArray(int row,char **arr)
{
    for(int i=0;i<row;i++)
    {
        delete[] arr[i];
    }
}

int CheckCol(int row1,int col1,int row2,int col,char **arr)
{
    for(int i=0;i<col;i++)
    {
        if(i==col1) continue;
        if(arr[row1][i]=='#')
            if(arr[row2][i]!='#')
            {
                //cout<<"No"<<endl;
                return 1;
                ;
            }

    }
    for(int j=0;j<col;j++)
    {
        if(j==col1) continue;
        if(arr[row2][j]=='#')
            if(arr[row1][j]!='#')
            {
                //cout<<"No"<<endl;
                return 1;
            }

    }
    return 0;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int row,col;
    cin>>row>>col;
   // while(scanf("%d%d",&row,&col)!= EOF)
  //  {
         char **arr=CreatArray(row,col);
    for(int i=0;i<row;i++)
    {
        flag[i]=0;
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];

        }
    }
    //cout<<CheckCol(row,col,arr)<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]=='#')
            {
                if(flag[i]==1) continue;//剪枝
                for(int k=i+1;k<row;k++)
                {
                     if(arr[k][j]=='#')
                    {
                        flag[k]=1;//进行完行检测
                        if(CheckCol(i,j,k,col,arr)==1)
                        {
                            cout<<"No"<<endl;
                            return 0;
                        }
                    }
                    else
                        continue;
                }

            }
            else
                continue;
        }

    }
    cout<<"Yes"<<endl;
    DeleteArray(row,arr);
   // }

    /*

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    //cout << "Hello world!" << endl;
    //return 0;
//}
#include <cstdio>

typedef long long int64;
static const int MAXN = 53;

static int n, m;
static bool a[MAXN][MAXN];
static int64 b[MAXN];

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) a[i][j] = (getchar() == '#');//是#返回true 否则false；<=m是为了接收回车

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            bool all_same = true, no_intersect = true;
            for (int k = 0; k < m; ++k) {
                if (a[i][k] != a[j][k]) all_same = false;//是否存在不对称（#，-）（-，#）
                if (a[i][k] && a[j][k]) no_intersect = false;//是否存在同列同为井号
            }
            if (!all_same && !no_intersect) {
                puts("No"); return 0;
            }
        }

    puts("Yes"); return 0;
}


