#include <iostream>

using namespace std;

template <class T> class RedBlackBST {

private : static bool RED   = 1;
		  static bool BLACK = 0;

private : class Node;

private : Node * root;

public  : RedBlackBST();
		  bool isEmpty();		            // is BST empty?
	  	  int  size();				    // return number of Nodes in BST
	  	  int  height(); 			    // return the height of BST
	  	  bool contains(T key);	  		    // is key present in my BST
	  	  void put(T key);			    // inserts key in BST
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
		  int  size(Node * x);
		  int  height(Node * x);
		  bool contains(Node * x, T key);
		  int  compare(T k1, T k2);
};


template <class T> class RedBlackBST<T>::Node {

public :
		 T      key;		// the key    
		 int    size;	    // the number of Nodes in a subtree 
		 Node * left;		// pointer to left subtree
		 Node * right;   	// pointer to right subtree
		 bool   color;

public  :Node(T k, bool c, int s) {
	    	key   = k;
			size  = s;
			color = c;
			left  = NULL;
			right = NULL;	
	    }	

};

template <class T> RedBlackBST<T>::RedBlackBST() {
	root = NULL;
}

template <class T> bool RedBlackBST<T>::isEmpty() {
	return root == NULL;
}

template <class T> int RedBlackBST<T>::size() {
	return size(root);
}

template <class T> int RedBlackBST<T>::size(Node * x) {
	if (x == NULL) return 0;
	else 		   return x->size;
}

template <class T> int RedBlackBST<T>::height() {
	return height(root);
}

template <class T> int RedBlackBST<T>::height(Node * x) {
	if (x == NULL) return -1;
	else 		   return 1 + max(height(x->left), height(x->right));
}

template <class T> bool RedBlackBST<T>::contains(T key) {
	return contains(Node * x, T key);
}

template <class T> bool RedBlackBST<T>::contains(Node * x, T key) {
	
	if (x == NULL) 	  return 0;

	int cmp = compare(key, x->key);
	
	if      (cmp < 0) return contains(x->left, key);
	else if (cmp > 0) return contains(x->right, key);
	else	          return 1;

	
}

template <class T> int RedBlackBST<T>::compare(T k1, T k2) {
	if      (k1 < k2) return -1;
	else if (k1 > k2) return  1;
	else 			  return  0;
}




