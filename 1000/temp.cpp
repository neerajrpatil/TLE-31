#include <bits/stdc++.h>
using namespace std;
int asciiCalc(string x)
{
    int num = 0;
    for (int i = 0; i < x.size(); i++)
    {
        num += x[i] % 10;
    }
    return num - 6;
}
int main(int argc, char const *argv[])
{
    cout << "\t\t\tKey is the name of the beautiful series used!" << endl;
    cout << "\t\t\tTIP --> THIS PROGRAM IS USELESS IF YOU HAVE NOT FINISHED MID TASK!(DON'T CHANGE ANYTHING IN THE CODE!)" << endl;
    string key = "fibonacci";

    int arr1[] = {0, 0, 0, 2, 0, 0, 1, 6, 5, 4, 0, 7, 8};
    int arr2[] = {8, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    cout << "Enter all the outputs separated by space: ";
    string ans = "";
    for (int i = 36; i < 40 + 10; i++)
    {
        int x = i;

        // 13
        //  cin >> x;
        char z = (10 * ((i * arr2[i - 1]) + arr1[i - 1])) + (x % 10) + asciiCalc(key);
        ans.push_back(z);
        cout << z << " ";
    }
    // cout << ans << endl;
    return 0;
}