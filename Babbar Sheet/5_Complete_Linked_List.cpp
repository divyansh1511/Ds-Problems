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

node* reverseInkgroup(node* head , int k){
    node* curr = head;
    node* prev = NULL;
    node* tmp = NULL;
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
        head->next = reverseInkgroup(tmp , k);
    }
    return prev;
}

bool DetectAndRemoveLoop(node* root){
    node* slow = root;
    node* fast = root;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout<<"LOOP FOUND"<<endl;
            while (slow->next != root->next)
            {
                slow = slow->next;
                root = root->next;
            }
            slow->next = NULL;
            return true;
        }
    }
    return false;
}

node* removeDuplicateSortedList(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == tmp->next->data)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return head;
}

node* RemoveDuplicatesUnsortedList(node* head){
    map<int,bool> mp;
    node* ans = head;
    node* tmp = head->next;
    mp[ans->data] = true;
    while (tmp != NULL)
    {
        if (mp[tmp->data])
        {
            ans->next = tmp->next;
        }
        else
        {
            ans = ans->next;
        }
        tmp = tmp->next;
    }
    return ans;
}

node* movetofront(node* head){
    node* tmp = head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    node* t = tmp->next;
    tmp->next = NULL;
    t->next = head;
    return t;
}

node* addonetoLL(node* head){
    node* a = reverseLL(head);
    node* tmp = a;
    int carry = 1;
    node* prev = NULL;
    while (tmp != NULL && carry != 0)
    {
        int sum = tmp->data + carry;
        tmp->data = sum%10;
        carry = sum/10;
        prev = tmp;
        tmp = tmp->next;
    }
    if (carry != 0)
    {
        prev->next = new node(carry);
    }
    a = reverseLL(a);
    return a;
}

node* add2list(node* h1 , node* h2){
    h1 = reverseLL(h1);
    h2 = reverseLL(h2);
    node* newnode = new node(-1);
    node* tmp = newnode;
    int carry = 0;
    while (h1 != NULL || h2 != NULL || carry != 0)
    {
        int sum = carry;
        if (h1 != NULL)
        {
            sum += h1->data;
        }
        if (h2 != NULL)
        {
            sum += h2->data;
        }
        newnode->next = new node(sum%10);
        carry = sum/10;
        newnode = newnode->next;
    }
    return tmp->next;
}

node* AllIntersectionPoint(node* h1 , node* h2){
    node* newnode = NULL;
    node* ans = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            h1 = h1->next;
        }
        else if (h1->data > h2->data)
        {
            h2 = h2->next;
        }
        else
        {
            if (newnode == NULL)
            {
                newnode = h1;
                ans = h1;
            }
            else
            {
                newnode->next = h1;
                newnode = newnode->next;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    return ans;
}

node* IntersectionPointof2(node* h1 , node* h2){
    int n = 0;
    node* tmp1 = h1;
    while (tmp1 != NULL)
    {
        tmp1 = tmp1->next;
        n++;
    }
    int m = 0;
    tmp1 = h2;
    while (tmp1 != NULL)
    {
        tmp1 = tmp1->next;
        m++;
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
    while (h1 != h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
}

node* merge2ll(node* a , node* b){
    node* newnode = NULL;
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    else if (a->data < b->data)
    {
        newnode = a;
        newnode->next = merge2ll(a->next , b);
    }
    else
    {
        newnode = b;
        newnode->next = merge2ll(a , b->next);
    }
    return newnode;
}

node* Mergesort(node* h1){
    if (h1 == NULL || h1->next == NULL)
    {
        return h1;
    }
    node* slow = h1;
    node* fast = h1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    node* tmp = slow->next;
    slow->next = NULL;
    node* a = Mergesort(h1);
    node* b = Mergesort(tmp);
    return merge2ll(a , b);
}

node* pivotele(node* h1 , node* end){
    node* pivot = h1;
    node* newnode = h1->next;
    while (newnode != end)
    {
        if (newnode->data <= pivot->data)
        {
            swap(newnode->data , pivot->data);
        }
        newnode = newnode->next;
    }
    return pivot;
}

void helper(node* h1 , node* end){
    if (h1 == NULL || h1->next == NULL || h1 == end)
    {
        return;
    }
    node* mid = pivotele(h1 , end);
    helper(h1 , mid);
    helper(mid->next , end);
}

void QuickSort(node* h1){
    node* end = NULL;
    helper(h1 , end);
}

bool IsCircular(node* h1){
    node* tmp = h1;
    while (tmp != NULL && tmp != h1)
    {
        tmp = tmp->next;
    }
    return (tmp == h1);
}

void SplitCirculartList(node* h1 , node* &t1 , node* &t2){
    if (h1 == NULL || h1->next == NULL)
    {
        return;
    }
    node* slow = h1;
    node* fast = h1->next;
    while (fast != h1 && fast->next != h1)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next = h1;
    t1 = h1;

    t2 = tmp;
    node* curr = tmp;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = t2;
}

bool IsPalindrome(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next = NULL;
    tmp = reverseLL(tmp);
    while (tmp != NULL)
    {
        if (tmp->data != head->data)
        {
            return false;
        }
        tmp = tmp->next;
        head = head->next;
    }
    return true;
}

node* DeleteFromCircularLinkedList(node* h1 , int k){
    if (h1->data == k)
    {
        node* t = h1;
        while (t->next != h1)
        {
            t = t->next;
        }
        t->next = h1->next;
        return t->next;
    }
    else
    {
        node* t = h1;
        while (t->next->data == k)
        {
            t = t->next;
        }
        t->next = t->next->next;
        return h1;
    }
}

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node* ReverseDoublyLinkedList(Node* h1){
    Node* curr = h1;
    Node* tmp = NULL;
    while (curr != NULL)
    {
        tmp = curr->next;
        curr->next = curr->prev;
        curr->prev = tmp;
        h1 = curr;
        curr = curr->prev;
    }
    return h1;
}

vector<vector<int>> PairWithGivenSum(Node* head , int sum){
    Node* f = head;
    Node* s = head;
    vector<vector<int>> ans;
    while (s->next != NULL)
    {
        s = s->next;
    }
    while (f != s && s->next != f)
    {
        if (f->data + s->data == sum)
        {
            ans.push_back({f->data , s->data});
            f = f->next;
            s = s->prev;
        }
        else if (f->data + s->data < sum)
        {
            f = f->next;
        }
        else
        {
            s = s->prev;
        }
    }
    return ans;
}

int countPairs(Node* first, Node* second, int value)
{
    int count = 0;
    while (first != NULL && second != NULL && 
           first != second && second->next != first) {
        if ((first->data + second->data) == value) {
            count++;
            first = first->next;
            second = second->prev;
        }
        else if ((first->data + second->data) > value)
            second = second->prev;
        else
            first = first->next;
    }
    return count;
}

int CountTriplets(Node* head , int sum){
    Node* f = head;
    Node* s = head;
    while (s->next != NULL)
    {
        s = s->next;
    }
    int count = 0;
    for (Node* curr = head; curr != NULL; curr = curr->next)
    {
        f = curr->next;
        count += countPairs(f , s , sum-curr->data);
    }
    return count;
}

void rotateByN(Node* &head, int pos)
{
    if(pos==0){
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
    int count=1;
    while(count<=pos)
    {
        head=head->next;
        temp=temp->next;
        count++;
    }
    temp->next=NULL;
    head->prev=NULL;
}

void push(Node** head_ref, Node* new_node)
{
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node *current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }
    newHead->prev = NULL;
    return newHead;
}

// Flatten A Linked List : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

node* segregate(node *head) {
    node* zs = new node(-1);
    node* ze = zs;
    node* os = new node(-1);
    node* oe = os;
    node* ts = new node(-1);
    node* te = ts;
    while(head != NULL){
        if(head->data == 0){
            zs->next = head;
            zs = zs->next;
        }
        else if(head->data == 1){
            os->next = head;
            os = os->next;
        }
        else{
            ts->next = head;
            ts = ts->next;
        }
        head = head->next;
    }
    ts->next = NULL;
    os->next = te->next;
    zs->next = oe->next;
    return ze->next;
}

// Copy List With Random Pointer : https://leetcode.com/problems/copy-list-with-random-pointer/

node* mergeKlist(vector<node*> v){
    node* ans = NULL;
    for (int i = 0; i < v.size(); i++)
    {
        ans = merge2ll(ans , v[i]);
    }
    return ans;
}

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    int mod = pow(10 , 9)+7;
    long long a = 0;
    while(l1 != NULL){
        a = (a*10 + l1->data)%mod;
        l1 = l1->next;
    }
    long long b = 0;
    while(l2 != NULL){
        b = (b*10 + l2->data)%mod;
        l2 = l2->next;
    }
    a = a%mod;
    b = b%mod;
    long long ans = (a*b)%mod;
    return ans;
}

node *compute(node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prev = reverseLL(head);
    node*temp = prev;
    node* tt;
    node* curr = prev;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->data < prev->data){
            tt = curr->next;
            curr->next = tt->next;
            delete tt;
        }
        else{
            curr = curr->next;
            prev = curr;
        }
    }
    node* a = reverseLL(temp);
    return a;
}

node* segregateevenandodd(int N, node *head){
    node* e = new node(-1);
    node* est = e;
    node* o = new node(-1);
    node* ost = o;
    while(head != NULL){
        if(head->data%2 == 0){
            e->next = head;
            e = e->next;
        }
        else{
            o->next = head;
            o = o->next;
        }
        head = head->next;
    }
    o->next = NULL;
    e->next = ost->next;
    return est->next;
}

node* NthnodeFromEnd(node* head , int n){
    node* slow = head;
    node* fast = head;
    while (n--)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}



int main(){

}