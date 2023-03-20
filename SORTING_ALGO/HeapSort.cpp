#include <iostream>
#include "../TREE_DS/BinaryMaxHeap.cpp"
using namespace std;

template <class T> class HeapSort {
	
private: HeapSort();

public : 
		 static void sort(T * arr, int n);
		 static void sort(T * arr, int lo, int hi);
		 static T *  indexSort(T * arr, int n);


private: 
		 static void exch(T * arr, int i, int j);
		 static bool less(T * arr, int i, int j);
		 static void sink(T * arr, int k, int size);

};

template <class T> HeapSort<T>::HeapSort() {
	
}

template <class T> void HeapSort<T>::sort(T * arr, int n) {
	sort(arr, 0, n-1);
} 

template <class T> void HeapSort<T>::sort(T * arr, int lo, int hi) {
	
	BinaryMaxHeap<T>(arr, lo, hi);

	int k = hi;

	while (k > lo) {
		exch(arr, lo, k--);
		sink(arr, lo, k);
	}
        
}

template <class T> T * HeapSort<T>::indexSort(T * arr, int n) {
	
	T * brr = new T[n];
	for (int i = 0; i < n; i++) brr[i] = arr[i];
	sort(brr, 0, n-1);
	return brr;

}

template <class T> void HeapSort<T>::exch(T * arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T> bool HeapSort<T>::less(T * arr, int i, int j) {
	if (arr[i] < arr[j]) return 1;
	else return 0;
}

template <class T> void HeapSort<T>::sink(T * arr, int k, int size) {
	
	while (2*k <= size) {
		int j = 2*k;
		if (j < size && less(arr, j, j+1)) j++;
		if (!less(arr, k, j)) break;
		exch(arr, k, j);
		k = j;
	}

}
