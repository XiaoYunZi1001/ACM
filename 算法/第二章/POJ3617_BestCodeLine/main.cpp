#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;//����
char S[2001];
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>S[i];
    int a = 0, b = N-1;//ʣ����ַ���ΪS[a],S[a+1],...,S[b].
    while(a<=b)
    {
        //��������ʹ�������ַ����Ƚ�
        bool left = false;
        for(int i=0; a+i <= b ;i++)
        {
            if(S[a+i]<S[b-i])//�ױ�βС���������
            {
                left =true;
                break;
            }
            else if(S[a+i] > S[b-i])
            {
                left = false;
                break;
            }
            //��βһ������Ƚ���һ�ַ���С
        }
        if(left) putchar(S[a++]);//�״������
        else putchar(S[b--]);//β�����β
    }
    putchar('\n');
   // cout << "Hello world!" << endl;
    return 0;
}
