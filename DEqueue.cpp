#include <iostream>
using namespace std;

class DEqueue
{
    int *arr;
    int f; // front
    int l; // last
    int size;

public:
    DEqueue()
    {
        size = 10;
        f = l = -1;
        arr = new int[size];
    }
    DEqueue(int a)
    {
        size = a;
        f = l = -1;
        arr = new int[size];
    }
    void insertLast(int a);
    void removeLast();
    void removeFront();
    void insertFront(int a);
    void display();
};

void DEqueue::insertLast(int a)
{
    if (l == size - 1)
    {
        cout << "overflow\n";
        return;
    }

    l++;
    arr[l] = a;
}
void DEqueue::removeLast()
{
    if (l == f)
    {
        cout << "empty\n";
        return;
    }

    l--;
}
void DEqueue::insertFront(int a)
{
    if (f < 0)
    {
        cout << "overflow , no space in front\n";
        return;
    }

    arr[f] = a;
    f--;
}
void DEqueue::removeFront()
{
    if (l == f)
    {
        cout << "empty\n";
        return;
    }

    f++;
}
void DEqueue::display()
{
    if (f == l)
        return;
    for (int i = f + 1; i <= l; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    DEqueue d(5);
    d.insertFront(1);
    d.insertLast(1);
    d.insertLast(2);
    d.insertLast(3);
    d.insertLast(4);
    d.insertLast(5);
    d.insertLast(6);
    d.display();
    d.removeFront();
    d.removeLast();
    d.display();
    d.insertFront(9);
    d.display();

    return 0;
}