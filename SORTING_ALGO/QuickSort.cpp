#include <iostream>

using namespace std;

template <class T> class QuickSort {
	
private: QuickSort();

public : 
		 static void sort(T * arr, int n);
		 static void sort(T * arr, int lo, int hi);
		 static T *  indexSort(T * arr, int n);


private: 
		 static void exch(T * arr, int i, int j);
		 static void quickSort(T * arr, int lo, int hi);
		 static int partition(T * arr, int lo, int hi);

};

template <class T> QuickSort<T>::QuickSort() {
	
}

template <class T> void QuickSort<T>::sort(T * arr, int n) {
	sort(arr, 0, n-1);
} 

template <class T> void QuickSort<T>::sort(T * arr, int lo, int hi) {
	quickSort(arr, lo, hi);    
}

template <class T> T * QuickSort<T>::indexSort(T * arr, int n) {
	
	T * brr = new T[n];
	for (int i = 0; i < n; i++) brr[i] = arr[i];
	sort(brr, 0, n-1);
	return brr;

}

template <class T> void QuickSort<T>::exch(T * arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T> void QuickSort<T>::quickSort(T * arr, int lo, int hi) {

        if (lo >= hi) return;

        int keyIndex = partition(arr, lo, hi);

        quickSort(arr, lo, keyIndex-1);
        quickSort(arr, keyIndex+1, hi);

}

template <class T> int QuickSort<T>::partition(T * arr, int lo, int hi) {

        int key = arr[hi];

        int i = lo-1;

        for (int j = lo; j < hi; j++) {
                if (arr[j] <= key) {
                        i++;
                        exch(arr, i, j);
                }
        }

        i++;
        exch(arr, i, hi);

        return i;

}

