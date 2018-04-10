#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//mycode
/*
char l[100];
int check(char a ,char b)
{
    if(a==b)
        return 2;
    else
        return 1;
}
int main()
{
    int n,sum=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(l[i]==l[i+1])
        {
            if(l[i]!='?')
            {

                puts("No");
                return 0;
            }
        }
    }
     for(int i=0;i<n-1;i++)
    {
        if((l[i]==l[i+1])&&(l[i]=='?'))
        {

                puts("Yes");
                return 0;

        }
    }
    if((l[0]=='?')||(l[n-1]=='?'))
    {
        puts("Yes");
        return 0;
    }
    for(int i=1;i<n-1;i++)
    {
        if(l[i]=='?')
        {
            sum*=check(l[i-1],l[i+1]);
        }
    }
    if(sum>1)
        puts("Yes");
    else
        puts("No");
    //cout << "Hello world!" << endl;
    return 0;
}
*/

//internet
/*
void NO() {
	puts("No");
	exit(0);
}
void YES() {
	puts("Yes");
	exit(0);
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n - 1; ++i)
		if(s[i] != '?' && s[i] == s[i+1])
			NO();
	for(int i = 0; i < n; ++i) if(s[i] == '?') {
		if(i == 0 || i == n - 1) YES();
		if(s[i+1] == '?') YES();
		if(s[i-1] == s[i+1]) YES();
	}
	NO();
}
*/

//optimal
void Yes()
{
    puts("Yes");
    exit(0);
}
void No()
{
    puts("No");
    exit(0);
}
int main()
{
    int n;
    cin>>n;
    string l;
    cin>>l;
    for(int i=0;i<n-1;i++)
            if(l[i]==l[i+1])
                if(l[i]!='?') No();
    if((l[0]=='?')||(l[n-1]=='?')) Yes();
    for(int i=1;i<n-1;i++)
    {
        if(l[i]=='?')
        {
           if((l[i+1])=='?') Yes();
            if(l[i-1]==l[i+1]) Yes();
        }
    }
    No();
}
