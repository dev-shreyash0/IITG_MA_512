#include <iostream>
#include <vector>

using namespace std;

template <class T> class Queue {

private: class Node; 
	
private: Node * first;
		 Node * last;
		 int n;

public : Queue();
		 bool isEmpty();
		 int  size();
		 void enqueue(T item);
		 T    dequeue();
		 T    peek();
		 void items(vector<T> &v);
		 vector<T> & items();

};

template <class T> class Queue<T>::Node {
	
public : T  item;
		 Node * next;

public : Node(T item) {
			this->item = item;
			this->next = NULL;
		 }

};

template <class T> Queue<T>::Queue() {
	first = NULL;
	last  = NULL;
	n     = 0;
}

template <class T> bool Queue<T>::isEmpty() {
	return first == NULL;
}

template <class T> int Queue<T>::size() {
	return n;
}

template <class T> void Queue<T>::enqueue(T item) {
	
	if (first == NULL) first = last       = new Node(item);
	else                last = last->next = new Node(item);
	
	n++;

}

template <class T> T Queue<T>::dequeue() {

	if (isEmpty()) throw underflow_error("Queue underflow");

	T item = first->item;

	if (first == last) first = last = NULL;
	else	           first = first->next;
	
	n--;

	return item;

}

template <class T> T Queue<T>::peek() {
	
	if (isEmpty()) throw underflow_error("Queue underflow");

	return first->item;

}



template <class T> void Queue<T>::items(vector<T> &v) {
	
	Node * ptr = first;

	while (ptr != NULL) {
		v.push_back(ptr->item);
		ptr = ptr->next;
	}
	
}




template <class T> vector<T> & Queue<T>::items() {
	
	vector<T> * v = new vector<T>();

	Node * ptr = first;

	while (ptr != NULL) {
		(*v).push_back(ptr->item);
		ptr = ptr->next;
	}

	return (*v);

}


