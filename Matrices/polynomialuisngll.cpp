#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;
void create()
{
    struct Node *t, *last;
    int num;
    cout << "Enter number of terms " << endl;
    cin >> num;
    cout << "Enter each term with coeff and exp " << endl;
    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cin >> t->coeff;
        cin >> t->exp;
        t->next = NULL;
        if (poly == NULL)
        {
            last = t;
            poly = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->coeff << "x^" << p->exp << "+";
        p = p->next;
    }
    cout << endl;
}
long Eval(struct Node *p, int x)
{
    long val;
    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}
int main()
{
    create();
    int x;
    cout << "The representation of the polynomial is" << endl;
    Display(poly);
    cout << "Enter value at which you want to evaluate the expression" << endl;
    cin >> x;
    cout << "Value of the expression at " << x << " is " << Eval(poly, x) << endl;
    return 0;
}