#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int countSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ngr(n), ngl(n);

    // Next Greater Element to the Right (NGR)
    stack<int> s;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && nums[i] >= nums[s.top()])
        {
            s.pop();
        }
        ngr[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Next Greater Element to the Left (NGL)
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            s.pop();
        }
        ngl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    long long count = 0;
    for (int i = 0; i < n; ++i)
    {
        long long left = i - ngl[i] + 1;  // Include the current element
        long long right = ngr[i] - i + 1; // Include the current element
        count += (left * right) / 2;      // Divide by 2 to avoid double counting
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 4, 3, 3, 2};
    cout << "Output: " << countSubarrays(nums) << endl; // Expected output: 6

    return 0;
}
