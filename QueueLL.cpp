#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
};

class Queue
{
    node *last;
    node *front;

public:
    int size;
    Queue()
    {
        size = 0;
        last = front = NULL;
    }
    void enqueue(int a);
    void dequeue();
    void display();
};

void Queue::enqueue(int a)
{
    node *n = new node(a);
    if (n == NULL)
    {
        cout << "Queue overflow\n";
        return;
    }
    if (front==NULL)
    {
        last = n;
        front = n;
        size++;
        return;
    }
    last->next = n;
    last=last->next;
    size++;
}
void Queue::display()
{
    if (front)
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}
void Queue::dequeue()
{
    if (front == NULL)
    {
        cout << "Queue empty\n";
        return;
    }
    node *temp = front;
    size--;
    front = front->next;
    delete temp;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.size;

    return 0;
}