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
        int s=X[i++];//s��û�и��ǵ�����ߵĵ��λ��
        while(i<N && X[i]<= s+R) i++;//һֱ����ǰ��ֱ������s�������R�ĵ�
        int p = X[i-1];//p���¼��ϱ�ǵĵ��λ��
        while(i<N && X[i] <=p+R) i++;//һֱ����ǰ��ֱ����p�ľ������R�ĵ�
        ans++;
    }
    cout << ans << endl;
    return 0;
}
