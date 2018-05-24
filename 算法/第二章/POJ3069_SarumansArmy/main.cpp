#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N,R;
int X[1000];
int main()
{
    cin>>N>>R;
    for(int i=0;i<N;i++) cin>>X[i];
    sort(X,X+N);
    int i = 0,ans = 0;
    while(i<N)
    {
        int s=X[i++];//s是没有覆盖的最左边的点的位置
        while(i<N && X[i]<= s+R) i++;//一直向右前进直到距离s距离大于R的点
        int p = X[i-1];//p是新加上标记的点的位置
        while(i<N && X[i] <=p+R) i++;//一直向右前进直到距p的距离大于R的点
        ans++;
    }
    cout << ans << endl;
    return 0;
}
