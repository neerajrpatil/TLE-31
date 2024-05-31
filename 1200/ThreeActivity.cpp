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

    /*
    https://codeforces.com/problemset/problem/1914/D
    I cant iterative over all three array with complexity n^3

    But i can do 3^3 for sure

    in a1,a2,a3,a4,a5,a6,a7,a8
    the element which will be elected will be one among the 3 maximums for sure

    same will happen in b1,b2,b3..

    //i find max 3 without sorting
    //init with -1 to make it easier

    */
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

#define p pair<int, int>
        p a[n], b[n], c[n];
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            a[i] = {ele, i};
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            b[i] = {ele, i};
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            c[i] = {ele, i};
        }
        sort(a, a + n);
        sort(b, b + n);
        sort(c, c + n);
        reverse(a, a + n);
        reverse(b, b + n);
        reverse(c, c + n);
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int I = a[i].second, J = b[j].second, K = c[k].second;
                    if (I == J || J == K || K == I)
                        continue;
                    else
                        ans = max(ans, a[i].first + b[j].first + c[k].first);
                    // i,j,k is new indices, i.e the one after sorting
                    // I,J,K are old indices, i.e as the one given in input
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}