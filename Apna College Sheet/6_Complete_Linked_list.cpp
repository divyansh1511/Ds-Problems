#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    node *head = NULL;
    node *tail = NULL;

    int data;
    cin >> data;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

node *reverseLL(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *tmp = NULL;
    while (curr != NULL)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

bool IsCycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

node *merge2sortedLL(node *h1, node *h2)
{
    node *newnode = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    if (h1->data < h2->data)
    {
        newnode = h1;
        newnode->next = merge2sortedLL(h1->next, h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2sortedLL(h1, h2->next);
    }
    return newnode;
}

void DeleteNode(node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node *prev = NULL;
        while (head->next != NULL)
        {
            head->data = head->next->data;
            prev = head;
            head = head->next;
        }
    }
}

void removeDuplicates(node *head)
{
    node *ptr1 = head;
    node *ptr2;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                ptr2->next = ptr2->next->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

node *sort012(node *head)
{
    node *zs = NULL, *ze = NULL;
    node *os = NULL, *oe = NULL;
    node *ts = NULL, *te = NULL;

    while (head != NULL)
    {
        if (head->data == 0)
        {
            if (zs == NULL)
            {
                zs = head;
                ze = head;
            }
            else
            {
                ze->next = head;
                ze = head;
            }
        }
        else if (head->data == 1)
        {
            if (os == NULL)
            {
                os = head;
                oe = head;
            }
            else
            {
                oe->next = head;
                oe = head;
            }
        }
        else
        {
            if (ts == NULL)
            {
                ts = head;
                te = head;
            }
            else
            {
                te->next = head;
                te = head;
            }
        }
        head = head->next;
    }
    ze->next = os;
    oe->next = ts;
    return zs;
}

long long multiplyLL(node *h1, node *h2)
{
    int a = 0;
    while (h1 != NULL)
    {
        a = a * 10 + h1->data;
        h1 = h1->next;
    }
    int b = 0;
    while (h2 != NULL)
    {
        b = b * 10 + h2->data;
        h2 = h2->next;
    }
    long long ans = a * b;
    return ans;
}

node *removeNthnodefromend(node *head, int k)
{
    node *slow = head;
    node *fast = head;

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

void reorderList(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    node *tmp = prev->next;
    prev->next = NULL;

    tmp = reverseLL(tmp);

    node *n1 = head, *n2 = tmp;
    node *newnode = new node(-1);
    while (n2->next)
    {
        tmp = n1->next;
        n1->next = n2;
        n1 = tmp;

        tmp = n2->next;
        n2->next = n1;
        n2 = tmp;
    }
}

int IntersectionPoint(node *n1, node *n2)
{
    node *p1 = n1, *p2 = n2;

    if (p1 == NULL || p2 == NULL)
    {
        return -1;
    }
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2)
        {
            return p1->data;
        }
        if (p1 == NULL)
        {
            p1 = n2;
        }
        if (p2 == NULL)
        {
            p2 = n1;
        }
    }
    return -1;
}

// Flatten a linked list

node *greaternodesonright(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = reverseLL(head);
    node *temp = prev;
    node *tt;
    node *curr = prev;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->data < prev->data)
        {
            tt = curr->next;
            curr->next = tt->next;
            delete tt;
        }
        else
        {
            curr = curr->next;
            prev = curr;
        }
    }
    node *a = reverseLL(temp);
    return a;
}

node *oddevenSegregrate(node *head)
{
    node *es = NULL, *ee = NULL;
    node *os = NULL, *oe = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (es == NULL)
            {
                es = head;
                ee = head;
            }
            else
            {
                ee->next = head;
                ee = head;
            }
        }
        else
        {
            if (os == NULL)
            {
                os = head;
                oe = head;
            }
            else
            {
                oe->next = head;
                oe = head;
            }
        }
        head = head->next;
    }
    ee->next = os;
    oe->next = NULL;
    return es;
}

/// Random Pointer

node *mergeKLists(vector<node *> &lists)
{
    if (lists.empty())
    {
        return NULL;
    }
    while (lists.size() > 1)
    {
        lists.push_back(merge2sortedLL(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}

node* mergeSort(node* head) {
    if(!head or !(head->next)) return head;
    node *slow=head;
    node *fast=head;
    node *tmp=NULL;
    while(fast and fast->next){
        tmp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    tmp->next=NULL;
    node* f = mergeSort(head);
    node* s = mergeSort(slow);
    return merge2sortedLL(f,s);    
}

int main()
{
    
}