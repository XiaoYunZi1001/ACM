#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    int a,b,n,sum;

    while(scanf("%d",&b)!= EOF){
        for(int i=0;i<b;i++){
        sum=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a;
            sum+=a;
        }
        cout<<sum<<endl;
        if(b>i+1)
            printf("\n");
        }
        break;
    }


    return 0;
}
