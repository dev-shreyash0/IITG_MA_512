#include <iostream>

using namespace std;

template <class T> class BinaryMinHeap {

private: T * aux;
		 int size;

public : BinaryMinHeap(T * arr, int lo, int hi);
	 BinaryMinHeap(T * arr, int n);

private: 
	     void buildMinHeap();
		 void sink(int k);
		 bool greater(int i, int j);
		 void exch(int i, int j);	

};

template <class T> BinaryMinHeap<T>::BinaryMinHeap(T * arr, int n) {
	BinaryMinHeap(arr, 0, n-1);
}

template <class T> BinaryMinHeap<T>::BinaryMinHeap(T * arr, int lo, int hi) {
	
	size = hi-lo+1;
	aux = new T[size+1];
	for (int i = lo; i <= hi; i++) aux[i-lo+1] = arr[i];
	buildMinHeap();
	for (int i = lo; i <= hi; i++) arr[i] = aux[i-lo+1];

}

template <class T> void BinaryMinHeap<T>::buildMinHeap() {
	for (int i = size/2; i >= 1; i--) sink(i);
}

template <class T> void BinaryMinHeap<T>::sink(int k) {

	while (2*k <= size) {
		int j = 2*k;
		if (j < size && greater(j, j+1)) j++;
		if (!greater(k, j)) break;
		exch(k, j);
		k = j;
	}
	
}

template <class T> bool BinaryMinHeap<T>::greater(int i, int j) {
	if (aux[i] > aux[j]) return 1;
	else return 0;
}

template <class T> void BinaryMinHeap<T>::exch(int i, int j) {
	T temp = aux[i];
	aux[i] = aux[j];
	aux[j] = temp;
}
