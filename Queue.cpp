#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int last;
    int size;
    Queue()
    {
        arr = new int[10];
        front = -1;
        last = -1;
        size = 10;
    }
    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        last = -1;
        size = n;
    }
    void enqueue(int a);
    int dequeue();
    void display();
};

void Queue::display()
{
    if (front == -1 || last + 1 == front)
        return;
    for (int i = front; i <= last; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int Queue::dequeue()
{
    if (front == -1 || last + 1 == front)
        return -1;
    int a = front;
    front++;
    return arr[a];
}
void Queue::enqueue(int a)
{
    if (last == size - 1)
    {
        cout << "Queue overflow\n";
        return;
    }

    if (front == -1)
        front++;
    last++;
    arr[last] = a;
}

int main()
{
    // implementing queue using an array
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();

    q.enqueue(6);
    q.display();

    return 0;
}