#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
//生成{0,1,2,3,4,...,n-1}的n！种排列
bool used[100];
int perm[100];
void permutation1(int pos,int n)
{
    if(pos == n)
    {
        /*这里编写需要对perm进行的操作*/
        return  ;
    }
    //针对perm的第pos个位置，究竟使用0~n-1中的哪一个进行循环
    for(int i = 0;i<n;i++)
    {
        if(!used[i])
        {
            perm[pos] = i;
            //i已经被使用了，所以把标志设置为true
            used[i] = true;
            permutation1(pos +1,n);
            //返回之后把标志复位
            used[i] = false;
        }
    }
    return ;
}
//即使有重复的元素也会生出所有的排列
//next_permutation是按照字典序来生成下一个排列的
int perm2[100];
void permutation2(int n)
{
    for(int i=0;i<n;i++)
    {
        perm2[i] = i;
    }
    do
    {
        /*这里编写对perm2进行操作*/
    }while (next_permutation(perm2,perm2+n));
    //所有的排列都生成后，next_permutation会返回false
 return ;

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
