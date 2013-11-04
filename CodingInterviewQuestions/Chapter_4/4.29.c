#include <stdio.h>
#include <stdlib.h>

typedef struct int_node  {
	int data;
	struct int_node *next;
} int_node, node;

node* reservePair(node* head) {
	node* tmp;
	node *tmp2;

	if (head == NULL)
		return NULL;
	
	tmp = head->next;
	if (tmp == NULL)
		return head;
	
	
	tmp2 = tmp->next;
	
	head->next = tmp2;
	tmp->next = head;
	head = tmp;
	tmp = tmp->next;

	tmp->next = reservePair(tmp2);

	return head;


}

void printList_1(struct int_node *L) {
	struct int_node *tmp = L;

	while (tmp != NULL) {
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}


void main() {
	node* tmp; 

	node* node1 = (node*) malloc(sizeof(node));
	node* node2 = (node*) malloc(sizeof(node));
	node* node3 = (node*) malloc(sizeof(node));
	node* node4 = (node*) malloc(sizeof(node));

	node1->data = 1; node1->next = node2;
	node2->data = 2; node2->next = node3;
	node3->data = 3; node3->next = node4;
	node4->data = 4; node4->next = NULL;
	printList_1(node1);

	tmp = reservePair(node1);
	printList_1(tmp);

	free(node1);
	free(node2);
	free(node3);
	free(node4);
}