#include "../GRAPH_ALGO/UNDIRECTED_GRAPH/UnDiGraphLib.hpp"

int main(int argc, char ** argv) {


	Graph G(argv[1]);

	G.print();

/*	DepthFirstPaths dfs(G, 6);
	BreathFirstPaths bfs(G, 6);

	vector<int> v1;
	dfs.pathTo(2, v1);

	vector<int> v2;
	bfs.pathTo(2, v2);

	for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
	cout << endl;  

*/

/*	CC c(G);

	cout << c.count() << endl;

	cout << c.connected(6, 3) << endl;
	cout << c.connected(6, 11) << endl;
	cout << c.connected(10, 11) << endl;

	cout << c.size(0) << endl;
	cout << c.size(11) << endl;
	cout << c.size(7) << endl;

	for (int i = 1; i <= c.count(); i++) {
		for (int j = 0; j < G.V(); j++) if (c.identity(j) == i) cout << j << " ";
		cout << endl;
	}

*/

/*

	Bipartite b(G);

	cout << b.isBipartite() << endl;

	vector<int> v;

	b.oddCycle(v);

	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

*/

/*	Cycle c(G);

	cout << c.hasCycle() << endl;
	vector<int> v;
	c.cycle(v);
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
 
*/

	return 0;
}