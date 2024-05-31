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
        int n, x;
        cin >> n >> x;
        int start = 0;
        vector<int> v1(n), v2(n), v3(n);
        for (auto &it : v1)
            cin >> it;
        for (auto &it : v2)
            cin >> it;
        for (auto &it : v2)
            cin >> it;

        for (auto it : v1)
        {
            bool chk = true;
            for (int i = 31; i >= 0 && chk; i--)
            {
                int bx = ((x >> i) & 1);
                int bele = ((it >> i) & 1);
                if (bx == 0 && bele == 1)
                {
                    chk = false;
                    break;
                }
            }
            if (!chk)
                break;
            else
                start |= it;
        }
        for (auto it : v3)
        {
            bool chk = true;
            for (int i = 31; i >= 0 && chk; i--)
            {
                int bx = ((x >> i) & 1);
                int bele = ((it >> i) & 1);
                if (bx == 0 && bele == 1)
                {
                    chk = false;
                    break;
                }
            }
            if (!chk)
                break;
            else
                start |= it;
        }
        for (auto it : v2)
        {
            bool chk = true;
            for (int i = 31; i >= 0 && chk; i--)
            {
                int bx = ((x >> i) & 1);
                int bele = ((it >> i) & 1);
                if (bx == 0 && bele == 1)
                {
                    chk = false;
                    break;
                }
            }
            if (!chk)
                break;
            else
                start |= it;
        }
        if (x == start)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}