#include <iostream>
//#include<bits/stdc++.h>

using namespace std;
/*
int input(int n){
    int cycle_length;
    cout<<n<<" ";
    if(n==1)
        return cycle_length;
    //return

}
*/
int cycle_length=0;
int input(int n){
   // if(n<0 || n>1000000)
     //   return 1;
    //cout<<n<<' ';
    cycle_length++;
    if(n==1)
        return cycle_length;
    else{
        if(n%2 != 0){
            return input(3*n+1);
        }
        else{
            return input(n/2);
        }
    }
}
int main()
{
    int i,j;
    int n,m,t=0,tmp,a,b;
    //cin>>i>>j;
    while(scanf("%d%d",&i,&j)!= EOF){
    a=i;
    b=j;
    if(i>=j){
        tmp=a;
        a=b;
        b=tmp;
    }
    for(n=a;n<=b;n++)
    {
        m=input(n);
        if(m>t){
            t=m;
            cycle_length=0;
        }
        else
            cycle_length=0;

    }
    cout<<i<<' '<<j<<' '<<t<<endl;
    t=0;
    }
    //cout<<input(n)<<endl;
    //cycle_length=0;
    //cout<<input(m)<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
