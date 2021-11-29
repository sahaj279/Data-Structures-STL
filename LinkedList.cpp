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
        else
            return;
    }
}
void removeDuplicate(node *&head)//for sorted list
{
    node *p = head;
    node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
void reverse(node *&head){
    //reversing links using sliding pointer
    node *p=head;
    node *q=NULL;
    node *r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;

    }
    head=q;
}
void concat(node *&first,node *&second){
    node *p=first;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=second;
    second=NULL;
}
int main()
{
    // node *head = new node(10);//initially, head has data and points null
    node *head = 0; // initially head is null
    insert(head, 0, 0);
    insert(head, 0, 1);
    insert(head, 0, 2);
    insert(head, 3, 3);
    insert(head, 3, 4);
    insert(head, 3, 4);
    insert(head, 0, 4);
    removeDuplicate(head);
    display(head);        // 0 11 12 3 5 4
    deleteNode(head, 0);  // nothing gets deleted
    deleteNode(head, 1);  // 0 deleted
    deleteNode(head, 5);  // 4 deleted
    deleteNode(head, 15); // nothing gets deleted as 15 is out of bound
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
    reverse(h1);//7 6 5 4 3 2 1 
    concat(h1,head);
    display(h1);//7 6 5 4 3 2 1 3 0 3

    return 0;
}