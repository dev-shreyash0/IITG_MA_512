
class DirectedCycle {

private : bool * marked;
		  int  * edgeTo;
		  bool * onStack;
		  Stack<int> * st;

		  int n;

public  : DirectedCycle(DiGraph &G);
		  bool hasCycle();
		  void cycle(vector<int> &v);

private : void dfs(DiGraph &G, int v);

};

DirectedCycle::DirectedCycle(DiGraph &G) {

	n = G.V();

	marked = new bool[n];
	onStack = new bool[n];
	edgeTo = new int[n];

	st = new Stack<int>();

	for (int i = 0; i < n; i++) {
		marked[i] = 0;
		onStack[i] = 0;
		edgeTo[i] = -1;
	}

	for (int i = 0; i < n; i++) if (!marked[i] && (*st).isEmpty()) dfs(G, i);

}

bool DirectedCycle::hasCycle() {
	return !(*st).isEmpty();
}

void DirectedCycle::cycle(vector<int> &v) {
	(*st).items(v);
}

void DirectedCycle::dfs(DiGraph &G, int v) {

	marked[v] = 1;
	onStack[v] = 1;

	vector<int> w;
	G.adjVertices(v, w);

	for (int i = 0; i < w.size(); i++) {

		if (!(*st).isEmpty()) {
			return;
		} else if (!marked[w[i]]) {
			edgeTo[w[i]] = v;
			dfs(G, w[i]);
		} else if (onStack[w[i]]) {
			for (int x = v; x != w[i]; x = edgeTo[x]) (*st).push(x);
			(*st).push(w[i]);
			(*st).push(v);
		}

	}

	onStack[v] = 0;

}
