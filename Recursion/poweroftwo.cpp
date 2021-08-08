#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 2 == 0)
            return isPowerOfTwo(n / 2);
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
    if (sol.isPowerOfTwo(n))
    {
        cout << "The number is power of 2";
    }
    else
    {
        cout << "Not a power of 2";
    }
    return 0;
}