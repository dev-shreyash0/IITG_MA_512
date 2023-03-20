#include <string>

using namespace std;

template <class Object> class CountingSort {
	
private: Object * brr;

public:  CountingSort(Object * arr, int N, int lo, int hi);
	 CountingSort(Object * arr, int N, int lo, int hi, int keyLo, int keyHi);

private: void SortFunction(Object * arr, int N, int lo, int hi, int keyLo, int keyHi);

};

template <class Object> CountingSort<Object>::CountingSort(Object * arr, int N, int lo, int hi) {
	
	int keySize = (arr[0].Key()).length();
	SortFunction(arr, N, lo, hi, 0, keySize-1);

}

template <class Object> CountingSort<Object>::CountingSort(Object * arr, int N, int lo, int hi, int keyLo, int keyHi) {
	
	SortFunction(arr, N, lo, hi, keyLo, keyHi);

}

template <class Object> void CountingSort<Object>::SortFunction(Object * arr, int N, int lo, int hi, int keyLo, int keyHi) {
	
	Object * brr = new Object[N];

	int * freq = new int[hi-lo+1];
	int * K    = new int[N];
	
	for (int i = 0; i < hi-lo+1; i++) freq[i] = 0;

	for (int i = 0; i < N; i++) {
		
		string key1 = arr[i].Key();
		string key2 = key1.substr(keyLo, keyHi-keyLo+1);

		K[i] = stoi(key2);
		freq[K[i]-lo]++;

	}

	for (int i = 1; i < hi-lo+1; i++) freq[i] += freq[i-1];

	for (int i = N-1; i >= 0; i--) brr[--freq[K[i]-lo]] = arr[i];

	for (int i = 0; i < N; i++) arr[i] = brr[i];	

}

 
