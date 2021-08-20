#include <iostream>
using namespace std;
void rev_string(char *s)
{
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
    }
}
int main()
{
    char s[] = "Hello World 2";
    cout << "Original String " << endl;
    cout << s << endl;
    cout << "Reversed String " << endl;
    rev_string(s);
    cout << s << endl;
    return 0;
}