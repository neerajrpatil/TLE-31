#include <bits/stdc++.h>
using namespace std;
vector<int> parent, val;
void Union(int a, int b, int w)
{
    a = get(a);
    b = get(b);
    if (a < b)
    {
        parent[b] = a;
        val[a] &= w;
        val[a] &= val[b];
    }
    else
    {
        parent[a] = b;
        val[b] &= w;
        val[b] &= val[a];
    }
}
int get(int u)
{
    return parent[u] = (parent[u] == u ? u : get(parent[u]));
}
int main()
{
    return 0;
}