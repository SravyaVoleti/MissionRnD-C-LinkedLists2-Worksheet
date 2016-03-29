/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	struct node *ptr,*preptr,*temp;
	int len = 0,m,c = 0,median = 0;

	ptr = head;
	preptr = head;
	temp = head;
	if (head == NULL)
		return -1;
	while (ptr != NULL) {
		len++;
		ptr = ptr->next;
	}
	m = len / 2;
	if (len % 2 != 0) {
		while (preptr != NULL) {
			if (c == m) {
				median = preptr->num;
				break;
			}
			c++;
			preptr = preptr->next;
		}
		return median;
	}
	else if (len % 2 == 0) {
		while (temp != NULL) {
			if (m == c) {
				temp = preptr->next;
				median = (temp->num + preptr->num) / 2;
				break;
			}
			c++;
			preptr = temp;
			temp = temp->next;
		}
	}
	return median;
}
