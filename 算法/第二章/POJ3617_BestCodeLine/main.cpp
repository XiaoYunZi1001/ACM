#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;//输入
char S[2001];
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>S[i];
    int a = 0, b = N-1;//剩余的字符串为S[a],S[a+1],...,S[b].
    while(a<=b)
    {
        //将从左起和从右起的字符串比较
        bool left = false;
        for(int i=0; a+i <= b ;i++)
        {
            if(S[a+i]<S[b-i])//首比尾小，则输出首
            {
                left =true;
                break;
            }
            else if(S[a+i] > S[b-i])
            {
                left = false;
                break;
            }
            //首尾一样大则比较下一字符大小
        }
        if(left) putchar(S[a++]);//首大输出首
        else putchar(S[b--]);//尾大输出尾
    }
    putchar('\n');
   // cout << "Hello world!" << endl;
    return 0;
}
