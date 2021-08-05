#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    int num;
    cout << "Enter the number you want the factorial for ";
    cin >> num;
    cout << "The factorial of " << num << " is " << factorial(num);
    return 0;
}