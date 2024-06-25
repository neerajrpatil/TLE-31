#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// for i in range 0 to len(text)-1, if k = z[i+len(pattern)+1] ==len(pattern) then we found ans at i

int main()
{
    vector<int> v = z_function("acdcdacdc$acd");
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return 0;
}