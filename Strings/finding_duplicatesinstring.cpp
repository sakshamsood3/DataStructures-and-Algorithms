#include <iostream>
using namespace std;
void find_duplicates(char *s)
{
    int i, j;
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    for (i = 0; i < len; i++)
    {
        int cnt = 1;
        for (j = i + 1; j < len + 1; j++)
        {
            if (s[i] == s[j])
            {
                cnt++;
                s[j] = -1;
            }
        }
        if (cnt > 1 && s[i] != -1)
        {
            cout << "Element " << s[i] << " occurs " << cnt << " times" << endl;
        }
    }
}
void find_duplicates_hashing(char *s)
{
    int s1[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        s1[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] > 1)
        {
            cout << "Element " << (char)(i + 97) << " occurs " << s1[i] << " times" << endl;
        }
    }

} //works only for a string having lowercase else take array of size 122
void find_duplicate_bitwise(char *s)
{
    int H = 0, x = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x << (s[i] - 97);
        if ((x & H) > 0)
        {
            cout << s[i] << " is duplicate" << endl;
        }
        else
            H = x | H;
        ;
    }
}
int main()
{
    char s[] = "HelloWorld ByeWorld";
    char s1[] = "howareyoubro";
    char s2[] = "hello";
    cout << "Duplicates in first string " << endl;
    find_duplicates(s);
    cout << "Duplicates in second string" << endl;
    find_duplicates_hashing(s1);
    find_duplicate_bitwise(s2);
    return 0;
}