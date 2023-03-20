#include <iostream>

using namespace std;

template <class T> class InsertionSort {
	
private: InsertionSort();

public : 
		 static void sort(T * arr, int n);
		 static void sort(T * arr, int lo, int hi);
		 static T *  indexSort(T * arr, int n);


private: 
		 static void exch(T * arr, int i, int j);
		 static bool less(T o1, T o2);

};

template <class T> InsertionSort<T>::InsertionSort() {
	
}

template <class T> void InsertionSort<T>::sort(T * arr, int n) {
	sort(arr, 0, n-1);
} 

template <class T> void InsertionSort<T>::sort(T * arr, int lo, int hi) {
	
	for (int i = lo + 1; i <= hi; i++) 
        for (int j = i; j > lo && less(arr[j], arr[j-1]); j--) exch(arr, j, j-1);
        
}

template <class T> T * InsertionSort<T>::indexSort(T * arr, int n) {
	
	T * brr = new T[n];
	for (int i = 0; i < n; i++) brr[i] = arr[i];
	sort(brr, 0, n-1);
	return brr;

}

template <class T> void InsertionSort<T>::exch(T * arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T> bool InsertionSort<T>::less(T o1, T o2) {
	if (o1 < o2) return 1;
	else return 0;
}