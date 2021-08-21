#include <iostream>
#include <algorithm>
using namespace std;
void permutations(char s[], int k)
{
    static int A[10] = {0};
    static char res[10];
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                permutations(s, k + 1);
                A[i] = 0;
            }
        }
    }
}
void permutations2(char s[], int l, int h)
{
    int i;
    if (l == h)
        cout << s << endl;
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[i], s[l]);
            permutations2(s, l + 1, h);
            swap(s[i], s[l]);
        }
    }
}
int main()
{
    char s[] = "ABC";
    cout << "Permutations are " << endl;
    permutations2(s, 0, 2); //we can use permutations() function as well
    return 0;
}