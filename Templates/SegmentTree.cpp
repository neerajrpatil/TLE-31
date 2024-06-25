#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int n;

public:
    // Constructor
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr);
    }

    // Function to build the segment tree
    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; ++i)
        {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; --i)
        {
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // Function to merge two nodes
    int merge(int leftValue, int rightValue)
    {
        // Implement according to the type of query (sum, min, max, etc.)
        // For sum: return leftValue + rightValue;
        // For min: return min(leftValue, rightValue);
        // For max: return max(leftValue, rightValue);
        // For gcd: return __gcd(leftValue, rightValue);
        // For other operations, implement accordingly.
        return leftValue + rightValue;
    }

    // Function for query operation
    int query(int left, int right)
    {
        left += n;
        right += n + 1;
        // Initialize result variable based on the type of query
        // For sum: Initialize with 0
        // For min: Initialize with INT_MAX
        // For max: Initialize with INT_MIN
        // For gcd: Initialize with 0
        // For other operations, initialize appropriately.
        int result = 0;
        while (left < right)
        {
            if (left & 1)
            {
                result = merge(result, tree[left]);
                ++left;
            }
            if (right & 1)
            {
                --right;
                result = merge(result, tree[right]);
            }
            left /= 2;
            right /= 2;
        }
        return result;
    }

    // Function to update a value
    void update(int index, int value)
    {
        index += n;
        tree[index] = value;
        while (index > 1)
        {
            index /= 2;
            tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
        }
    }
};

int main()
{
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree st(arr);

    // Example queries
    std::cout << st.query(0, 3) << endl; // Query for sum or other operations
    // st.update(2, 10);               // Update a value
    std::cout << st.query(0, 2) << endl; // Query after update

    return 0;
}
