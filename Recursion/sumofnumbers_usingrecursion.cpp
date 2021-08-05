#include <iostream>
using namespace std;
int sum_numbers(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum_numbers(n - 1);
}
int main()
{
    int num;
    cout << "Enter the no. of terms for which you want the sum of natural numbers ";
    cin >> num;
    cout << "The sum of first " << num << " natural numbers is " << sum_numbers(num);
    return 0;
}
//Note: Loop is better in this case because space complexity is less
//the best method is to use the formula n*(n+1)/2 because it has constant time complexity