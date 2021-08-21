#include <iostream>
using namespace std;
#include <string>
#include <cstring>
bool check_palindrome(char *s)
{
    int len;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    char s1[len + 1];
    int i = 0;
    for (int j = len - 1; j >= 0; j--)
    {
        s1[i++] = s[j];
    }
    s1[i] = '\0';
    cout << s1 << endl;
    if (strcmp(s, s1) == 0)
        return true;
    else
        return false;
}
int main()
{
    char s[] = "madam";
    if (check_palindrome(s))
    {
        cout << "Palindrome string";
    }
    else
        cout << "Not a Palindrome";
}