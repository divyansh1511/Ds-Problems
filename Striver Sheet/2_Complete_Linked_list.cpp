#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;
    
    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
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
        cin>>data;
    }
    return head;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* reverseLL(node* head){
    node* temp = NULL;
    node* curr = head;
    node* prev = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

node* MidNode(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge2ll(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = merge2ll(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = merge2ll(head1 , head2->next);
    }
    return newnode;
}

node* removeNthnodefromEnd(node* head , int k){
    node* fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    node* slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

node* Add2Numbers(node* head1 , node* head2){
    node* newnode = new node(-1);
    node* ans = newnode;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = carry;
        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        newnode->next = new node(sum%10);
        carry = sum/10;
        newnode = newnode->next;
    }
    return ans->next;
}

void deleteNode(node* &nod){
    nod->data = nod->next->data;
    nod->next = nod->next->next;
}

node* IntersectionPoint(node* head1 , node* head2){
    node* tmp1 = head1;
    int n = 0;
    while (tmp1 != NULL)
    {
        n++;
        tmp1 = tmp1->next;
    }
    int m = 0;
    node* tmp2 = head2;
    while (tmp2 != NULL)
    {
        m++;
        tmp2 = tmp2->next;
    }
    tmp1 = head1;
    tmp2 = head2;
    if (n > m)
    {
        for (int i = 0; i < (n-m); i++)
        {
            tmp1 = tmp1->next;
        }
    }
    else
    {
        for (int i = 0; i < (m-n); i++)
        {
            tmp2 = tmp2->next;
        }
    }
    while (tmp1 != NULL)
    {
        if (tmp1 == tmp2)
        {
            return tmp1;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return NULL;
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;
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

node* reverseLLinKgrp(node* head , int k){
    node* tmp = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
        count++;
    }
    if (tmp != NULL)
    {
        head->next = reverseLLinKgrp(tmp , k);
    }
    return prev;
}

bool CheckPalindrome(node* head){
    node* mid = MidNode(head);
    node* t1 = mid->next;
    mid->next = NULL;
    t1 = reverseLL(t1);
    while (head != NULL)
    {
        if (head->data != t1->data)
        {
            return false;
        }
        head = head->next;
        t1 = t1->next;
    }
    return true;
}

node* cyclestartpoint(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    while (slow->next != head->next)
    {
        slow = slow->next;
        head = head->next;
    }
    return slow->next;
}

//FLATTEN A LINKED LIST --> USING MERGE2LIST

node* rotatelist(node* head , int k){
    node* tmp = head;
    int n = 0;
    while (tmp->next)
    {
        tmp = tmp->next;
        n++;
    }
    n++;
    tmp->next = head;
    tmp = tmp->next;
    int c = n - (k%n);
    node* t = NULL;
    while (c>0)
    {
        if (c == 1)
        {
            t = tmp;
        }
        tmp = tmp->next;
        c--;
    }
    t->next = NULL;
    return tmp;
}

//----COPY LIST WITH RANDOM POINTERS-----//



int main(){

}