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
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;
        /*
        My had thought correct that when it switches monotonic increase/decreasing nature
        i have to increase my counter, but i thought i need to keep track if its dec or inc
        and then check if its changed n all

        But i can rather think with respect to each element, an element a[i] wont change monotonic nature if a[i-1]<=a[i]<=a[i] || a[i-1]>=a[i]>=a[i+1]


        */

        /*
         set<int> st(begin(v), end(v));
         if (st.size() == 1)
         {
             cout << 1 << endl;
             continue;
         }
         int ans = 2;
         for (int i = 1; i < n - 1; i++)
         {
             if ((v[i - 1] <= v[i] && v[i] <= v[i + 1]) || (v[i - 1] >= v[i] && v[i] >= v[i + 1]))
                 continue;
             else
                 ans++;
         }
         cout << ans << endl;

        Observer the last test case carefully, do know why code will fail
         */
        auto last = unique(begin(v), end(v));
        v.erase(last, end(v));
        if (v.size() == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int del = n - v.size();
        for (int i = 1; i < v.size() - 1; i++)
        {
            if (v[i - 1] > v[i] && v[i] > v[i + 1] || (v[i - 1] < v[i] && v[i] < v[i + 1]))
                del++;
        }
        cout << n - del << endl;
    }
    return 0;
}