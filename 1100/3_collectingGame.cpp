#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        int i = 0;
        for (auto &it : v)
        {
            int ele;
            cin >> ele;
            it = {ele, i++};
        }
        sort(begin(v), end(v));
        int pre[n];
        pre[0] = 0;
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + v[i][0];
        vector<int> ans(n);
        int dp[n];
        dp[n - 1] = n - 1;
        dp[0] = 0;
        ans[v[n - 1][1]] = n - 1;
        ans[v[0][1]] = 0;
        for (int i = n - 2; i >= 1; i--)
        {
            auto ub = upper_bound(begin(v), end(v), pre[i]);
            if (ub == v.begin())
                dp[i] = 0;
            else
            {
                ub--;
                int x = distance(begin(v), ub);
                if (x > i)
                    dp[i] = dp[x];
                else
                    dp[i] = i;

                ans[v[i][1]] = dp[i];
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}