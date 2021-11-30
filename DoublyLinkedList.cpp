#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int length(node *head)
{
    int l = 0;
    node *p = head;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
void insert(node *&head, int index, int val)
{
    node *t = new node(val);
    node *p = head;
    if (p == NULL)
    {
        head = t;
        return;
    }
    if (index < 0 || index > length(head))
        return;
    else
    {
        if (index == 0) // inserting before head
        {
            head->prev = t;
            t->next = head;
            head = t;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->prev = p;
            t->next = p->next;
            if (p->next)
                p->next->prev = t;
            p->next = t;
        }
    }
}
void Delete(node *&head, int index)
{
    if (index <= 0 || index > length(head))
        return;
    if (index == 1)
    {
        node *p = head;
        if (head->next)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
            head = NULL;
        delete p;
    }
    else
    {
        node *q = NULL;
        node *p = head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        delete p;
    }
}
void reverse(node *&head)
{
   
    node *temp;
    node*p=head;

    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            head = p;
    }
}
int main()
{
    node *head = NULL;
    insert(head, 1, 1); // head->1
    insert(head, 0, 0); // head->0 1
    insert(head, 2, 2); // head->0 1 2
    insert(head, 2, 3); // head->0 1 3 2
    display(head);
    Delete(head, 1);
    Delete(head, 2);
    Delete(head, 2);
    Delete(head, 1);
    insert(head, 0, 20);
    insert(head, 1, 21);
    insert(head, 2, 22);
    insert(head, 3, 23);
    display(head);
    reverse(head);
    display(head);

    return 0;
}