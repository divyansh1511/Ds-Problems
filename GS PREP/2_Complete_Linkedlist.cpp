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

//-----------------------------Reverse a LL ----------------------------//

node* reverseLL(node* head){
    node* curr = head;
    node* prev = NULL;
    node* tmp = NULL;

    while (curr != NULL)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

//------------------------------Middle of LL ------------------------------//

node* middlenode(node* head){
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//-----------------------------merge 2 sorted LL -----------------------------//

node* merge2LL(node* h1 , node* h2){
    node* newnode = NULL;
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
        newnode->next = merge2LL(h1->next , h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2LL(h1 , h2->next);
    }
}

//------------------------------Remove Nth node from end ---------------------------//

node* removeNthNode(node* head , int k){
    node* fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    node* slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next = tmp->next;
    return head;
}

//--------------------------------Add 2 numbers as LL --------------------------//

node* add2num(node* h1 , node* h2){
    int sum = 0;
    int carry = 0;
    node* dmy = new node(-1);
    node* ans = dmy;
    while (h1 != NULL || h2 != NULL || carry != 0)
    {
        sum = carry;
        if (h1)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        dmy->next = new node(sum%10);
        carry = sum/10;
        dmy = dmy->next;
    }
    return ans->next;
}

//--------------------------------delete a node in LL --------------------------//

void deletenode(node* h1){
    h1->data = h1->next->data;
    h1->next = h1->next->next;
}

//-------------------------------Intersection of 2 LL -------------------------------//

node* Intersectingnode(node* h1 , node* h2){
    int n = 0;
    node* tmp = h1;
    while (tmp != NULL)
    {
        n++;
        tmp = tmp->next;
    }
    int m = 0;
    tmp = h2;
    while (tmp != NULL)
    {
        m++;
        tmp = tmp->next;
    }
    if (n > m)
    {
        for (int i = 0; i < (n-m); i++)
        {
            h1 = h1->next;
        }
    }
    else
    {
        for (int i = 0; i < (m-n); i++)
        {
            h2 = h2->next;
        }
    }
    while (h1 != NULL)
    {
        if (h1 == h2)
        {
            return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

//------------------------------Detect a Cycle ----------------------------//

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL || fast->next != NULL)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return false;
}

//-------------------------------Reverse a LL in grp of K ------------------------//

node* reverseIngrpofK(node* head , int k){
    node* curr = head;
    node* tmp = NULL;
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
        head->next = reverseIngrpofK(tmp , k);
    }
    return prev;
}

//------------------------------check Palindrome LL -----------------------------------//

bool isPalindrome(node* head){
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node* tmp = middlenode(head);
    node* h2 = tmp->next;
    tmp->next = NULL;
    h2 = reverseLL(h2);
    while (head != NULL && h2 != NULL)
    {
        if (head->data != h2->data)
        {
            return false;
        }
        head = head->next;
        h2 = h2->next;
    }
    return false;
}

//--------------------------------FLatten a LL----//

//-----------------------------clone ll random pointer----//


//---------------------------Swap Nodes --------------------------//

node* swapPairs(node* h1){
    if (h1 == NULL || h1->next == NULL)
    {
        return h1;
    }
    node* tmp = h1->next;
    h1->next = swapPairs(tmp->next);
    tmp->next = h1;

    return tmp;
}

//-----------------------------------

int main(){

}