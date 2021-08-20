#include <iostream>
using namespace std;
int count_words(char *s)
{
    int i = 0, words = 1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            words++;
        }
    }
    return words;
}
int main()
{
    char s[20] = {0};
    cout << " Enter a string" << endl;
    cin.getline(s, 20);
    cout << count_words(s);
    return 0;
}