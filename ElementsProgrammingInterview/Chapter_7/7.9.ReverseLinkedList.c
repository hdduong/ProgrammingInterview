#include <stdlib.h>
#include <stdio.h>

struct int_node {
	int data;
	struct int_node *next;
};

struct int_node *reverseList(struct int_node *list) {
	struct int_node *pre_tmp = NULL;
	struct int_node *tmp = list;
	struct int_node *next_tmp = tmp->next;

	while(next_tmp != NULL) {
		tmp->next = pre_tmp;
		pre_tmp = tmp;
		tmp = next_tmp;
		next_tmp = next_tmp->next;
	}
	tmp->next = pre_tmp;
	list = tmp;

	return list;
}

struct int_node *reverseList_2(struct int_node *list) {
	
	struct int_node *tmp_node; 

	if (list->next == NULL)
		return list;

	tmp_node = reverseList_2(list->next);
	tmp_node->next = list;

	return list;
	
}


void printList_2(struct int_node *L) {
	struct int_node *tmp = L;

	while (tmp != NULL) {
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}


void main () {

	struct int_node* tmp; 

	struct int_node *new_node1 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *new_node2 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *new_node3 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *new_node4 = (struct int_node*)malloc(sizeof(struct int_node));
	struct int_node *new_node5 = (struct int_node*)malloc(sizeof(struct int_node));

	new_node1->data = 1; new_node1->next = new_node2;
	new_node2->data = 2; new_node2->next = new_node3;
	new_node3->data = 3; new_node3->next = new_node4;
	new_node4->data = 4; new_node4->next = new_node5;
	new_node5->data = 5; new_node5->next = NULL;
	
	printList_2(new_node1);

	//tmp = reverseList(new_node1);

	tmp = reverseList(new_node1);

	printList_2(new_node5);

	free(new_node1);
	free(new_node2);
	free(new_node3);
	free(new_node4);
	free(new_node5);

}