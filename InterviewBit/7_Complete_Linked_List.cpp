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

node* SortBinaryList(node* head){
    node* even = new node(-1);
    node* st = even;
    node* odd = new node(-1);
    node* oddst = odd;
    while (head != NULL)
    {
        if (head->data == 0)
        {
            even->next = head;
            even = even->next;
        }
        else
        {
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    even->next = oddst->next;
    return st->next;
}

node* PartitionList(node* head , int key){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* less = new node(-1);
    node* t1 = less;
    node* moreeq = new node(-1);
    node* t2 = moreeq;
    while (head != NULL)
    {
        if (head->data < key)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            moreeq->next = head;
            moreeq = moreeq->next;
        }
        head = head->next;
    }
    less->next = t2->next;
    moreeq->next = NULL;
    return t1->next;
}

node* InsertionSort(node* head){
    node* dmy = new node(10000);

    while (head)
    {
        node* n = head->next;
        node* tmp = dmy;

        while (tmp->next && tmp->next->data < head->data)
        {
            tmp = tmp->next;
        }
        head->next = tmp->next;
        tmp->next = head;
        head = n;
    }
    return dmy->next;
}

node* Merge2ll(node* head1 , node* head2){
    node* newnode = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if (head1->data < head2->data)
    {
        newnode = head1;
        newnode->next = Merge2ll(head1->next , head2);
    }
    else
    {
        newnode = head2;
        newnode->next = Merge2ll(head1 , head2->next);
    }
    return newnode;
}

node* mergeSort(node* head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* t = slow->next;
    slow->next = NULL;
    return Merge2ll(mergeSort(head) , mergeSort(t));
}

node* reve(node* head){
    node* curr = head;
    node* prev = NULL;
    node* temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool IsPalindrome(node* head){
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next =NULL;
    node* t = reve(tmp);
    while (t != NULL)
    {
        if (t->data != head->data)
        {
            return false;
        }
        t = t->next;
        head = head->next;
    }
    return true;
}

node* RemoveDuplicatesII(node* A){
    if(A == NULL || A->next == NULL){
        return A;
    }
    node* temp = A;
    while(A->next != NULL && A->next->data == A->data){
        A = A->next;
    }
    if(temp == A){
        A->next = RemoveDuplicatesII(A->next);
        return A;
    }
    else{
        A = A->next;
        return RemoveDuplicatesII(A);
    }
}

node* RemoveDuplicates(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* curr = head;
    while (curr->next)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

node* removenthnodefromend(node* head , int k){
    node* slow = head;
    node* fast = head;
    while (k != 0)
    {
        fast = fast->next;
        k--;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

node* reverseList(node* A, int B) {
    node* prev = NULL;
    node* curr = A;
    node* temp = NULL;
    int count = 0;
    while(curr != NULL && count < B){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if(temp != NULL){
        A->next = reverseList(temp , B);
    }
    return prev;
}

node* EvenReverse(node* A) {
    if(!A || !A->next || !A->next->next) return A;
    stack<int> s;
    int len = 0;
    node*curr = A;
    while(curr) {
        len+=1;
        if(len%2 == 0) 
            s.push(curr->data);
        curr = curr->next;
    }
    curr = A;
    len = 0;
    while(curr) {
        len += 1;
        if(len%2 == 0) {
            curr->data = s.top();
            s.pop();
        }
        curr = curr->next;
    }
    return A;
}

node* swapPairs(node* A) {
    node* prev = NULL;
    node* current = A;
    node* nextptr;

    int k = 2, count = 0;
    while(current!=NULL && count<k){
        nextptr = current->next;
        current->next = prev;
        prev = current;
        current= nextptr;
        count++;
    }
    if(nextptr!=NULL){
        A->next = swapPairs(nextptr);
    }
    return prev;
}

node* rotateRight(node* A, int B) {
    if(B==0 || A==NULL){
        return A;
    }
    int count=0;
    node* p=A;
        
    while(p->next){
        p=p->next;
        count++;
    }
    count++;
    p->next=A;
    p=p->next;
        
    int temp=count-(B%count);
    node* q=nullptr;
    while(temp>0){
        if(temp==1){
            q=p;
        }
        temp--; 
        p=p->next;
    }
    q->next=nullptr;        
    return p;
}

int kthnodefromMid(node* A, int B) {
    node* slow = A;
    node* fast = A;
    int mid = 0;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        mid++;
    }
    if(mid < B){
        return -1;
    }
    int count = mid - B;
    node* curr = A;
    for(int i=0;i<count;i++){
        curr = curr->next;
    }
    return curr->data;
}

node* fun(node* A, int B,int flag){
    node* prev=NULL;
    node* curr=NULL;
    node* temp=A;
    int k=0;
    if(flag){
        while(temp!=NULL && k++<B ){
            
            curr=temp;
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            
        }
        if(temp!=NULL){
            A->next=fun(temp,B,1-flag);
        }
        return prev;   
    }
    else{
        while(temp!=NULL && k++<B){
            prev=temp;
            temp=temp->next;
        }
        if(temp!=NULL){
            prev->next=fun(temp,B,1-flag);
        }
        return A;
    }   
}
node* RverseAlternateKnodes(node* A, int B) {
    return fun(A,B,1);
}

node* reverseBetween(node* head, int m, int n) {
       
    node *dummy = new node(0), *pre = dummy, *cur;
    dummy -> next = head;
    for (int i = 0; i < m - 1; i++) {
        pre = pre -> next;
    }
    cur = pre -> next;
    for (int i = 0; i < n - m; i++) {
        node* temp = pre -> next;
        pre -> next = cur -> next;
        cur -> next = cur -> next -> next;
        pre -> next -> next = temp;
    }
    return dummy -> next;
}

node* reorderList(node* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    node* slow = A;
    node* fast = A->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* temp = slow->next;
    slow->next = NULL;
    temp = reve(temp);
    node* ans = Merge2ll(A , temp);
    return ans;
}

node* addTwoNumbers(node* A, node* B) {
    node* first = A;
    node* second = B;
    node* temp = new node(10);
    node* ans = temp;
    int a = 0 , b = 0;
    int carry = 0;
    while(first != NULL || second != NULL || carry > 0){
        if(first != NULL){
            a = first->data;
            first = first->next;
        }
        if(second != NULL){
            b = second->data;
            second = second->next;
        }
        int sum = a + b + carry;
        node* newnode = new node(sum%10);
        carry = sum/10;
        temp->next = newnode;
        temp = newnode;
        a = b = 0;
    }
    return ans->next;
}

node* detectCycle(node* A) {
    node* slow = A;
    node* fast = A;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(A!=slow){
                A=A->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}


int main(){
    
}