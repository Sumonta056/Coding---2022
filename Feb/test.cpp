//Code:655
///I am Groot |*|
///27.01.2021>>01.08 PM
#include<bits/stdc++.h>
#include <iostream>
 
typedef long long int vau;
typedef int meao;
 
using namespace std;
meao main()
{
    meao t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        meao cnt=0,i;
        for(i=0; i<s.length()-1; i++)
        {
            if(s[i]-'0'+s[i+1]-'0'>=10)
            {
                cnt=i;
            }
        }
        for(i=0; i<cnt; i++)
        {
            cout << s[i];
 
        }
        //cout << ".";
        int num=s[cnt]-'0'+s[cnt+1]-'0';
        cout << num;
        for(i=cnt+2; i<s.length(); i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}
0
0
0
0
0
0
0
1
1
1
1
1
1
0
0