#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T>
class Node {
public:
	T		data;
	Node	*next;
	
	Node(T dt, Node *n) {
		data = dt;
		next = n;
	}
};


template<class T>
class AuxStack {
private: 
	Node<T> *top;
public:
	AuxStack();  
	void	pop();
	void	push(T t);
	bool	isEmpty();
	T		getMax();
	void	dispose();
	void	printAuxStack();
};

template <class T>
AuxStack<T>::AuxStack() {
	top = NULL;
}

template <class T>
bool AuxStack<T>::isEmpty() {
	return (top == NULL);
}

template <class T>
void AuxStack<T>::push(T t) {
	Node<T> *tmp = new Node<T>(t,NULL);
	Node<T> *prev;

	if (isEmpty()) {
		top = tmp;
	}
	else {
		prev = top;
		tmp->next = top;
		top= tmp;
		if (tmp->data < prev->data) {
			tmp->data = prev->data;
		}
	}
}


template<class T>
void AuxStack<T>::pop() {
	Node<T> *tmp = top;
	if (isEmpty()) {
		throw("Stack is empty");
	}
	top = top->next;
	//return tmp->data;
}

template<class T>
T AuxStack<T>::getMax() {
	Node<T> *tmp = top;

	if (isEmpty()) {
		throw("Stack is empty");
	}
	top = top->next;
	return tmp->data;
}


template<class T>
void AuxStack<T>::dispose() {
	Node<T> *tmp;
	while (top!= NULL) {
		tmp = top;
		top = top->next;
		delete(tmp);
	}
}

template<class T>
void AuxStack<T>::printAuxStack() {
	Node<T> *tmpAux = top;

	while (tmpAux!= NULL) {
		cout << tmpAux->data << " ";
		tmpAux = tmpAux->next;
		
	}
	cout << "\n";
}



template<class T>
class Stack {
private: 
	Node<T> *top;
	AuxStack <T> *auxStack;  
public:
	Stack();  
	T		pop();
	void	push(T t);
	bool	isEmpty();
	T		getMax();
	void	dispose();
	void	printStack();
};


template<class T>
Stack<T>::Stack() {
	top = NULL;
	auxStack = new AuxStack<T>;
}


template<class T>
bool Stack<T>::isEmpty() {
	return (top == NULL);
}

template<class T>
void Stack<T>::push(T t) {
	Node<T> *tmp = new Node<T>(t,NULL);

	if (isEmpty()) {
		top = tmp;
	}
	else {
		tmp->next = top;
		top= tmp;
	}

	auxStack->push(t);
}

template<class T>
T Stack<T>::pop() {
	Node<T> *tmp = top;
	if (isEmpty()) {
		throw("Stack is empty");
	}
	top = top->next;
	auxStack->pop;
	return tmp->data;
}


//** getMax is for auxiliary Stack */
template<class T>
T Stack<T>::getMax() {
	return auxStack->getMax();
}


template<class T>
void Stack<T>::dispose() {
	Node<T> *tmp;
	while (top!= NULL) {
		tmp = top;
		top = top->next;
		delete(tmp);
	}
	auxStack->dispose();
}


template<class T>
void Stack<T>::printStack() {
	Node<T> *tmp = top;
	
	
	while (tmp!= NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
		
	}
	cout << "\n";
	auxStack->printAuxStack();
}




void main_8_1() {
	Stack<int> *head = new Stack<int>;
	int max;

	head->push(1);
	head->push(3);
	head->push(2);

	

	head->printStack();

	max = head->getMax();
	cout << max << "\n";

	cout << "\n";
}