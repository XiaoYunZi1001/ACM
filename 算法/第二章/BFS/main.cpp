#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//���Ӷ� O(4*N*M)=O(N*M) ��������⣺�����·��

//DFS���Ѿ����ʹ���״̬�ñ�ǹ����������Ϳ������ɽ���Զ������
const int INF = 100000000;
//ʹ��pair��ʾ״̬ʱ��ʹ��ypedef�������һЩ
typedef pair<int,int> P;//pair �� һ��ģ�����͡�ÿ��pair ���Դ洢����ֵ��������ֵ�����ơ�
//Ҳ���Խ��Լ�д��struct�Ķ���Ž�ȥ.Ӧ�ã����һ����������������ֵ �Ļ����������ͬ���ͣ��Ϳ��������鷵�أ�����ǲ�ͬ���ͣ��Ϳ����Լ�д��struct ��
//��Ϊ�˷���Ϳ���ʹ�� c++  �Դ���pair ������һ��pair,���д�������ֵ��
char maze[100][101];//��ʾ�Թ����ַ�������
int N,M;
int sx,sy;//�������
int gx,gy;//�յ�����
int d[100][100];//������λ�����·�����飬��ʼ��ʱ�ó�ִ���INF������δ����λ�þ��� INS Ҳ���˱������
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};//�ĸ������ƶ�������
//��ӣ�sx,sy��->(gx,gy)����̾���
//����޷��������INF
int bfs()
{
    queue<P> que;
    //������λ�ó�ʼ��ΪINF
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            d[i][j]= INF;
        }
    }
    //����������У�������һ��ľ�������Ϊ0
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    //����ѭ����ֱ�����еĳ���Ϊ0
    while(que.size())
    {
        //�Ӷ���ǰ��ȡ��Ԫ��
        P p = que.front();
        que.pop();
        //���ȡ����״̬�Ѿ����յ㣬���������
        if(p.first == gx && p.second == gy)
            break;
        //�ĸ������ѭ��
        for(int i=0;i<4;i++)
        {
            //�ƶ�֮���λ�ü�Ϊ��nx,ny��
            int nx = p.first + dx[i],ny = p.second + dy[i];
            //�ж��Ƿ�����ƶ��Լ��Ƿ��Ѿ����ʹ���d[nx][ny]!=INF ��Ϊ�Ѿ����ʹ���
            if(0<=nx && nx < N && 0<= ny && ny <M &&maze[nx][ny] != '#' && d[nx][ny] ==INF)
            {
                //�����ƶ��Ļ����������У����ҵ���λ�õľ���ȷ��Ϊ��p�ľ���+1
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second]+1;
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if(maze[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    int res = bfs();
    cout<<res<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
