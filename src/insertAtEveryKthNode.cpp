/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	int count = 1,len = 0;
	struct node *ptr, *preptr,*newnode;
	ptr = head;
	
	if (head == NULL)
		return NULL;

	if (K == 0)
		return head;

	while (ptr->next != NULL) {
		len++;
		ptr = ptr->next;
	}

	if (K > len)
		return head;
	preptr = head;
	ptr = head->next;
	while (ptr!= NULL) {
		
		if (count % K == 0) {
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			preptr->next = newnode;
			newnode->next = ptr;
			count = 0;
		}
		count++;
		preptr = ptr;
		ptr = ptr->next;
		

	}
	if (K == 1) {
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = K;
		preptr->next = newnode;
		newnode->next = NULL;
		}
	return head;
	
}
