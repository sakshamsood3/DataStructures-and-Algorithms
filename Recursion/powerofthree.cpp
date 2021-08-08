#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 3 == 0)
            return isPowerOfThree(n / 3);
        else
            return false;
    }
};
int main()
{
    Solution sol;
    cout << "Enter a number to check ";
    int n;
    cin >> n;
    if (sol.isPowerOfThree(n))
    {
        cout << "The number is power of 3";
    }
    else
    {
        cout << "Not a power of 3";
    }
    return 0;
}