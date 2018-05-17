#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool used[100];
int perm[100];
void permutation1(int pos,int n)
{
    if(pos == n)
    {
        /**/
        return  ;
    }
    for(int i = 0;i<n;i++)
    {
        if(!used[i])
        {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos +1,n);
            used[i] = false;
        }
    }
    return ;
}
int perm2[100];
void permutation2(int n)
{
    for(int i=0;i<n;i++)
    {
        perm2[i] = i;
    }
    do
    {

    }while (next_permutation(perm2,perm2+n));
 return ;

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
