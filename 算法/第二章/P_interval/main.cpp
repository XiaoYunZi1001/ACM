#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//�ڿ�ѡ�����У�ÿ�ζ�ѡȡ����ʱ������Ĺ�����
int N,S[100000],T[100000];
pair<int,int> itv[100000];//���ڶԹ��������pair����
int main()
{
    cin>>N;
    for(int i = 0 ; i<N;i++)
        cin>>S[i];
    for(int i = 0 ; i<N;i++)
        cin>>T[i];
    //��pair���е��������ֵ���Ƚ�
    //Ϊ���ý���ʱ����Ĺ�������ǰ�棬��T����first,��S����second
    for(int i=0;i<N;i++)
    {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv,itv+N);
    //t�������ѡ�����Ľ���ʱ��
    int ans = 0, t = 0;
    for(int i =0;i<N;i++)
    {
        if(t<itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    }
    cout <<ans<< endl;
    return 0;
}
