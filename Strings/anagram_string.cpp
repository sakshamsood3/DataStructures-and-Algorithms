#include <iostream>
#include <cstring>
using namespace std;
void anagram(char *s, char *s1)
{
    if (strlen(s) != strlen(s1))
        cout << "Not an anagram" << endl;
    else
    {
        int H[26], i = 0;
        for (i = 0; s[i] != '\0'; i++)
        {
            H[s[i] - 97]++;
        }
        for (int i = 0; s1[i] != 0; i++)
        {
            H[s[i] - 97]--;
            if (H[s[i] - 97] < 0)
            {
                cout << "Not an anagram" << endl;
                break;
            }
        }
        if (s1[i] == '\0')
            cout << "Its an anagram" << endl;
    }
}
int main()
{
    char s[] = "random";
    char s1[] = "smandon";
    char s3[] = "se";
    char s4[] = "modran";
    anagram(s, s1);
    anagram(s1, s3);
    anagram(s, s4);
    return 0;
}