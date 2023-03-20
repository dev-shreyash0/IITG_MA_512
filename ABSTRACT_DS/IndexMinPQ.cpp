

template <class T> class IndexMinPQ {

private : int maxN;                          // Maximum number of keys that this priority queue can have.
		  int n;                             // Number of keys on the priority queue.
		  int * pq;                          // Binary heap array if indices.
		  int * qp;                          // ith entry of qp contains the index of i in pq.
		  T   * Keys;						 // ith entry of Keys contains the key associated with indix i.
	
public  : IndexMinPQ(int N);                 // Constructs IndexMinPQ with max size n.
		  bool isEmpty();                    // Returns true if this priority queue is empty.
		  bool contains(int i);              // Returns true if the index 'i' is on this priority queue.
		  int  size();                       // Returns the number of keys on this priority queue.
		  void insert(int i, T key);         // Associates given key with index i.
		  int  minIndex();                   // Returns the index associated to minimum key.
		  T    minKey(); 					 // Returns a minimum key.
		  int  delMin();					 // Removes a minimum key and returns its associated index.
		  T    keyOf(int i);                 // Returns the key associated with index i.
		  void changeKey(int i, T key);      // Change the key associated with index i to the specified value.
		  void decreaseKey(int i, T key);    // Decrease the key associated with index i to the specified value.
		  void increaseKey(int i, T key);    // Increase the key associated with index i to the specified value.
		  void deleteKey(int i);             // Remove the key associated with index i.

		  vector<int> & iterator();          // Returns an iterator that iterates over priority queue in ascending order.

private : void validateIndex(int i);
		  bool greater(int i, int j);
		  void exch(int i, int j);
		  void swim(int k);
		  void sink(int k);

};

template <class T> IndexMinPQ<T>::IndexMinPQ(int N) {
	
	if (N < 0)     throw invalid_argument("Cannot initialize IndexMinPQ with negative size");

	maxN = N;
	n = 0;
	pq = new int[maxN+1];
	qp = new int[maxN+1];
	Keys = new T[maxN+1];

	for (int i = 0; i <= maxN; i++) qp[i] = -1;     // implies no key present on PQ.

}

template <class T> bool IndexMinPQ<T>::isEmpty() {
	return n == 0;
}

template <class T> bool IndexMinPQ<T>::contains(int i) {
	
	validateIndex(i);
	return qp[i] != -1;

}

template <class T> int IndexMinPQ<T>::size() {
	return n;
}

template <class T> void IndexMinPQ<T>::insert(int i, T key) {
	
	validateIndex(i);
	if (contains(i)) throw invalid_argument("index is already in priority queue");

	n++;

	qp[i]   = n;
	pq[n] 	= i;
	Keys[i] = key;

	swim(n);   

}

template <class T> int IndexMinPQ<T>::minIndex() {
	if (n == 0)      throw underflow_error("priority queue underflow");
	else return pq[1];
}

template <class T> T IndexMinPQ<T>::minKey() {
	if (n == 0)      throw underflow_error("priority queue underflow");
	else return Keys[pq[1]];
}

template <class T> int IndexMinPQ<T>::delMin() {
	if (n == 0)      throw underflow_error("priority queue underflow");
	int min = pq[1];
	exch(1, n--);
	sink(1);
	qp[min] = -1;
	return min;
}

template <class T> T IndexMinPQ<T>::keyOf(int i) {
	validateIndex(i);
	if (!contains(i))  throw invalid_argument("index is not on the prority queue");
	else return Keys[i];	
}

template <class T> void IndexMinPQ<T>::changeKey(int i, T key) {
	validateIndex(i);
	if (!contains(i))  throw invalid_argument("index is not on the prority queue");

	Keys[i] = key;
	swim(qp[i]);
	sink(qp[i]);

}

template <class T> void IndexMinPQ<T>::decreaseKey(int i, T key) {
	validateIndex(i);
	if (!contains(i))   throw invalid_argument("index is not on the prority queue");
	if (Keys[i] == key) throw invalid_argument("Calling decreaseKey() with a key equal to the key in the priority queue");
	if (Keys[i] <  key) throw invalid_argument("Calling decreaseKey() with a key strictly greater than the key in the priority queue");

	Keys[i] = key;
	swim(qp[i]);
}

template <class T> void IndexMinPQ<T>::increaseKey(int i, T key) {
	validateIndex(i);
	if (!contains(i))   throw invalid_argument("index is not on the prority queue");
	if (Keys[i] == key) throw invalid_argument("Calling increaseKey() with a key equal to the key in the priority queue");
	if (Keys[i] >  key) throw invalid_argument("Calling increaseKey() with a key strictly less than the key in the priority queue");

	Keys[i] = key;
	sink(qp[i]);
}

template <class T> void IndexMinPQ<T>::deleteKey(int i) {
	validateIndex(i);
	if (!contains(i))   throw invalid_argument("index is not on the prority queue");

	int index = qp[i];
    exch(index, n--);
    swim(index);
    sink(index);
    qp[i] = -1;

}

template <class T> vector<int> & IndexMinPQ<T>::iterator() {
	
	vector<int> * v = new vector<int>();

	IndexMinPQ copy(maxN);

	for (int i = 1; i <= n; i++) copy.insert(pq[i], Keys[pq[i]]);

	while (!copy.isEmpty()) (*v).push_back(copy.delMin());

	return (*v);

}

template <class T> void IndexMinPQ<T>::validateIndex(int i) {
	if (i < 0 || i >= maxN) throw invalid_argument("index not valid");
}

template <class T> bool IndexMinPQ<T>::greater(int i, int j) {
	return Keys[pq[i]] > Keys[pq[j]];
}

template <class T> void IndexMinPQ<T>::exch(int i, int j) {
	int temp = pq[i];
	pq[i] = pq[j];
	pq[j] = temp;
	qp[pq[i]] = i;
	qp[pq[j]] = j;
}

template <class T> void IndexMinPQ<T>::swim(int k) {
	
	while (k > 1 && greater(k/2, k)) {
		exch(k, k/2);
		k = k/2;
	}

}

template <class T> void IndexMinPQ<T>::sink(int k) {
	
	while (2*k <= n) {
		int j = 2*k;
		if (j < n && greater(j, j+1)) j++;
		if (!greater(k, j)) break;
		exch(k, j);
		k = j;
	}

}

