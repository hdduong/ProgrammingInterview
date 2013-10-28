#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class node_int {

	int data;
	node_int *next;

public: 
	node_int(int new_data, node_int* new_next) {
		setData(new_data);
		setNext(new_next);
	}
	
	int getData() { 
		return data; 
	}

	void setData(int new_data) {
		data = new_data;
	}

	node_int* getNext() {
		return next;
	}

	void setNext(node_int *new_next) {
		next = new_next;
	}


};


bool detectCycle(node_int *list, node_int **meet_node) {
	node_int *slow_node;
	node_int *fast_node;

	slow_node = list;
	fast_node = list;

	while ( (fast_node->getNext() != NULL)  && (fast_node != NULL) && (slow_node != NULL) ) {
		fast_node = fast_node->getNext()->getNext();			//run 2 steps
		if (fast_node == slow_node) {
			*meet_node = fast_node;
			return true;
		}

		slow_node = slow_node->getNext();
		if (slow_node == fast_node) {
			*meet_node = slow_node;
			return true;
		}
	}

	if ( (fast_node->getNext() == NULL) || (fast_node == NULL) || (slow_node == NULL) ) {
		return false;
	}
	return true;

}

node_int* getFirstCycleNode(node_int *list, node_int *start_node) {
	// assume that list has cycle
	node_int *slow_node = list;
	node_int *fast_node = start_node->getNext()->getNext();	 //IMPORTANT

	while(fast_node!= slow_node) {
		fast_node = fast_node->getNext();
		slow_node = slow_node->getNext();
	}

	//equal
	return slow_node;
}

void main_7_2() {
	node_int *node_1 = new node_int(1,NULL);
	node_int *node_2 = new node_int(2,NULL);
	node_int *node_3 = new node_int(3,NULL);
	node_int *node_4 = new node_int(4,NULL);
	node_int *node_5 = new node_int(5,NULL);

	node_int *list = node_1;
	node_int *meet_node = node_1;
	node_int *cycle_node = node_1;

	bool has_cycle = false;

	node_1->setNext(node_2);
	node_2->setNext(node_3);
	node_3->setNext(node_4);
	node_4->setNext(node_5);
	node_5->setNext(node_2);
	//node_5->setNext(NULL);

	has_cycle = detectCycle(list,&meet_node);
	cycle_node = getFirstCycleNode(list,meet_node);

	cout << has_cycle << "\n" << meet_node->getData() << "\n" << cycle_node->getData() << endl;



	delete node_1;
	delete node_2;
	delete node_3;
	delete node_4;
	delete node_5;
}