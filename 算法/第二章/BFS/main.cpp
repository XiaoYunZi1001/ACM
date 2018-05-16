#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//复杂度 O(4*N*M)=O(N*M) 待解决问题：求最短路径

//DFS将已经访问过的状态用标记管理起来，就可做到由近及远的搜索
const int INF = 100000000;
//使用pair表示状态时，使用ypedef会更方便一些
typedef pair<int,int> P;//pair 是 一种模版类型。每个pair 可以存储两个值。这两种值无限制。
//也可以将自己写的struct的对象放进去.应用：如果一个函数有两个返回值 的话，如果是相同类型，就可以用数组返回，如果是不同类型，就可以自己写个struct ，
//但为了方便就可以使用 c++  自带的pair ，返回一个pair,其中带有两个值。
char maze[100][101];//表示迷宫的字符串数组
int N,M;
int sx,sy;//起点坐标
int gx,gy;//终点坐标
int d[100][100];//到各个位置最短路径数组，初始化时用充分大数INF，且尚未到达位置就是 INS 也起到了标记作用
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};//四个方向移动的向量
//求从（sx,sy）->(gx,gy)的最短距离
//如果无法到达，则是INF
int bfs()
{
    queue<P> que;
    //把所有位置初始化为INF
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            d[i][j]= INF;
        }
    }
    //将起点加入队列，并把这一点的距离设置为0
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    //不断循环，直到队列的长度为0
    while(que.size())
    {
        //从队列前端取出元素
        P p = que.front();
        que.pop();
        //如果取出的状态已经是终点，则结束搜索
        if(p.first == gx && p.second == gy)
            break;
        //四个方向的循环
        for(int i=0;i<4;i++)
        {
            //移动之后的位置记为（nx,ny）
            int nx = p.first + dx[i],ny = p.second + dy[i];
            //判断是否可以移动以及是否已经访问过（d[nx][ny]!=INF 即为已经访问过）
            if(0<=nx && nx < N && 0<= ny && ny <M &&maze[nx][ny] != '#' && d[nx][ny] ==INF)
            {
                //可以移动的话，则加入队列，并且到该位置的距离确定为到p的距离+1
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
