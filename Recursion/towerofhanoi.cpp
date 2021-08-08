#include <iostream>
using namespace std;
void towerofhanoi(int n, int A, int B, int C)
{
    if (n > 0)
    {
        towerofhanoi(n - 1, A, C, B);
        cout << "moving disk " << n << " from tower " << A << " to tower " << C << endl;
        towerofhanoi(n - 1, B, A, C);
    }
}
int main()
{
    int num;
    cout << "Enter number of disks ";
    cin >> num;
    //Tower A=1,Tower B=2,Tower C=3
    towerofhanoi(num, 1, 2, 3);
    cout << "Congrats you managed to move all the disks! ";
    return 0;
}
