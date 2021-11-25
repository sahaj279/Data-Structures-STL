#include <iostream>
using namespace std;
class Element
{
public:
    int i;   // holds row num
    int j;   // holds col num
    int num; // the num
};
class SparseMatrix
{
    int m; // no of rows of original matrix
    int n; // no of columns of original matrix
    int l; // length of sparse matrix(num of nonzero elelments)
    Element *e;

public:
    SparseMatrix(int m, int n, int l)
    {
        this->m = m;
        this->n = n;
        this->l = l;
        e = new Element[l];
    }
    ~SparseMatrix()
    {
        delete[] e;
    }
    void read();
    void display();
    SparseMatrix operator+(SparseMatrix &b);
    SparseMatrix operator-(SparseMatrix &b);
};
void SparseMatrix ::read()
{
    cout << "Enter row num, col num and the number itself\n";
    for (int i = 0; i < l; i++)
    {
        cout << i + 1 << ". ";
        cin >> e[i].i >> e[i].j >> e[i].num;
    }
}
void SparseMatrix ::display()
{
    cout << "\n";
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (e[k].i == i && e[k].j == j)
            {
                cout << e[k++].num << " ";
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
SparseMatrix SparseMatrix ::operator+(SparseMatrix &b)
{
    if (m != b.m || n != b.n)
        return SparseMatrix(0, 0, 0);

    SparseMatrix *c = new SparseMatrix(m, n, l + b.l);
    int i = 0, j = 0, k = 0;
    while (i < l && j < b.l)
    {
        if (e[i].i < b.e[j].i)
        {
            c->e[k++] = e[i++];
        }
        else if (e[i].i > b.e[j].i)
        {
            c->e[k++] = b.e[j++];
        }
        else
        {
            if (e[i].j < b.e[j].j)
            {
                c->e[k++] = e[i++];
            }
            else if (e[i].j > b.e[j].j)
            {
                c->e[k++] = b.e[j++];
            }
            else
            {
                if (e[i].num + b.e[j].num != 0)
                {
                    c->e[k].i = e[i].i;
                    c->e[k].j = e[i].j;
                    c->e[k].num = e[i].num + b.e[j].num;
                    k++;
                    i++;
                    j++;
                }
            }
        }
    }
    for (; i < l; i++)
    {
        c->e[k++] = e[i];
    }
    for (; j < b.l; j++)
    {
        c->e[k++] = e[j];
    }
    c->l = k;

    return *c;
}
SparseMatrix SparseMatrix ::operator-(SparseMatrix &b)
{
    if (m != b.m || n != b.n)
        return SparseMatrix(0, 0, 0);

    SparseMatrix *c = new SparseMatrix(m, n, l + b.l);
    int i = 0, j = 0, k = 0;
    while (i < l && j < b.l)
    {
        if (e[i].i < b.e[j].i)
        {
            c->e[k++] = e[i++];
        }
        else if (e[i].i > b.e[j].i)
        {
            c->e[k].i = b.e[j].i;
            c->e[k].j = b.e[j].j;
            c->e[k].num = b.e[j].num * (-1);
            k++;
            j++;
        }
        else
        {
            if (e[i].j < b.e[j].j)
            {
                c->e[k++] = e[i++];
            }
            else if (e[i].j > b.e[j].j)
            {
                c->e[k].i = b.e[j].i;
                c->e[k].j = b.e[j].j;
                c->e[k].num = b.e[j].num * (-1);
                k++;
                j++;
            }
            else
            {
                if (e[i].num - b.e[j].num != 0)
                {
                    c->e[k].i = e[i].i;
                    c->e[k].j = e[i].j;
                    c->e[k].num = e[i].num - b.e[j].num;
                    k++;
                }
                i++;
                j++;
            }
        }
    }
    for (; i < l; i++)
    {
        c->e[k++] = e[i];
    }
    for (; j < b.l; j++)
    {
        c->e[k].i = b.e[j].i;
        c->e[k].j = b.e[j].j;
        c->e[k].num = b.e[j].num * (-1);
        k++;
    }
    c->l = k;

    return *c;
}

int main()
{
    SparseMatrix s(5, 5, 5); // original matrix had 5 rows and columns and 5 non zero elements
    s.read();
    SparseMatrix p(5, 5, 5);
    p.read();
    SparseMatrix c = s + p;
    SparseMatrix d = s - p;
    
    c.display();
    d.display();

    return 0;
}