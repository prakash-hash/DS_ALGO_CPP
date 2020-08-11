#include <iostream>
#include "mergetwoLL.cpp"
#include "midLL.cpp"
Node* newhead = NULL;
Node *tail = NULL;

Node* mergeSort(Node *head) {
    //write your code here
    if(head -> next == NULL)
        return head;
    
    Node *ll1 = NULL;
    Node *ll2 = NULL;
    Node *mid = NULL;
    Node *h1 = NULL;
    Node *h2 = NULL;
    mid = midLL(head);
    ll2 = mid -> next;
    mid -> next = NULL;
    ll1 = head;
    
    h1 = mergeSort(ll1);
    h2 = mergeSort(ll2);
    
    if(newhead == NULL)
    {
    	newhead = mergeTwoLLs(h1,h2);
	tail = head;
    }
    else
	    tail -> next = mergeTwoLLs(h1,h2);
    return newhead;
}

