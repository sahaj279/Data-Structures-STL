#include <iostream>
using namespace std;

class CQueue
{
    int *arr;
    int front;
    int last;
    int size;

public:
    CQueue()
    {
        arr = new int[10];
        front = 0;
        last = 0;
        size = 10;
    }
    CQueue(int n)
    {
        arr = new int[n];
        front = 0;
        last = 0;
        size = n;
    }
    void enqueue(int a);
    void dequeue();
    void display();
};

void CQueue::display()
{
    if (front == last)
        return;

    int i = front + 1;

    do
    {

        printf("%d ", arr[i]);
        i = (i + 1) % size;
    } while (i != (last + 1) % size);

    printf("\n");
}
void CQueue::dequeue()
{
    if (front == last)
        cout << "queue empty\n";

    front = (front + 1) % size;
}
void CQueue::enqueue(int a)
{
    if (((last + 1) % size) == front)
    {
        cout << "Queue overflow\n";
        return;
    }

    last = (last + 1) % size;
    arr[last] = a;
}

int main()
{
    // implementing queue using an array
    CQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.enqueue(6);
    q.dequeue();
    q.enqueue(7);
    q.enqueue(7);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}