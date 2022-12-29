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

void PrintLinkedList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

vector<int> linkedListToArray(node *head)
{
    vector<int> v;
    while (head != NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }
    return v;
}

void printLinkedListReverse(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printLinkedListReverse(head->next);
    cout << head->data << " ";
}

node *kthElement(node *head, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        head = head->next;
    }
    return head;
}

node *addAtkthElement(node *head, int k, node *newElement)
{
    if (k == 1)
    {
        newElement->next = head;
        return newElement;
    }
    node *t = head;
    k--;
    while (k != 1)
    {
        t = t->next;
        k--;
    }
    node *temp = t->next;
    t->next = newElement;
    newElement->next = temp;
    return head;
}

node *removekthElement(node *head, int k)
{
    if (k == 1)
    {
        return head->next;
    }
    node *t = head;
    k--;
    while (k != 1)
    {
        t = t->next;
        k--;
    }
    node *temp = t->next;
    t->next = temp->next;
    return head;
}

node *appendLists(node *list1, node *list2)
{
    node *t = list1;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = list2;
    return list1;
}

node *reverseLinkedList(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node *removeOccurences(node *head, int key)
{
    while (head != NULL && head->data == key)
    {
        head = head->next;
    }
    node *t = head;
    while (t != NULL && t->next != NULL)
    {
        if (t->next->data == key)
        {
            t->next = t->next->next;
        }
        else
        {
            t = t->next;
        }
    }
    return head;
}

node* midele(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge2sorted(node *h1, node *h2)
{
    node *newnode = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    else if (h2 == NULL)
    {
        return h1;
    }
    else if (h1->data < h2->data)
    {
        newnode = h1;
        newnode->next = merge2sorted(h1->next, h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2sorted(h1, h2->next);
    }
    return newnode;
}

void deleteNode(node *node)
{
    while (node->next != NULL)
    {
        node->data = node->next->data;
        if (node->next->next == NULL)
        {
            break;
        }
        node = node->next;
    }
    node->next = NULL;
}

bool isPalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *tmp = slow->next;
    slow->next = NULL;
    tmp = reverseLinkedList(tmp);
    while (tmp != NULL)
    {
        if (head->data != tmp->data)
        {
            return false;
        }
        head = head->next;
        tmp = tmp->next;
    }
    return true;
}

node *getIntersectionNode(node *A, node *B)
{
    node *tmp = A;
    int n1 = 0, n2 = 0;
    while (tmp != NULL)
    {
        n1++;
        tmp = tmp->next;
    }
    tmp = B;
    while (tmp != NULL)
    {
        n2++;
        tmp = tmp->next;
    }
    if (n1 > n2)
    {
        int d = n1 - n2;
        for (int i = 0; i < d; i++)
        {
            A = A->next;
        }
    }
    else
    {
        int d = n2 - n1;
        for (int i = 0; i < d; i++)
        {
            B = B->next;
        }
    }
    while (A != B)
    {
        A = A->next;
        B = B->next;
    }
    return A;
}

node *removeDuplicates(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *ans = head;
    while (ans->next != NULL)
    {
        if (ans->data == ans->next->data)
        {
            ans->next = ans->next->next;
        }
        else
        {
            ans = ans->next;
        }
    }
    return head;
}

node *removeDuplicates(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *ans = head;
    while (head->next != NULL && head->data == head->next->data)
    {
        head = head->next;
    }
    if (ans == head)
    {
        head->next = removeDuplicates(head->next);
        return head;
    }
    else
    {
        head = head->next;
        return removeDuplicates(head);
    }
}

node *kthnodefromend(node *head, int k)
{
    node *t = head;
    for (int i = 0; i < k; i++)
    {
        t = t->next;
    }
    while (t != NULL)
    {
        t = t->next;
        head = head->next;
    }
    return head;
}

node *removeXthNodeFromEnd(node *head, int x)
{
    node *slow = head;
    node *fast = head;
    for (int i = 1; i < x; i++)
    {
        fast = fast->next;
    }
    if (fast->next == NULL)
    {
        return head->next;
    }
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

node *addTwoNumbers(node *firstList, node *secondList)
{
    int sum = 0, carry = 0;
    node *ans = new node(-1);
    node *t = ans;
    while (firstList != NULL || secondList != NULL || carry != 0)
    {
        sum = 0;
        if (firstList)
        {
            sum = firstList->data;
            firstList = firstList->next;
        }
        if (secondList)
        {
            sum += secondList->data;
            secondList = secondList->next;
        }
        sum += carry;
        ans->next = new node(sum % 10);
        carry = sum / 10;
        ans = ans->next;
    }
    return t->next;
}

node *reverseLinkedListRange(node *head, int m, int n)
{
    node *dummy = new node(0), *pre = dummy, *cur;
    dummy->next = head;
    for (int i = 0; i < m - 1; i++)
    {
        pre = pre->next;
    }
    cur = pre->next;
    for (int i = 0; i < n - m; i++)
    {
        node *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
    }
    return dummy->next;
}

node *reverseLinkedListKGroup(node *head, int k)
{
    node *currentNode = head;
    int totalNodes = 0;
    while (currentNode != NULL && totalNodes < k)
    {
        currentNode = currentNode->next;
        totalNodes++;
    }
    if (totalNodes < k)
    {
        return head;
    }
    currentNode = head;
    node *prevNode = NULL;
    node *nextNode = NULL;
    int nodeCount = 0;
    while (nodeCount < k)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nodeCount++;
    }
    head->next = reverseLinkedListKGroup(nextNode, k);
    return prevNode;
}

node* addOneToList(node* head) {
	node* h1 = reverseLinkedList(head);
	node* tmp = h1;
	int carry = 1;
	node* prev = NULL;
	while(tmp != NULL){
		int sum = tmp->data + carry;
		tmp->data = sum%10;
		carry = sum/10;
		prev = tmp;
		tmp = tmp->next;
	}
	if(carry != 0){
		prev->next = new node(carry);
	}
	return reverseLinkedList(h1);
}

node* reorderList(node* head) {
	if(head == NULL){
		return head;
	}
	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	node* tmp = slow->next;
	slow->next = NULL;
	tmp = reverseLinkedList(tmp);
	
	node *n1=head,*n2=tmp;
	while(n1 && n2){
		node* temp = n2->next;
		n2->next = n1->next;
		n1->next = n2;
		n2 = temp;
		n1 = n1->next->next;
    }
	return head;
}

node* rotateListByK(node* head, int k) {
	if(head == NULL || head->next == NULL){
		return head;
	}
	int n = 0;
	node* a = head;
	while(a != NULL){
		n++;
		a = a->next;
	}
	k = k%n;
	node* t = head;
	for(int i=0;i<(n-k-1);i++){
		t = t->next;
	}
	node* ans = t->next;
	t->next = NULL;
	node* v = ans;
	while(v->next != NULL){
		v = v->next;
	}
	v->next = head;
	return ans;
}

node* getStartingNodeOfLoop(node* list){
	if(list == NULL || list->next == NULL){
		return NULL;
	}
	node* slow = list->next;
	node* fast = list->next->next;
	while(fast != NULL && fast->next != NULL){
		if(slow == fast){
			slow = list;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL || fast->next == NULL) {
		return NULL;
	}
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

void removeLoop(node* list) {
    if (list == NULL || list->next == NULL) {
		return;
	}
	node *slowPtr = list->next, *fastPtr = list->next->next;
	node *prevNode = list->next;
	while (fastPtr != NULL && fastPtr->next != NULL) {
		if(slowPtr == fastPtr) {
			slowPtr = list;
			break;
		}
		slowPtr = slowPtr->next;
		prevNode = fastPtr->next;
		fastPtr = fastPtr->next->next;
	}
	if (fastPtr == NULL || fastPtr->next == NULL) {
		return;
	}
	while (slowPtr != fastPtr) {
		prevNode = fastPtr;
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	prevNode->next = NULL;
	return;
}

node* flattenTheLinkedList(node* root) {
	if(root == NULL){
		return root;
	}
	return merge2sorted(root , flattenTheLinkedList(root->next));
}

node* partitionList(node* head, int key) {
	node* smallerHead = NULL, *equalHead = NULL, *greaterHead = NULL;
	node* smallerLast = NULL, *equalLast = NULL, *greaterLast = NULL;
	while (head != NULL) {
		if (head->data < key) {
			if(smallerHead == NULL) {
				smallerHead = smallerLast = head;
			} else {
				smallerLast->next = head;
				smallerLast = smallerLast->next;
			} 
		} else if (head->data == key) {
			if (equalHead == NULL) {
				equalHead = equalLast = head;
			} else {
				equalLast->next = head;
				equalLast = equalLast->next;
			}
		} else {
			if (greaterHead == NULL) {
				greaterHead = greaterLast = head;
			} else {
				greaterLast->next = head;
				greaterLast = greaterLast->next;
			}
		}
		head = head->next;
	}
	if (greaterHead != NULL) {
		greaterLast->next = NULL;
	}
	if (equalHead == NULL) {
		if (smallerHead == NULL) {
			smallerHead = greaterHead;
		} else {
			smallerLast->next = greaterHead;
		}
	} else {
		equalLast->next = greaterHead;
		if (smallerHead == NULL) {
			smallerHead = equalHead;
		} else {
			smallerLast->next = equalHead;
		}
	}
	return smallerHead;
}

node* mergeSort(node* head) {
	if (head->next == NULL) {
		return head;
	}
	node* midNode = midele(head);
	node* secondHalf = mergeSort(midNode->next);
	midNode->next = NULL;
	node* firstHalf = mergeSort(head);
	return merge2sorted(firstHalf, secondHalf);
}

int main()
{
    
}