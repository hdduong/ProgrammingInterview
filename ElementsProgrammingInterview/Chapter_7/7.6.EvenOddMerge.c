#include <stdlib.h>
#include <stdio.h>

struct int_node {
	int data;
	struct int_node *next;
};

void printList_1(struct int_node *L) {
	struct int_node *tmp = L;

	while (tmp != NULL) {
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void createOddEvenList(struct int_node **l0) {
	struct int_node *last_node = *l0;
	struct int_node *tmp_node = *l0;
	struct int_node *after_tmp_node = *l0;

	while(tmp_node->next != NULL) {
		tmp_node = tmp_node->next;
	}
	last_node = tmp_node;

	if (last_node == *l0) {					// only l0 quit
		return;
	}

	last_node->next = (*l0)->next;
	
	tmp_node = *l0;
	after_tmp_node = tmp_node->next;
	while(tmp_node->next != last_node) {
		tmp_node->next = after_tmp_node->next;
		tmp_node = after_tmp_node;
		after_tmp_node = after_tmp_node->next;
	}
	tmp_node->next = NULL;

}

void main() {
	struct int_node *l0 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *l1 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *l2 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *l3 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *l4 = (struct int_node*)malloc(sizeof(struct int_node));

	l0->data = 0; l0->next = l1;
	l1->data = 1; l1->next = l2;
	l2->data = 2; l2->next = l3;
	l3->data = 3; l3->next = l4;
	l4->data = 4; l4->next = NULL;

	printList_1(l0);
	createOddEvenList (&l0);
	printList_1(l0);


	free(l0);
	free(l1);
	free(l2);
	free(l3);
	free(l4);
}

