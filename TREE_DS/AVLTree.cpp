#include <iostream>
#include <vector>
#include "../LINEAR_DS/Queue.cpp"
using namespace std;

template <class T> class AVLTree {

private: 	class Node;

private:	 
			Node * root;				    			// the root node

public :		   AVLTree();				    		// initialises empty AVLTree
			bool   isEmpty(); 			    			// checks if tree is empty
			int    size(); 				    			// returns number of nodes in a tree
			int    height();			    			// returns height of internal tree, assumption empty tree height = -1, single node tree height = 0			
			bool   contains(T key);			    		// checks is tree contains given key
			void   put(T key);			    			// inserts the key in tree
			void   deleteKey(T key);		    		// removes the given key from tree
			void   deleteMin();			    			// removes the minimum key from tree
			void   deleteMax();			    			// removes the maximum key from tree
			T      minInTree();			    			// returns the minimum key in tree
			T      maxInTree();			    			// returns the maximum key in tree
			T      floor(T key);		   	   	   	    // returns greatest key less than or equal to given key
	  		T      ceiling(T key);			    		// returns least key greater than or eqaul to given key
	  		void   inOrder(vector<T> & v);              // inserts keys in AVLTree in ascending order in a given vector
	   	   	void   inOrder(vector<T> & v, T lo, T hi);  // inserts keys in AVLTree in acsending order between lo and hi in a given vector
	  		void   preOrder(vector<T> & v);		    	// inserts keys according to preOrder traversal in a given vector
	  		void   postOrder(vector<T> & v);	    	// inserts keys according to postOrder traversal in a given vector
	  		void   levelOrder(vector<T> & v);           // inserts keys according to levelOrder traversal in a given vector
	  		int    rank(T key);			    			// returns number of keys strictly less than given key	
	  		T      select(int rank);                    // returns the key of given rank
	  		int    size(T lo, T hi);		    		// returns number of keys in AVLTree between lo and hi  

private:	
			int       size(Node * x);					// returns number of nodes in a subtree rooted at node x
			int       height(Node * x);					// returns height of subtree rooted at x
			bool      contains(Node * x, T key);		// checks if subtree rooted at node x contains given key
			int    	  compare(T k1, T k2);				// returns -1 if k1 less than k2 , 0 if equal, 1 otherwise
			Node * 	  balance(Node * x);				// restores AVLTree property of a subtree rooted at node x
			int    	  balanceFactor(Node * x);			// returns balance factor of a subtree rooted at node x
			Node * 	  rotateLeft(Node * x);				// rotates the given subtree to left
			Node * 	  rotateRight(Node * x);			// rotates the given subtree to right
			Node * 	  put(Node * x, T key);          	// inserts the key in a tree and return new root(if changed)
			Node *    deleteKey(Node * x, T key);		// removes the given key from a subtree
			Node *    deleteMin(Node * x);  			// removes the minimum key from a subtree
			Node *    deleteMax(Node * x);  			// removes the maximum key from a subtree
			Node *    minInTree(Node * x);				// returns the node containing minimum key in a subtree
			Node *    maxInTree(Node * x);				// returns the node containing maximum key in a subtree
		    Node *    helpFloor(Node * x, T key);
	  		Node *    helpCeil(Node * x, T key);
	  		void 	  helpInOrder(Node * x, vector<T> & v, T lo, T hi);
	  		void 	  helpPreOrder(Node * x, vector<T> &v);
	  		void 	  helpPostOrder(Node * x, vector<T> &v);
	  		int 	  helpRank(Node * x, T key);
	  		T         helpSelect(Node * x, int rank);
	  		
};

template <class T> class AVLTree<T>::Node {

public 	:
			T 	   key;			// the key    
			int    height;     	// the height of subtree 
			int    size;		// the number of Nodes in a subtree 
			Node * left;		// pointer to left subtree
			Node * right;   	// pointer to right subtree

public  : Node(T k, int h, int s) {
	    		key    = k;
				height = h;
				size   = s;
				left   = NULL;
				right  = NULL;	
	      }

};

template <class T> AVLTree<T>::AVLTree() {
	root = NULL;
}

template <class T> bool AVLTree<T>::isEmpty() {
	return root == NULL;
}

template <class T> int AVLTree<T>::size() {
	return size(root);
}

template <class T> int AVLTree<T>::size(Node * x) {
	if (x == NULL) return 0;
	return 		   x->size;
}

template <class T> int AVLTree<T>::height() {
	return height(root);
}

template <class T> int AVLTree<T>::height(Node * x) {
	if (x == NULL) return -1;
	return     	   x->height;
}

template <class T> bool AVLTree<T>::contains(T key) {
	return contains(root, key);
}

template <class T> bool AVLTree<T>::contains(Node * x, T key) {
	
	if    (x == NULL) return 0;
	
	int cmp = compare(key, x->key);
	
	if      (cmp < 0) return contains(x->left, key);
	else if (cmp > 0) return contains(x->right, key);
	else              return 1;

}

template <class T> int AVLTree<T>::compare(T k1, T k2) {
	if     (k1 == k2) return 0;
	else if (k1 < k2) return -1;
	else              return 1;
}

template <class T> void AVLTree<T>::put(T key) {
	root = put(root, key);
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::put(Node * x, T key) {
	
	if (x == NULL) return new Node(key, 0, 1);

	int cmp = compare(key, x->key);

	if      (cmp < 0) x->left  = put(x->left, key);
	else if (cmp > 0) x->right = put(x->right, key);
	else                x->key = key;

	x->size   = 1 + size(x->left) + size(x->right);
	x->height = 1 + max(height(x->left), height(x->right));

	return balance(x);

}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::balance(Node * x) {
	
	if (balanceFactor(x) < -1) {
		if (balanceFactor(x->right) > 0) x->right = rotateRight(x->right);
		x = rotateLeft(x);
	} else if (balanceFactor(x) > 1) {
		if (balanceFactor(x->left) < 0)   x->left = rotateLeft(x->left);
		x = rotateRight(x);
	} 

	return x;

}

template <class T> int AVLTree<T>::balanceFactor(Node * x) {
	return height(x->left) - height(x->right);
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::rotateLeft(Node * x) {
	
	Node * y  = x->right;
	x->right  = y->left;
	y->left   = x;

	y->size   = x->size;
	x->size   = 1 + size(x->left) + size(x->right);

	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));

	return y;

}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::rotateRight(Node * x) {
	
	Node * y  = x->left;
	x->left   = y->right;
	y->right  = x;

	y->size   = x->size;
	x->size   = 1 + size(x->left) + size(x->right);

	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));

	return y;

}

template <class T> void AVLTree<T>::deleteKey(T key) {
	if (isEmpty()) throw underflow_error("AVLTree underflow");
	root = deleteKey(root, key);
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::deleteKey(Node * x, T key) {
	
	int cmp = compare(key, x->key);

	if      (cmp < 0) { x->left  = deleteKey(x->left, key);} 
	else if (cmp > 0) { x->right = deleteKey(x->right, key);} 
	else {

		if (x->left == NULL)  return x->right;
		if (x->right == NULL) return x->left;
		
		x->key   = minInTree(x->right)->key;
		x->right = deleteMin(x->right);

	}

	x->size   = 1 + size(x->left) + size(x->right);
	x->height = 1 + max(height(x->left), height(x->right));

	return balance(x);

}

template <class T> void AVLTree<T>::deleteMin() {
	if (isEmpty()) throw underflow_error("AVLTree underflow");
	root = deleteMin(root);
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::deleteMin(Node * x) {
	
	if (x->left == NULL) return x->right;
	
	x->left   = deleteMin(x->left);

	x->size   = 1 + size(x->left) + size(x->right);
	x->height = 1 + max(height(x->left), height(x->right));

	return balance(x);

}

template <class T> void AVLTree<T>::deleteMax() {
	if (isEmpty()) throw underflow_error("AVLTree underflow");
	root = deleteMax(root);
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::deleteMax(Node * x) {
	
	if (x->right == NULL) return x->left;
	
	x->right  = deleteMax(x->right);

	x->size   = 1 + size(x->left) + size(x->right);
	x->height = 1 + max(height(x->left), height(x->right));

	return balance(x);

}

template <class T> T AVLTree<T>::minInTree() {
	if (isEmpty()) throw underflow_error("calls minInTree() with empty AVLTree");
	return         minInTree(root)->key;
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::minInTree(Node * x) {
	if (x->left == NULL) return x;
	return               minInTree(x->left);
}

template <class T> T AVLTree<T>::maxInTree() {
	if (isEmpty()) throw underflow_error("calls maxInTree() with empty AVLTree");
	return         maxInTree(root)->key;
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::maxInTree(Node * x) {
	if (x->right == NULL) return x;
	return maxInTree(x->right);
}

template <class T> T AVLTree<T>::floor(T key) {
	if (isEmpty()) throw underflow_error("calls floor() with empty AVLTree");
	Node * x = helpFloor(root, key)->key;
	if (x == NULL) throw invalid_argument("argument to floor() is too small");
	else           return x->key;
}

template <class T> T AVLTree<T>::ceiling(T key) {
	if (isEmpty()) throw underflow_error("calls floor() with empty AVLTree");
	Node * x = helpCeil(root, key)->key;
	if (x == NULL) throw invalid_argument("argument to ceiling() is too large");
	else           return x->key;
}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::helpFloor(Node * x, T key) {
	
	if (x == NULL) return NULL;

	int cmp = compare(key, x->key);

	if (cmp == 0) return x;
	if (cmp < 0)  return helpFloor(x->left, key);

	Node * y = helpFloor(x->right, key);

	if (y != NULL) return y;
	else           return x;

}

template <class T> typename AVLTree<T>::Node * AVLTree<T>::helpCeil(Node * x, T key) {
	
	if (x == NULL) return NULL;

	int cmp = compare(key, x->key);

	if (cmp == 0) return x;
	if (cmp > 0)  return helpCeil(x->right, key);

	Node * y = helpCeil(x->left, key);

	if (y != NULL) return y;
	else           return x;

}

template <class T> void AVLTree<T>::inOrder(vector<T> & v) {
	helpInOrder(root, v, minInTree(), maxInTree());
}

template <class T> void AVLTree<T>::inOrder(vector<T> & v, T lo, T hi) {
	helpInOrder(root, v, lo, hi);
}

template <class T> void AVLTree<T>::helpInOrder(Node * x, vector<T> & v, T lo, T hi) {
	
	if (x == NULL) return;

	int cmplo = compare(lo, x->key);
	int cmphi = compare(hi, x->key);

	if (cmplo < 0) helpInOrder(x->left, v, lo, hi);
	if (cmplo <= 0 && cmphi >= 0) v.push_back(x->key);
	if (cmphi > 0) helpInOrder(x->right, v, lo, hi);

}

template <class T> void AVLTree<T>::preOrder(vector<T> & v) {
	helpPreOrder(root, v);
}

template <class T> void AVLTree<T>::postOrder(vector<T> & v) {
	helpPostOrder(root, v);
}

template <class T> void AVLTree<T>::helpPreOrder(Node * x, vector<T> & v) {
	
	if (x == NULL) return;

	v.push_back(x->key);
	helpPreOrder(x->left, v);
	helpPreOrder(x->right, v);

}

template <class T> void AVLTree<T>::helpPostOrder(Node * x, vector<T> & v) {

	if (x == NULL) return;

	helpPostOrder(x->left, v);
	helpPostOrder(x->right, v);
	v.push_back(x->key);

}

template <class T> void AVLTree<T>::levelOrder(vector<T> & v) {
	
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

template <class T> int AVLTree<T>::rank(T key) {
	return helpRank(root, key);
}

template <class T> int AVLTree<T>::helpRank(Node * x, T key) {
	
	if (x == NULL) return 0;

	int cmp = compare(key, x->key);

	if       (cmp < 0) return helpRank(x->left, key);
	else if (cmp == 0) return size(x->left);
	else               return 1 + size(x->left) + helpRank(x->right, key);

}

template <class T> T AVLTree<T>::select(int rank) {
	
	if (rank < 0 || rank >= size()) throw invalid_argument("argument to select() is invalid");
	return                          helpSelect(root, rank);
}

template <class T> T AVLTree<T>::helpSelect(Node * x, int rank) {
	
	int leftSize = size(x->left);

	if      (leftSize == rank) return x->key;
	else if (leftSize < rank)  return helpSelect(x->right, rank-leftSize-1);
	else                       return helpSelect(x->left, rank);

}

template <class T> int AVLTree<T>::size(T lo, T hi) {
	
	if (lo > hi) return 0;
	
	if (contains(hi)) return rank(hi) - rank(lo) + 1;
	else              return rank(hi) - rank(lo);

}





