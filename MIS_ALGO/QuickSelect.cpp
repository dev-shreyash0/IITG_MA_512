#include <iostream>

using namespace std;

template <class T> class QuickSelect {

private: QuickSelect();

public : 
		 static T select(T * arr, int n, int k);

private:
		 static int partition(T * arr, int lo, int hi);
		 static void exch(T * arr, int i, int j);
	
};

template <class T> QuickSelect<T>::QuickSelect() {
	
}

template <class T> T QuickSelect<T>::select(T * arr, int n, int k) {
	
	int lo = 0, hi = n-1;

	while (lo < hi) {

		int j = partition(arr, lo, hi);

		if (k < j) hi = j-1;
		else if (k > j) lo = j+1;
		else return arr[k];

	} 

	return arr[k];

}

template <class T> int QuickSelect<T>::partition(T * arr, int lo, int hi) {
	
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

template <class T> void QuickSelect<T>::exch(T * arr, int i, int j) {
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}