#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 == 0)
            return isPowerOfFour(n / 4);
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
    if (sol.isPowerOfFour(n))
    {
        cout << "The number is power of 4";
    }
    else
    {
        cout << "Not a power of 4";
    }
    return 0;
}