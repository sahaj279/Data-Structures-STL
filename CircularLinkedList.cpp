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
        next = this;
    }
};
void display(node *head)
{
    node *p = head;
    if (p) // head is not null
    {
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << "\n";
    }
}
int length(node *head)
{
    int l = 0;
    node *p = head;
    if (p != NULL) // head is not null
    {
        do
        {
            l++;
            p = p->next;

        } while (p != head);
        return l;
    }
    else
        return 0;
}
void insert(node *&head, int index, int val)
{
    node *t = new node(val); // node to be inserted
    node *p = head;
    if (p == NULL) // t will be the first node
    {
        head = t;
        return;
    }
    if (index < 0 || index > length(head))
        return;              // invalid index
    else
    {
        if (index == 0)
        {
            do
            {
                p = p->next;
            } while (p->next != head);
            p->next = t;
            t->next = head;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
}
void Delete(node *&head, int index)
{
    if (index <= 0 || index>length(head))
        return;
    // i=1 means head and i =l means last node
    // the ith element would get deleted
    node *p = head;
    node *q = NULL;
    if (index == 1)
    { // deleting head/first node
        q = p;
        do
        {
            q = q->next;
        } while (q->next != head);
        q->next = p->next;
        head = p->next;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}
int main()
{
    node *head = NULL;
    // display(head);
    insert(head, 1, 1);
    display(head);
    insert(head, 1, 2); // index 1 means no.2 will be inserted after the 1st element
    // if index was 0 , element would be inserted before head
    insert(head, 2, 3);
    insert(head, 2, 4);
    insert(head, 0, 5); // inserting before head same as inserting at last
    display(head);      // 1 2 4 3 5
    Delete(head, 3);    // 3rd element gets deleted
    Delete(head,1);
    Delete(head,3);
    display(head);
    

    return 0;
}