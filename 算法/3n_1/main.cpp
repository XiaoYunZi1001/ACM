#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a,b;
int run(int x)
{
    if(x==1) return 1;
    if(x&1) return run(x*3+1)+1;
    else return run(x/2)+1;
}
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int ans=0;
        for(int x=min(a,b);x<=max(a,b);x++)
        {
            ans=max(ans,run(x));
        }
        cout<<a<<" "<<b<<" "<<ans<<endl;
    }
    return 0;
}
