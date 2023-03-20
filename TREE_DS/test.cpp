#include "AVLTree.cpp"

int main() {

	AVLTree<int> tree;

	for (int i = 1; i <= 1023; i++) tree.put(i);

	//cout << tree.height() << endl;

	cout << tree.select(99) << endl;

	return 0;

}