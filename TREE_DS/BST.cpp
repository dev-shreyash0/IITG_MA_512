#include "../LINEAR_DS/Queue.cpp"
#include <iostream>
#include <vector>

using namespace std;

template <class T> class BST {

private  : class Node;

private	:
	  Node *  root;

public  :
	  BST(); 				    // initialises empty BST
 	  bool isEmpty();		            // is BST empty?
	  int  size();				    // return number of Nodes in BST
	  int  height(); 			    // return the height of BST
	  void put(T key);			    // inserts key in BST
	  bool contains(T key);	  		    // is key present in my BST
	  T    minInBST(); 			    // returns minimum key in my BST
	  T    maxInBST();		            // returns maximum key in my BST
	  void deleteMin();         		    // deletes minimum key in my BST
	  void deleteMax();		            // deletes maximum key in my BST
	  void deleteKey(T key); 		    // deletes given key from my BST
	  T    floor(T key);		   	    // returns greatest key less than or equal to given key
	  T    ceiling(T key);			    // returns least key greater than or eqaul to given key
	  void inOrder(vector<T> & v);     	    // keys in BST in ascending order
	  void inOrder(vector<T> & v, T lo, T hi);  // keys in BST in acsending order between lo and hi
	  void preOrder(vector<T> & v);		    // keys according to preOrder traversal
	  void postOrder(vector<T> & v);	    // keys according to postOrder traversal
	  void levelOrder(vector<T> & v);           // keys according to levelOrder traversal
	  int  rank(T key);			    // returns number of keys strictly less than given key	
	  T    select(int rank);                    // returns the key of given rank
	  int  size(T lo, T hi);		    // returns number of keys in BST between lo and hi                   


private :
	  int    sizeOfNode(Node * x);
	  int    hOfNode(Node * x);
	  Node * insert(Node * x, T key);
	  int    compare(T k1, T k2);
	  bool   search(Node * x, T key);
	  Node * minNode(Node * x);
	  Node * maxNode(Node * x);
	  Node * helpDelMin(Node * x);
	  Node * helpDelMax(Node * x);
	  Node * helpDelKey(Node * x, T key);
	  Node * helpFloor(Node * x, T key);
	  Node * helpCeil(Node * x, T key);
	  void   helpInOrder(Node * x, vector<T> & v, T lo, T hi);
	  void   helpPreOrder(Node * x, vector<T> &v);
	  void   helpPostOrder(Node * x, vector<T> &v);
	  int    helpRank(Node * x, T key);
	  T 	 helpSelect(Node * x, int rank);

};

template <class T> class BST<T>::Node {

public :
	T key;				// the key    
	int height;     	// the height of subtree 
	int size;			// the number of Nodes in a subtree 
	Node * left;		// pointer to left subtree
	Node * right;   	// pointer to right subtree

public  :   Node(T k, int h, int s) {
                key = k;
                height = h;
                size = s;
                left = NULL;
                right = NULL;
            }

};


template <class T> BST<T>::BST() {
	root = NULL;
}

template <class T> bool BST<T>::isEmpty() {
	return root == NULL;
}

template <class T> int BST<T>::size() {
	return sizeOfNode(root);
}

template <class T> int BST<T>::sizeOfNode(Node * x) {
	if (x == NULL) return 0;
	else return x->size;
}

template <class T> int BST<T>::height() {
	return hOfNode(root);
}

template <class T> int BST<T>::hOfNode(Node * x) {
	if (x == NULL) return -1;
	else return x->height;
}

template <class T> void BST<T>::put(T key) {
	root = insert(root, key);
}

template <class T> typename BST<T>::Node * BST<T>::insert(Node * x, T key) {
	
	if (x == NULL) return new Node(key, 0, 1);

	int cmp = compare(key, x->key);

	if (cmp < 0) {
		x->left = insert(x->left, key);
	} else if (cmp > 0) {
		x->right = insert(x->right, key);
	} else {
		x->key = key;
	}

	x->height = 1 + max(hOfNode(x->left), hOfNode(x->right));
	x->size   = 1 + sizeOfNode(x->left) + sizeOfNode(x->right);

	return x;

}

template <class T> int BST<T>::compare(T k1, T k2) {
	if (k1 < k2) return -1;
	else if (k1 > k2) return 1;
	else return 0;
}

template <class T> bool BST<T>::contains(T key) {
	return search(root, key);
}

template <class T> bool BST<T>::search(Node * x, T key) {
	
	if (x == NULL) return 0;

	int cmp = compare(key, x->key);
	
	if (cmp < 0) {
		return search(x->left, key);
	} else if (cmp > 0) {
		return search(x->right, key);
	} else {
		return 1;
	}

}

template <class T> T BST<T>::minInBST() {
	if (isEmpty()) throw underflow_error("calls minInBST() with empty BST");
	return minNode(root)->key;
}

template <class T> T BST<T>::maxInBST() {
	if (isEmpty()) throw underflow_error("calls maxInBST() with empty BST");
	return maxNode(root)->key;
}

template <class T> typename BST<T>::Node * BST<T>::minNode(Node * x) {
	if (x->left == NULL) return x;
	else return minNode(x->left);
}

template <class T> typename BST<T>::Node * BST<T>::maxNode(Node * x) {
	if (x->right == NULL) return x;
	else return maxNode(x->right);
}

template <class T> void BST<T>::deleteMin() {
	if (isEmpty()) throw underflow_error("BST underflow");
	root = helpDelMin(root);
}

template <class T> void BST<T>::deleteMax() {
	if (isEmpty()) throw underflow_error("BST underflow");
	root = helpDelMax(root);
}

template <class T> void BST<T>::deleteKey(T key) {
	if (isEmpty()) throw underflow_error("BST underflow");
	root = helpDelKey(root, key);
}

template <class T> typename BST<T>::Node * BST<T>::helpDelMin(Node * x) {
	
	if (x->left == NULL) return x->right;

	x->left = helpDelMin(x->left);

	x->size = 1 + sizeOfNode(x->left) + sizeOfNode(x->right);
	x->height = 1 + max(hOfNode(x->left), hOfNode(x->right));

	return x;
	
}

template <class T> typename BST<T>::Node * BST<T>::helpDelMax(Node * x) {
	
	if (x->right == NULL) return x->left;

	x->right = helpDelMax(x->right);

	x->size = 1 + sizeOfNode(x->left) + sizeOfNode(x->right);
	x->height = 1 + max(hOfNode(x->left), hOfNode(x->right));

	return x;

}

template <class T> typename BST<T>::Node * BST<T>::helpDelKey(Node * x, T key) {
	
	if (x == NULL) return NULL;

	int cmp = compare(key, x->key);

	if (cmp < 0) {
		x->left = helpDelKey(x->left, key);
	} else if (cmp > 0) {
		x->right = helpDelKey(x->right, key);
	} else {

		if (x->left == NULL) return x->right;
		if (x->right == NULL) return x->left;
		
		x->key = minNode(x->right)->key;
		x->right = helpDelMin(x->right);

	}

	x->size   = 1 + sizeOfNode(x->left) + sizeOfNode(x->right);
	x->height = 1 + max(hOfNode(x->left), hOfNode(x->right));

	return x;

}

template <class T> T BST<T>::floor(T key) {
	if (isEmpty()) throw underflow_error("calls floor() with empty BST");
	Node * x = helpFloor(root, key);
	if (x == NULL) throw invalid_argument("argument to floor() is too small");
	else return x->key;
}

template <class T> T BST<T>::ceiling(T key) {
	if (isEmpty()) throw underflow_error("calls ceiling() with empty BST");
	Node * x = helpCeil(root, key)->key;
	if (x == NULL) throw invalid_argument("argument to ceiling() is too large");
	else return x->key;
}

template <class T> typename BST<T>::Node * BST<T>::helpFloor(Node * x, T key) {
	
	if (x == NULL) return NULL;

	int cmp = compare(key, x->key);

	if (cmp == 0) return x;
	if (cmp < 0) return helpFloor(x->left, key);

	Node * y = helpFloor(x->right, key);

	if (y != NULL) return y;
	else return x;

}

template <class T> typename BST<T>::Node * BST<T>::helpCeil(Node * x, T key) {
	
	if (x == NULL) return NULL;

	int cmp = compare(key, x->key);

	if (cmp == 0) return x;
	if (cmp > 0) return helpCeil(x->right, key);

	Node * y = helpCeil(x->left, key);

	if (y != NULL) return y;
	else return x;

}

template <class T> void BST<T>::inOrder(vector<T> & v) {
	helpInOrder(root, v, minInBST(), maxInBST());
}

template <class T> void BST<T>::inOrder(vector<T> & v, T lo, T hi) {
	helpInOrder(root, v, lo, hi);
}

template <class T> void BST<T>::helpInOrder(Node * x, vector<T> & v, T lo, T hi) {
	
	if (x == NULL) return;

	int cmplo = compare(lo, x->key);
	int cmphi = compare(hi, x->key);

	if (cmplo < 0) helpInOrder(x->left, v, lo, hi);
	if (cmplo <= 0 && cmphi >= 0) v.push_back(x->key);
	if (cmphi > 0) helpInOrder(x->right, v, lo, hi);

}

template <class T> void BST<T>::preOrder(vector<T> & v) {
	helpPreOrder(root, v);
}

template <class T> void BST<T>::postOrder(vector<T> & v) {
	helpPostOrder(root, v);
}

template <class T> void BST<T>::helpPreOrder(Node * x, vector<T> & v) {
	
	if (x == NULL) return;

	v.push_back(x->key);
	helpPreOrder(x->left, v);
	helpPreOrder(x->right, v);

}

template <class T> void BST<T>::helpPostOrder(Node * x, vector<T> & v) {

	if (x == NULL) return;

	helpPostOrder(x->left, v);
	helpPostOrder(x->right, v);
	v.push_back(x->key);

}

template <class T> void BST<T>::levelOrder(vector<T> & v) {
	
	Queue<Node *> que;
	que.enqueue(root);

	while (!que.isEmpty()) {
		Node * y = que.dequeue();
		if (y == NULL) continue;
		v.push_back(y->key);
		que.enqueue(y->left);
		que.enqueue(y->right);
	}

}

template <class T> int BST<T>::rank(T key) {
	return helpRank(root, key);
}

template <class T> int BST<T>::helpRank(Node * x, T key) {
	
	if (x == NULL) return 0;

	int cmp = compare(key, x->key);

	if (cmp < 0) return helpRank(x->left, key);
	else if (cmp == 0) return sizeOfNode(x->left);
	else return 1 + sizeOfNode(x->left) + helpRank(x->right, key);

}

template <class T> T BST<T>::select(int rank) {
	if (rank < 0 || rank >= size()) throw invalid_argument("argument to select() is invalid");
	return helpSelect(root, rank);
}

template <class T> T BST<T>::helpSelect(Node * x, int rank) {
	
	int leftSize = sizeOfNode(x->left);

	if (leftSize == rank) return x->key;
	else if (leftSize < rank) return helpSelect(x->right, rank-leftSize-1);
	else return helpSelect(x->left, rank);

}

template <class T> int BST<T>::size(T lo, T hi) {
	
	if (lo > hi) return 0;
	
	if (contains(hi)) return rank(hi) - rank(lo) + 1;
	else return rank(hi) - rank(lo);

}

