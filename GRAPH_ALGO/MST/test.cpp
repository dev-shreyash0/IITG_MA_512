#include "MSTLib.hpp"

//#include "../../SORTING_ALGO/InsertionSort.cpp"
//#include "../../ABSTRACT_DS/IndexMinPQ.cpp"

int main(int argc, char ** argv) {

/*
	Edge e1, e2;
	e1.set(1, 2, 1);
	e2.set(2, 3, 2);

	cout << e1 << endl;
	//cout << e2 << endl;

	Queue<Edge> q;

	q.enqueue(e1);
	q.enqueue(e2);

*/

/*
	Edge * E = new Edge[100];

	for (int i = 0; i < 100; i++) E[i].set(1,1,100-i);

	for (int i = 0; i < 100; i++) cout << E[i] << endl;
	cout << endl;

	InsertionSort<Edge>::sort(E, 100);

	for (int i = 0; i < 100; i++) cout << E[i] << endl;
	cout << endl;	

	

*/

/*
	IndexMinPQ<Edge> pq(15);

	for (int i = 0; i < 15; i++) {
		Edge e;
		e.set(i,i,15-i);
		pq.insert(i, e);
	}

	for (auto & itr : pq.iterator()) cout << itr << " ";
	cout << endl;

*/

	EdgeWeightedGraph G(argv[1]);

//	cout << G << endl;

	KruskalMST mst2(G);

	cout << mst2.weight() << endl;
	for (Edge & E : mst2.edges()) cout << E << endl;

	cout << endl;
	cout << endl;

/*	EagerPrimMST mst1(G);

	cout << mst1.weight() << endl;
	for (Edge & E : mst1.edges()) cout << E << endl;
 
 	cout << endl;
 	cout << endl;

	LazyPrimMST mst(G);

	cout << mst.weight() << endl;
	for (Edge & E : mst.edges()) cout << E << endl;
*/
	return 0;

}