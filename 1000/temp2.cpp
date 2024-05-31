#include <iostream>
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

int main()
{
    cout << "\t\t\tKey is the name of the beautiful series used!" << endl;
    cout << "\t\t\tTIP --> THIS PROGRAM IS USELESS IF YOU HAVE NOT FINISHED MID TASK! (DON'T CHANGE ANYTHING IN THE CODE!)" << endl;

    string key = "fibonacci";

    int arr1[] = {0, 0, 0, 2, 0, 0, 1, 6, 5, 4, 0, 7, 8};
    int arr2[] = {8, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    cout << "Enter all the outputs separated by space: ";
    string ans = "";

    for (int i = 1; i < 14; i++)
    {
        int x;
        x = i;
        // cin >> x;

        // Calculate target character '{' value in reverse
        char target = '{';
        int targetZ = target - asciiCalc(key);

        // Rearrange the equation to solve for x
        x = (targetZ - 10 * ((i * arr2[i - 1]) + arr1[i - 1]) - asciiCalc(key)) % 10;

        // Output the value of x
        // cout << "Value of x for position " << i << ": " << x << endl;
        cout << i << " ";
        // Generate the string
        char z = (10 * ((i * arr2[i - 1]) + arr1[i - 1])) + (x % 10) + asciiCalc(key);
        ans.push_back(z);
    }
    cout << endl;

    cout << "Final answer: " << ans << endl;

    return 0;
}
