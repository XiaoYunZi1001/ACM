#include <iostream>
#include <bits/stdc++.h>>
using namespace std;

//��������

const int V[6] = {1,5,10,50,100,500};//Ӳ����ֵ
//����
int C[6];//��ͬ��ֵ��Ӳ������
int A;//֧����Ǯ

int main()
{
    for(int i=0;i<6;i++)
        cin >>C[i];
    cin >> A;

    int ans = 0;
    for(int i=5; i>=0; i--)
    {
        int t = min(A / V[i] , C[i]); //ʹ��Ӳ��i��ö��
        A -= t * V[i];
        ans +=t;
    }
    cout <<ans<< endl;
    return 0;
}
