#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
// make less_equal to make it multiset
// dont use index trick for using set as multiset,ratether use multiset itself by using less_equal

// template one

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

Order Statistics:

find_by_order(k): Returns an iterator to the k-th element in the set (0-based indexing).
order_of_key(x): Returns the number of elements in the set that are strictly less than x.


*/

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;

*/

// paste them outside class

int main()
{
    ordered_set os;
    // os.find_by_order(t1)->first;
    // os.insert({a[i],i});
    // this template is for pair

    main()
    {

        if (fork() && fork())
        {
            fork();
        }
        print(1);
    }
    return 0;
}