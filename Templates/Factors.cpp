#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n)
{
    vector<int> t;

    for (int i = 1; i <= sqrt(n); i++)
    {

                if (n % i == 0)
        {
            if (n / i == i)
                t.push_back(i);
            else
            {
                t.push_back(i);
                t.push_back(n / i);
            }
        }
    }

    return t;
}
int main()
{
    return 0;
}
