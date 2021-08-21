#include <iostream>
using namespace std;
void compare_strings(char *s, char *s1)
{
    int i;
    for (i = 0; s[i] != '\0' && s1[i] != '\0'; i++)
    {
        if (s[i] != s1[i])
            break;
    }
    if (s[i] == s1[i])
        cout << "Two strings are equal" << endl;
    else if (s[i] > s1[i])
        cout << "String 1 is greater" << endl;
    else
        cout << " String 2 is greater" << endl;
}
int main()
{
    char s[] = "Welcome";
    char s1[] = "Welcome";
    compare_strings(s, s1);
}