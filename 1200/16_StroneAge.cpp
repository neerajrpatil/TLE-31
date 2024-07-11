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
    /*
    qn link : https://codeforces.com/problemset/problem/1679/B
    */
    while (t--)
    {
        ll n, q;
        cin >> n >> q;

        vector<ll> put(n + 1, 0);
        vector<ll> puv(n + 1, 0);

        ll ruv = 0, rut = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int ele;
            cin >> ele;
            puv[i] = ele;
            sum += ele;
        }

        for (ll i = 1; i <= q; i++)
        {
            ll type;
            cin >> type;
            if (type == 1)
            {
                ll ind, val;
                cin >> ind >> val;

                if (put[ind] < rut)
                {
                    sum -= ruv;
                    sum += val;
                    put[ind] = i;
                    puv[ind] = val;
                }
                else
                {
                    sum -= puv[ind];
                    sum += val;

                    put[ind] = i;
                    puv[ind] = val;
                }
            }
            else
            {
                ll ele;
                cin >> ele;
                ruv = ele;
                rut = i;
                sum = ele * n;
            }
            cout << sum << endl;
        }
    }
    return 0;
}