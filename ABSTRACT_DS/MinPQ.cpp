#include <iostream>
using namespace std;

template <class T> class MinPQ {

private: T * aux;
		 int auxSize;
		 int heapSize;

public : MinPQ();
		 MinPQ(T * arr, int n);
	
public : T delMin();
		 void insert(T key);
		 bool isEmpty();
		 T min();
		 int size();

private: bool greater(int i, int j);
		 void exch(int i, int j);
		 void sink(int k);
		 void swim(int k);
		 void resize(int size);

};

template <class T> MinPQ<T>::MinPQ() {
	aux      = NULL;
	auxSize  = 0;
	heapSize = 0;
}

template <class T> MinPQ<T>::MinPQ(T * arr, int n) {
	aux      = NULL;
	auxSize  = 0;
	heapSize = 0;
	for (int i = 0; i < n; i++) insert(arr[i]);
}

template <class T> bool MinPQ<T>::isEmpty() {
	return heapSize == 0;
}

template <class T> int MinPQ<T>::size() {
	return heapSize;
}

template <class T> void MinPQ<T>::insert(T key) {
	
	if (heapSize == auxSize) resize(2*heapSize);

	aux[++heapSize] = key;
	swim(heapSize);

}

template <class T> T MinPQ<T>::min() {
	if (isEmpty()) throw underflow_error("heap underflow");
	return aux[1];
}

template <class T> T MinPQ<T>::delMin() {
	if (isEmpty()) throw underflow_error("heap underflow");
	T temp = aux[1];
	aux[1] = aux[heapSize--];
	sink(1);
	if (heapSize <= auxSize/4) resize(heapSize/2);
	return temp;
}

template <class T> bool MinPQ<T>::greater(int i, int j) {
	if (aux[i] > aux[j]) return 1;
	else 				 return 0;
}

template <class T> void MinPQ<T>::exch(int i, int j) {
	T temp = aux[i];
	aux[i] = aux[j];
	aux[j] = temp;
}

template <class T> void MinPQ<T>::sink(int k) {
	
	while (2*k <= heapSize) {

		int j = 2*k;
		if (j < heapSize && greater(j, j+1)) j++;
		if (!greater(k,j)) break;
		exch(k, j);
		k = j;

	}

}

template <class T> void MinPQ<T>::swim(int k) {
	
	while (k > 1 && greater(k/2, k)) {
		exch(k,k/2);
		k = k/2;
	}

}

template <class T> void MinPQ<T>::resize(int size) {
	
	if (size == 0) size = 2;

	T * temp = new T[size];

	for (int i = 1; i <= heapSize; i++) temp[i] = aux[i];

	auxSize = size;

	aux = temp;

}
