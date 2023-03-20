
class Bipartite {

private : bool isBip;
		  bool * col;
		  bool * marked;
		  int * edgeTo;
		  Stack<int> * cycle;

		  int n;

public  : Bipartite(Graph &G);
		  bool isBipartite();
		  bool color(int v);
		  void oddCycle(vector<int> &v);

private : void dfs(Graph &G, int s);
		  void validateVertex(int v);

};

Bipartite::Bipartite(Graph &G) {

	isBip = 1;
	n = G.V();

	col = new bool[n];
	marked = new bool[n];
	edgeTo = new int[n];

	cycle = new Stack<int>();

	for (int i = 0; i < n; i++) {
		col[i] = 0;
		marked[i] = 0;
		edgeTo[i] = -1;
	}

	for (int i = 0; i < n; i++) if (!marked[i]) dfs(G, i);

}

void Bipartite::dfs(Graph &G, int s) {

	marked[s] = 1;

	vector<int> v;

	G.adjVertices(s, v);

	for (int i = 0; i < v.size(); i++) {

		if (!((*cycle).isEmpty())) return;

		if (!marked[v[i]]) {
			edgeTo[v[i]] = s;
			col[v[i]] = !col[s];
			dfs(G, v[i]);
		} else if (col[v[i]] == col[s]) {
			isBip = 0;
			(*cycle).push(v[i]);
			int w = v[i];
			for (int x = s; x != w; x = edgeTo[x]) (*cycle).push(x);
			(*cycle).push(v[i]);
		}

	}

}

bool Bipartite::isBipartite() {
	return isBip;
} 

bool Bipartite::color(int v) {
	validateVertex(v);
	if (!isBipartite()) throw runtime_error("color not supported as graph is not bipartite");
	return col[v];
} 

void Bipartite::validateVertex(int v) {
	if (v < 0 || v >= n) throw invalid_argument("");
}

void Bipartite::oddCycle(vector<int> &v) {
	(*cycle).items(v);
}