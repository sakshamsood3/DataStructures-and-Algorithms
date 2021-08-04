#include <iostream>
using namespace std;
void print_num(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        print_num(n - 1);
    }
}
int main()
{
    int x = 3;
    print_num(x);
    return 0;
}