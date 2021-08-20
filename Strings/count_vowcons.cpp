#include <iostream>
#include <cstring>
using namespace std;
void count_vowcons(char *s)
{
    int i, vowcount = 0, conscount = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' || s[i] == 'i' || s[i] == 'I')
        {
            vowcount++;
        }
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            conscount++;
        }
    }
    cout << " No. of vowels = " << vowcount << endl;
    cout << "No. of consonants = " << conscount << endl;
}
int main()
{

    char s[100] = {0};
    cout << "Enter a string: ";
    cin.getline(s, 100);
    cout << s << endl;
    count_vowcons(s);
    return 0;
}