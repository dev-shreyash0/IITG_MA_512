#include <iostream>

using namespace std;

template <class T> class BinaryMaxHeap {

private: T * aux;
		 int size;

public : BinaryMaxHeap(T * arr, int n);
		 BinaryMaxHeap(T * arr, int lo, int hi);	

private: 
	     void buildMaxHeap();
		 void sink(int k);
		 bool less(int i, int j);
		 void exch(int i, int j);	

};

template <class T> BinaryMaxHeap<T>::BinaryMaxHeap(T * arr, int n) {
	BinaryMaxHeap(arr, 0, n-1);
}

template <class T> BinaryMaxHeap<T>::BinaryMaxHeap(T * arr, int lo, int hi) {
	
	size = hi-lo+1;
	aux = new T[size+1];
	for (int i = lo; i <= hi; i++) aux[i-lo+1] = arr[i];
	buildMaxHeap();
	for (int i = lo; i <= hi; i++) arr[i] = aux[i-lo+1];

}

template <class T> void BinaryMaxHeap<T>::buildMaxHeap() {
	for (int i = size/2; i >= 1; i--) sink(i);
}

template <class T> void BinaryMaxHeap<T>::sink(int k) {

	while (2*k <= size) {
		int j = 2*k;
		if (j < size && less(j, j+1)) j++;
		if (!less(k, j)) break;
		exch(k, j);
		k = j;
	}
	
}

template <class T> bool BinaryMaxHeap<T>::less(int i, int j) {
	if (aux[i] < aux[j]) return 1;
	else return 0;
}

template <class T> void BinaryMaxHeap<T>::exch(int i, int j) {
	T temp = aux[i];
	aux[i] = aux[j];
	aux[j] = temp;
}