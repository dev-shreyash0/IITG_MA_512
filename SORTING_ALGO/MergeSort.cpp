#include <iostream>
using namespace std;

template <class T> class MergeSort {
	
private: MergeSort();

public : 
		 static void sort(T * arr, int n);
		 static void sort(T * arr, int lo, int hi);
		 static T *  indexSort(T * arr, int n);


private: 
		 static bool less(T o1, T o2);
		 static void sort(T * arr, T * aux, int lo, int hi);
		 static void merge(T * arr, T * aux, int lo, int mid, int hi);

};

template <class T> MergeSort<T>::MergeSort() {
	
}

template <class T> void MergeSort<T>::sort(T * arr, int n) {
	sort(arr, 0, n-1);
} 

template <class T> void MergeSort<T>::sort(T * arr, int lo, int hi) {
	T * aux = new T[hi+1];
	sort(arr, aux, lo, hi);
        
}

template <class T> T * MergeSort<T>::indexSort(T * arr, int n) {
	
	T * brr = new T[n];
	for (int i = 0; i < n; i++) brr[i] = arr[i];
	sort(brr, 0, n-1);
	return brr;

}

template <class T> void MergeSort<T>::sort(T * arr, T * aux, int lo, int hi) {
	
	if (lo >= hi) return;

	int mid = lo + (hi-lo)/2;

	sort(arr, aux, lo, mid);
	sort(arr, aux, mid + 1, hi);

	merge(arr, aux, lo, mid, hi);

}

template <class T> bool MergeSort<T>::less(T o1, T o2) {
	if (o1 < o2) return 1;
	else return 0;
}

template <class T> void MergeSort<T>::merge(T * arr, T * aux, int lo, int mid, int hi) {
	
	int i = lo, j = mid + 1;

	for (int k = lo; k <= hi; k++) {
		if (i > mid)           		   aux[k] = arr[j++];
		else if (j > hi)               aux[k] = arr[i++];
		else if (less(arr[j], arr[i])) aux[k] = arr[j++];
		else 						   aux[k] = arr[i++];
	}

	for (int k = lo; k <= hi; k++) arr[k] = aux[k];

}