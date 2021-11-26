#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void display(node *head)
{
    node *temp = head;
    for (; temp != 0; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << "\n";
}
void insert(node *&head, int data, int pos)
{ // the data would be inserted after ith position
  // and first node is considered to be at 1
    if (pos < 0)
        return;
    node *t = new node(data);
    node *p = head;
    if (pos == 0)
    { // to insert at head ,pos 0
        t->next = p;
        head = t;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p) // if p is null ,return
        {
            t->next = p->next;
            p->next = t;
        }
    }
}
node *last = 0;
void insertTail(node *&head, int val)
{
    node *t = new node(val);
    if (head == 0)
    {
        head = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void insertSorted(node *&head, int val)
{
    node *t = new node(val);
    node *p = head;
    if (val <= p->data)
    {
        t->next = p;
        head = t;
    }
    else
    {
        while (p->next)
        {
            if (p->next->data > val)
                break;
            p = p->next;
        }
        if (p->next == NULL)
        {
            p->next = t;
        }
        else
        {
            t->next = p->next;
            p->next = t;
        }
    }
}
void deleteNode(node *&head, int pos)
{ // the ele at given index will be deleted
    if (pos <= 0 || head == NULL)
        return;
    node *p = head;
    if (pos == 1) // we are deleteing head
    {
        node *t = head;
        head = head->next;
        delete t;
    }
    else
    {
        node *p = head;
        for (int i = 0; i < pos - 2 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            node *t = p->next;
            p->next = t->next;
            delete t;
        }
        else return;
    }
}
int main()
{
    // node *head = new node(10);//initially, head has data and points null
    node *head = 0; // initially head is null
    insert(head, 0, 0);
    insert(head, 11, 1);
    insert(head, 12, 2);
    insert(head, 3, 3);
    insert(head, 4, 4);
    insert(head, 5, 4);
    insert(head, 0, 8);
    display(head);//0 11 12 3 5 4
    deleteNode(head,0);//nothing gets deleted
    deleteNode(head,1);// 0 deleted
    deleteNode(head,5);//4 deleted
    deleteNode(head,15);//nothing gets deleted as 15 is out of bound
    // insertTail(head, 100);//doesnt work
    display(head);
    node *h1 = 0;
    insertTail(h1, 1);
    insertTail(h1, 2);
    insertTail(h1, 3);
    insertTail(h1, 4);
    insertTail(h1, 7);
    insertSorted(h1, 6);
    insertSorted(h1, 5);
    display(h1);

    return 0;
}