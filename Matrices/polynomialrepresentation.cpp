#include <iostream>
using namespace std;
class Term
{
public:
    int coeff;
    int exp;
};
class Polynomial
{
public:
    int terms;
    Term *term;
    Polynomial() {}
    Polynomial(int terms)
    {
        this->terms = terms;
        term = new Term[terms];
    }
    ~Polynomial()
    {
        delete[] term;
    }
    Polynomial operator+(Polynomial &p1)
    {
        int i = 0, j = 0, k = 0;
        Polynomial *final = new Polynomial(terms + p1.terms);
        while (i < terms && j < p1.terms)
        {
            if (term[i].exp > p1.term[j].exp)
            {
                final->term[k++] = term[i++];
            }
            else if (term[i].exp < p1.term[j].exp)
            {
                final->term[k++] = p1.term[j++];
            }
            else
            {
                final->term[k].exp = term[i].exp;
                final->term[k++].coeff = term[i++].coeff + p1.term[j++].coeff;
            }
        }
        for (i; i < terms; i++)
        {
            final->term[k++] = term[i];
        }
        for (i; i < p1.terms; i++)
        {
            final->term[k++] = p1.term[j];
        }
        final->terms = k;
        return *final;
    }
    friend istream &operator>>(istream &is, Polynomial &p);
    friend ostream &operator<<(ostream &os, Polynomial &p);
};
istream &operator>>(istream &is, Polynomial &p)
{
    for (int i = 0; i < p.terms; i++)
    {
        cout << "Enter the coefficient and exponent of x" << endl;
        cin >> p.term[i].coeff >> p.term[i].exp;
    }
    return is;
}
ostream &operator<<(ostream &os, Polynomial &p)
{
    for (int i = 0; i < p.terms; i++)
    {
        cout << p.term[i].coeff << "x^" << p.term[i].exp << "+ ";
    }
    cout << endl;
    return os;
}
int main()
{
    Polynomial p(5);
    Polynomial p1(3);
    cout << "Enter the terms of first Polynomial" << endl;
    cin >> p;
    cout << "Enter the terms of second Polynomial" << endl;
    cin >> p1;
    Polynomial final = p + p1;
    cout << "First Polynomial is" << endl;
    cout << p;
    cout << "Second Polynomial is" << endl;
    cout << p1;

    cout << "Sum of two Polynomials is" << endl;
    cout << final << endl;
    return 0;
}