#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N,M;//����
char field[100][100];//԰��
//����λ�ã�x,y��
void dfs(int x,int y)
{
    //����������λ���滻��.
    field[x][y] = '.';
    //ѭ�������ƶ���8������
    for(int dx=-1;dx<=1;dx++)
    {
        for(int dy=-1;dy<=1;dy++)
        {
            //��x�����ƶ�dx����y�����ƶ�dy���ƶ����Ϊ��nx,ny��
            int nx = x + dx;
            int ny = y + dy;
            //�жϣ�nx,ny���ǲ�����԰���ڣ��Լ��Ƿ��л�ˮ
            if(0 <= nx && nx <= N && 0 <= ny && ny <= M && field[nx][ny] == 'W')
                dfs(nx,ny);
        }
    }

}

int main()
{
    cin>>N>>M;
    int res = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>field[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(field[i][j] =='W')
            {
                //����W�ĵط���ʼdfs
                dfs(i,j);
                res++;
            }
        }
    //cout << "Hello world!" << endl;
    cout<<res<<endl;
    return 0;
}
