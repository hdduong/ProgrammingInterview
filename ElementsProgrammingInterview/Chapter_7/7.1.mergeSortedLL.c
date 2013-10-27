#include <stdlib.h>
#include <stdio.h>

typedef struct int_node_1 {
	int data;
	struct int_node_1 *next;
} int_node;


int_node* insertNodeSortList(int_node* L, int_node *insertedNode) {
	int_node *tmp_L = NULL;
	int_node *tmp_prev_L = NULL; 
	
	tmp_L = L;

	while ( (tmp_L != NULL) && (tmp_L->data <= insertedNode->data) ) {
		tmp_prev_L = tmp_L;
		tmp_L = tmp_L->next;
	}

	if (tmp_prev_L == NULL) {								// front
		insertedNode->next = L;
		L = insertedNode;
	} else if (tmp_prev_L != NULL)  {
		if (tmp_L == NULL) {								//end
			tmp_prev_L->next = insertedNode;
		}
		else {												//middle
			tmp_prev_L->next = insertedNode;
			insertedNode->next = tmp_L;
		}
	}
	return L;
}



int_node *mergeList(int_node* L, int_node* R) {
	
	int_node *tmp_R = R;

	while (R != NULL) {
	
		R = tmp_R->next;
		tmp_R->next = NULL;

		L = insertNodeSortList(L,tmp_R);
		tmp_R = R;
	}
	return L;
}


void printList(int_node *L) {
	int_node *tmp = L;

	while (tmp != NULL) {
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void main() {
	int_node *left_list = NULL;
	int_node *right_list = NULL;

	int_node *new_node1 = (int_node*)malloc(sizeof(int_node));
	int_node *new_node2 = (int_node*)malloc(sizeof(int_node));
	int_node *new_node3 = (int_node*)malloc(sizeof(int_node));

	int_node *new_node_R_1 = (int_node*)malloc(sizeof(int_node));
	int_node *new_node_R_2 = (int_node*)malloc(sizeof(int_node));

	new_node1->data = 2;
	new_node1->next = NULL;

	new_node2->data = 7;
	new_node2->next = NULL;

	new_node3->data = 5;
	new_node3->next = NULL;

	left_list = new_node1;

	
	left_list = insertNodeSortList(left_list, new_node2);
	left_list= insertNodeSortList(left_list, new_node3);

	new_node_R_1->data = 3;
	new_node_R_1->next = NULL;

	new_node_R_2->data = 11;
	new_node_R_2->next = NULL;

	right_list = new_node_R_1;

	right_list =  insertNodeSortList(right_list, new_node_R_2);

	printList(left_list);
	printList(right_list);

	left_list = mergeList(left_list,right_list);
	printList(left_list);

}