#include "CountingSort.cpp"

#include <string>
#include <math.h>

using namespace std;

template <class Object> class RadixSort {
	
public : RadixSort(Object * arr, int N, int bS);
	 RadixSort(Object * arr, int N);

private: void SortF(Object * arr, int N, int bS);

};

template <class Object> RadixSort<Object>::RadixSort(Object * arr, int N, int bS) {
	SortF(arr, N, bS);
}

template <class Object> RadixSort<Object>::RadixSort(Object * arr, int N) {
	int keySize = (arr[0].Key()).length();
	SortF(arr, N, keySize);
}

template <class Object> void RadixSort<Object>::SortF(Object * arr, int N, int bS) {
	
	int k = (arr[0].Key()).length();
	int keyLo = k-bS;
	int keyHi = k-1;

	int lo = 0;
	int hi = (int)pow(10, bS) - 1;

	while (keyLo >= 0) {
		CountingSort<Object> c(arr,N,lo,hi,keyLo,keyHi);
		keyLo -= bS;
		keyHi -= bS;
	}

	if (keyLo != -bS) {
		keyLo = 0;
		hi = (int)pow(10, keyHi-keyLo+1) - 1;
		CountingSort<Object> c(arr,N,lo,hi,keyLo,keyHi);
	}

}


