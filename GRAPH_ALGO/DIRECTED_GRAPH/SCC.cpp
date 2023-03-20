
// kosaraju sharir

class SCC {

private: int * id;
	     int * marked;
	     int * ccSize;
	     int cc;       //number of connected components
	     int n;        //number of vertices in a graph

public : SCC(DiGraph &G);
		 bool stronglyConnected(int v, int w);
		 int  count();
		 int  identity(int v);
		 int  size(int v);

private: void dfs(DiGraph &G, int s);
		 void validateVertex(int v);

};

SCC::SCC(DiGraph &G) {

	cc = 0;
	n  = G.V();

	id = new int[n];
	marked = new int[n];
	ccSize = new int[n];

	for (int i = 0; i < n; i++) marked[i] = 0;
	for (int i = 0; i < n; i++) ccSize[i] = 0;

	DiGraph g = G.reverse();

	DepthFirstOrder dfo(g);

	vector<int> v;
	dfo.reversePost(v);

	for (int i = 0; i < n; i++) {
		if (!marked[v[i]]) {
			cc++;
			dfs(G, v[i]);
		}
	}

}

bool SCC::stronglyConnected(int v, int w) {

	validateVertex(v);
	validateVertex(w);

	return id[v] == id[w];

}

int SCC::count() {
	return cc;
}

int SCC::identity(int v) {
	validateVertex(v);
	return id[v];
}

int SCC::size(int v) {
	validateVertex(v);
	return ccSize[id[v]];
}

void SCC::validateVertex(int v) {
	if (v < 0 || v >= n) throw invalid_argument("vertex not valid");
}

void SCC::dfs(DiGraph &G, int s) {

	marked[s] = 1;
	id[s]     = cc;
	ccSize[cc]++;

	vector<int> v;

	G.adjVertices(s, v);

	for (int i = 0; i < v.size(); i++) if (!marked[v[i]]) dfs(G, v[i]);
		
	
}