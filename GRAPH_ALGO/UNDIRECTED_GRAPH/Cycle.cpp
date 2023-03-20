
class Cycle {

private: bool * marked;
		 int * edgeTo;
		 Stack<int> * st;

public : Cycle(Graph &G);
		 bool hasCycle();
		 void cycle(vector<int> &v);

private: bool hasSelfLoops(Graph &G);
		 bool hasParallelEdges(Graph &G);
		 void dfs(Graph &G, int prev, int curr);

};

Cycle::Cycle(Graph &G) {

	st     = new Stack<int>();

	if (hasSelfLoops(G)) return;

	if (hasParallelEdges(G)) return;

	marked = new bool[G.V()];
	edgeTo = new int[G.V()];

	for (int i = 0; i < G.V(); i++) marked[i] = 0;
	for (int i = 0; i < G.V(); i++) edgeTo[i] = -1;

	for (int i = 0; i < G.V(); i++) if (!marked[i]) dfs(G, -1, i);

}

bool Cycle::hasCycle() {
	return !(*st).isEmpty();
}

void Cycle::cycle(vector<int> &v) {
	(*st).items(v);
}

bool Cycle::hasSelfLoops(Graph &G) {
	
	for (int i = 0; i < G.V(); i++) {
		vector<int> v;
		G.adjVertices(i, v);
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == i) {
				(*st).push(i);
				(*st).push(i);
				return 1;
			}
		}
	}

	return 0;

}

bool Cycle::hasParallelEdges(Graph &G) {

	marked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++) marked[i] = 0;

	for (int v = 0; v < G.V(); v++) {

		vector<int> w;
		G.adjVertices(v, w);

		for (int i = 0; i < w.size(); i++) {
			
			if (marked[w[i]]) {
				(*st).push(v);
				(*st).push(w[i]);
				(*st).push(v);
				return 1;
			} else {
				marked[w[i]] = 1;
			}

		}

		for (int i = 0; i < w.size(); i++) marked[w[i]] = 0;

	}

	return 0;

}

void Cycle::dfs(Graph &G, int prev, int curr) {

	marked[curr] = 1;

	vector<int> v;
	G.adjVertices(curr, v);

	for (int i = 0; i < v.size(); i++) {

		if (!(*st).isEmpty()) return;

		if (!marked[v[i]]) {
			edgeTo[v[i]] = curr;
			dfs(G, curr, v[i]);
		} else if (prev != v[i]) {
			for (int x = curr; x != v[i]; x = edgeTo[x]) (*st).push(x);    
            (*st).push(v[i]);
            (*st).push(curr);
		}

	}

}

