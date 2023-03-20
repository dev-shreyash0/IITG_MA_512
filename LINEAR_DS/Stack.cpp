#include <iostream>
#include <vector>

using namespace std; 

template <class T> class Stack {

private: class Node;

private: Node * first;
		 int n;

public : Stack();	
		 bool isEmpty();          // checks is my stack empty
		 int  size();			  // returns size of stack
		 void push(T item);       // inserts the item at top of stck
		 T    pop();              // removes the item form top of the stack
		 T    peek();	 		  // returns the item on top of the stack	
		 void items(vector<T> &v);
		 vector<T> & items();

};

template <class T> class Stack<T>::Node {
	
public : T item;
		 Node * next;

public : Node(T item) {
		 	this->item = item;
		 	this->next = NULL;
		 }

};

template <class T> Stack<T>::Stack() {
	first = NULL;
	n     = 0;
}

template <class T> bool Stack<T>::isEmpty() {
	return first == NULL;
}

template <class T> int Stack<T>::size() {
	return n;
}

template <class T> void Stack<T>::push(T item) {
	
	if (first == NULL) {
		first = new Node(item);
	} else {
		Node * temp = new Node(item);
		temp->next     = first;
		first          = temp;
	}
	n++;

}

template <class T> T Stack<T>::pop() {
	
	if (isEmpty()) throw underflow_error("Stack underflow");

	T item = first->item;
	first  = first->next;
	n--;
	return item;
		
}

template <class T> T Stack<T>::peek() {
	
	if (isEmpty()) throw underflow_error("Stack underflow");
	
	return first->item;

}


template <class T> void Stack<T>::items(vector<T> &v) {
	
	Node * ptr = first;

	while (ptr != NULL) {
		v.push_back(ptr->item);
		ptr = ptr->next;
	}
	
}




template <class T> vector<T> & Stack<T>::items() {
	
	vector<T> * v = new vector<T>();

	Node * ptr = first;

	while (ptr != NULL) {
		(*v).push_back(ptr->item);
		ptr = ptr->next;
	}

	return (*v);

}


