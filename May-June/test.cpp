#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool a[100999];
    memset(a, true, 100999);
    long long i, j, k;
    a[0] = a[1] = false;
    for(i = 2; i <=100999; i++)
    {
        if(a[i] == true)
        {
           for(j = i*2; j <= 100999; j+=i)
           {
               a[j] = false;
           }
        }
    }
    long long dis[100999];
    memset(dis, 0, 100999);
    for(i = 1; i < 100999; i++)
    {
        if(!a[i])
        {
            for(j = i+1; j <= 100999; j++)
            {
                if(a[j])
                {
                    //cout << i << " " << j <<endl;
                    dis[i] = j-i;
                    break;
                }
            }
        }
    }

    //for(i = 1; i < 100; i++) cout << dis[i] <<" ";

    long long n, m;
    cin >> n >> m;
    long long p[n][m];
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    long long mn = 99999999, sum = 0;
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0; j < m; j++)
        {
            sum += dis[p[i][j]];
        }
        //cout << sum << endl;
        if(mn > sum) mn = sum;
    }
    //cout << endl;
    sum = 0;
    for(i = 0; i < m; i++)
    {
        sum = 0;
        for(j = 0; j < n; j++)
        {
            sum += dis[p[j][i]];
            //cout << p[j][i] << " " << dis[p[j][i]] << endl;
        }
        //cout << sum << endl;
        if(mn > sum) mn = sum;
    }
    cout << mn << endl;
}