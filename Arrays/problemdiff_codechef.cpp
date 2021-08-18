#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int arr[] = {a, b, c, d};
        sort(arr, arr + 4);
        int max_count = 1, current_count = 1, res = arr[0];
        for (int i = 1; i < 4; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                current_count++;
            }
            else
            {
                if (current_count > max_count)
                {
                    max_count = current_count;
                    res = arr[i - 1];
                }
                current_count = 1;
            }
        }
        if (current_count > max_count)
        {
            max_count = current_count;
            res = arr[3];
        }
        if (max_count == 4)
            cout << 0 << endl;
        else if (max_count == 3)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        t--;
    }
}
