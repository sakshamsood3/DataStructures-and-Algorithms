#include <iostream>
using namespace std;
int main()
{
    char s[] = "WELCOME";
    char p[] = "WeLc34oMe";
    for (int i = 0; s[i] != '\0'; i++) //changing case
    {
        s[i] += 32;
    }
    cout << s << endl;
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 65 && p[i] <= 90)
            p[i] += 32;
        else if (p[i] >= 97 && p[i] <= 122)
            p[i] -= 32;
    }
    cout << p;
    return 0;
}