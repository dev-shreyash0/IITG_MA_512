#include "../GRAPH_ALGO/DIRECTED_GRAPH/DiGraphLib.hpp"

int main(int argc, char ** argv) {

	DiGraph D1(argv[1]);

//	D1.print();

/*	
	DiGraph D2 = D1.reverse();

	D2.print();

	DirectedDFS dfs1(D1, 0);
	DirectedDFS dfs2(D2, 2);

	vector<int> v1;
	vector<int> v2;

	dfs1.pathTo(2, v1);
	dfs2.pathTo(0, v2);

	for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
	cout << endl;
	for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
	cout << endl;

	DirectedBFS bfs1(D1, 0);
	DirectedBFS bfs2(D2, 2);

	vector<int> v3;
	vector<int> v4;

	bfs1.pathTo(2, v3);
	bfs2.pathTo(0, v4);

	for (int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
	cout << endl;
	for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
	cout << endl;
*/

/*
	DirectedCycle dc(D1);

	vector<int> v;
	if (dc.hasCycle()) dc.cycle(v);

	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

*/

/*	DepthFirstOrder dfo(D1);

	vector<int> v1;
	dfo.preOrder(v1);

	vector<int> v2;
	dfo.postOrder(v2);

	vector<int> v3;
	dfo.reversePost(v3);

	for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
	cout << endl;

	for (int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
	cout << endl;

*/

/*
	Topological t(D1);

	vector<int> v1;
	t.order(v1);

	for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
	cout << endl;

*/

	SCC scc(D1);

	cout << scc.count() << endl;

	return 0;


}
