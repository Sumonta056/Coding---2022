//        ** Sumonta Saha Mridul **                                    SWE - SUST
/*

 *        ######    ##     ##  ##     ##   #######   ##    ##   ########      ###
 !       ##    ##   ##     ##  ###   ###  ##     ##  ###   ##      ##        ## ##
 ?       ##         ##     ##  #### ####  ##     ##  ####  ##      ##       ##   ##
 *        ######    ##     ##  ## ### ##  ##     ##  ## ## ##      ##      ##     ##
 !             ##   ##     ##  ##     ##  ##     ##  ##  ####      ##      #########
 ?       ##    ##   ##     ##  ##     ##  ##     ##  ##   ###      ##      ##     ##
 *        ######     #######   ##     ##   #######   ##    ##      ##      ##     ##

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back

#define pii pair<int, int>
#define pll pair<long, long>
#define mp(a, b) make_pair(a, b)
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>
#define sll set<ll>
#define qll queue<ll>
#define stll stack<ll>
#define Mi map<int, int>
#define mii map<pii, int>
#define alls(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()

#define Size(s) s.length()
#define all(v) (v.begin, v.end)
#define rev(v) reverse(v.begin, v.end)
#define srt(v) sort(v.begin, v.end)

#define F(i, s, e) for (ll i = s; i < e; ++i)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rem(i, a, b) for (int i = a; i > b; i--)
#define pv(v)             \
    for (ll i : v)        \
        cout << i << " "; \
    cout << endl;

#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

#define cin(n) cin >> n
#define cin2(a, b) cin >> a >> b;
#define cin3(a, b, c) cin >> a >> b >> c;
#define printE(str) cout << str << endl
#define print(str) cout << str << endl
#define endl '\n'
#define Y cout << "YES\n"
#define No cout << "NO\n"
#define ye cout << "Yes\n"
#define no cout << "No\n"

#define sp " "
#define enter cout << endl;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define mod 1000000007
#define inf 1000000000000000005
#define INF numeric_limits<ll>::max();
#define NINF numeric_limits<ll>::min();
const int N = int(1e5 + 3);

#define foi(i, a, b) for (int i = a; i < b; i++)
#define foI(i, a, b) for (int i = a; i <= b; i++)
#define fol(i, a, b) for (ll i = a; i < b; i++)
#define foL(i, a, b) for (ll i = a; i <= b; i++)

//* char a = 'A';   int num = (int) a;
//* char a = '2';   int num = a-48;

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        double paid[200] = {0.00};
        double countArr[200] = {0.00};

        map<char, double> p;

        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;

            double value;
            cin >> value;

            // int index = (int)c;
            // paid[index] = value;
            p.insert({c, value});
        }

        // for(auto it : paid)
        // {
        //     if(it != 0) cout <<it <<endl;
        // }

        int line;
        cin >> line;

        double ans = 0;

        string s;
        getline(cin, s);

        map<char, double> q;

        for (int i = 0; i < line; i++)
        {

            getline(cin, s);
            int size = s.length();

            for (int j = 0; j < size; j++)
            {
                char c = s[j];

                ans = ans + p[c];
            }
        }

        // for (int i = 0; i < 200; i++)
        // {
        //     ans += paid[i] * countArr[i] * 1.00;
        // }

        // for (auto it = p.begin(); it != p.end(); it++)
        // {
        //     ans = ans + it->second * q[it->first] * 1.00;
        // }

        ans = ans / 100;

        cout << fixed << setprecision(2);
        cout << ans << "$" << endl;
    }
}
