#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int pow;
};
class Poly
{
    int num; // no. of terms
    Term *arr;

public:
    Poly(int num)
    {
        this->num = num;
        arr = new Term[num];
    }
    ~Poly()
    {
        delete[] arr;
    }
    void show();
    void read();
    Poly operator+(Poly &b);
};

Poly Poly::operator+(Poly &b)
{
    Poly *c = new Poly(num + b.num);
    int i = 0, j = 0, k = 0;
    while (i < num && j < b.num)
    {
        if (arr[i].pow < b.arr[j].pow)
        {
            c->arr[k++] = b.arr[j++];
        }
        else if (arr[i].pow > b.arr[j].pow)
        {
            c->arr[k++] = arr[i++];
        }
        else
        {
            if (arr[i].coeff + b.arr[j].coeff != 0)
            {
                c->arr[k].pow = arr[i].pow;
                c->arr[k++].coeff = arr[i].coeff + b.arr[j].coeff;
            }
            i++;
            j++;
        }
    }
    for (; i < num; i++)
    {
        c->arr[k++] = arr[i];
    }
    for (; j < b.num; j++)
    {
        c->arr[k++] = arr[j];
    }
    c->num = k;
    return *c;
}
void Poly::show()
{
    int i;
    for (i = 0; i < num - 1; i++)
    {
        cout << arr[i].coeff << "x^" << arr[i].pow << "+ ";
    }
    cout << arr[i].coeff << "x^" << arr[i].pow << "\n";
}
void Poly::read()
{

    int i;
    cout << "Enter the coeff and the power of terms\n";
    for (i = 0; i < num; i++)
    {
        cin >> arr[i].coeff >> arr[i].pow;
    }
}
int main()
{
    Poly p(3);//3 2 4 1 7 0
    p.read();
    Poly q(4);//8 3 6 2 -4 1 3 0
    q.read();
    Poly r = p + q;
    r.show();

    return 0;
}