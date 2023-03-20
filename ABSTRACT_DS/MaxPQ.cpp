#include <iostream>
using namespace std;

template <class T> class MaxPQ {

private: T * aux;
		 int auxSize;
		 int heapSize;

public : MaxPQ();
		 MaxPQ(T * arr, int n);
	
public : T delMax();
		 void insert(T key);
		 bool isEmpty();
		 T max();
		 int size();

private: bool less(int i, int j);
		 void exch(int i, int j);
		 void sink(int k);
		 void swim(int k);
		 void resize(int size);

};

template <class T> MaxPQ<T>::MaxPQ() {
	aux      = NULL;
	auxSize  = 0;
	heapSize = 0;
}

template <class T> MaxPQ<T>::MaxPQ(T * arr, int n) {
	aux      = NULL;
	auxSize  = 0;
	heapSize = 0;
	for (int i = 0; i < n; i++) insert(arr[i]);
}

template <class T> bool MaxPQ<T>::isEmpty() {
	return heapSize == 0;
}

template <class T> int MaxPQ<T>::size() {
	return heapSize;
}

template <class T> void MaxPQ<T>::insert(T key) {
	
	if (heapSize == auxSize) resize(2*heapSize);

	aux[++heapSize] = key;
	swim(heapSize);

}

template <class T> T MaxPQ<T>::max() {
	if (isEmpty()) throw underflow_error("heap underflow");
	return aux[1];
}

template <class T> T MaxPQ<T>::delMax() {
	if (isEmpty()) throw underflow_error("heap underflow");
	T temp = aux[1];
	aux[1] = aux[heapSize--];
	sink(1);
	if (heapSize <= auxSize/4) resize(heapSize/2);
	return temp;
}

template <class T> bool MaxPQ<T>::less(int i, int j) {
	if (aux[i] < aux[j]) return 1;
	else 				 return 0;
}

template <class T> void MaxPQ<T>::exch(int i, int j) {
	T temp = aux[i];
	aux[i] = aux[j];
	aux[j] = temp;
}

template <class T> void MaxPQ<T>::sink(int k) {
	
	while (2*k <= heapSize) {

		int j = 2*k;
		if (j < heapSize && less(j, j+1)) j++;
		if (!less(k,j)) break;
		exch(k, j);
		k = j;

	}

}

template <class T> void MaxPQ<T>::swim(int k) {
	
	while (k > 1 && less(k/2, k)) {
		exch(k,k/2);
		k = k/2;
	}

}

template <class T> void MaxPQ<T>::resize(int size) {
	
	if (size == 0) size = 2;

	T * temp = new T[size];

	for (int i = 1; i <= heapSize; i++) temp[i] = aux[i];

	auxSize = size;
	aux = temp;

}
