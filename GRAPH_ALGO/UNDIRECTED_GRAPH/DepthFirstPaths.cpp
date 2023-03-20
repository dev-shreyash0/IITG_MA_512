
class DepthFirstPaths {

private : int * marked;
		  int * edgeTo;
		  int S;         // source vertex
		  int size;      // number of vertices in graph
		  int n;         // number of vertices in connected component containing vertix s

public  : DepthFirstPaths(Graph &G, int s);
		  bool hasPathTo(int V);
		  int  count();
		  void pathTo(int d, vector<int> &v);

private : void validate(int V); 
          void dfs(Graph &G, int V);
          void reverse(vector<int> &v);

};

DepthFirstPaths::DepthFirstPaths(Graph &G, int s) {

	S = s; 

	marked = new int[G.V()];
	for (int i = 0; i < G.V(); i++) marked[i] = 0;

	edgeTo = new int[G.V()];
	for (int i = 0; i < G.V(); i++) edgeTo[i] = -1;

	n = 0;
	size = G.V();

	dfs(G, s);

}

bool DepthFirstPaths::hasPathTo(int V) {
	validate(V);
	return marked[V];
}

int DepthFirstPaths::count() {
	return n;
}

void DepthFirstPaths::validate(int V) {
	if (V < 0 || V >= size) throw invalid_argument("not valid vertex");
}

void DepthFirstPaths::dfs(Graph &G, int V) {

	n++;
	marked[V] = 1;

	vector<int> v;
	G.adjVertices(V, v);

	for (int i = 0; i < v.size(); i++) {
		if (!marked[v[i]]) {
			edgeTo[v[i]] = V;
			dfs(G, v[i]);
		}
	}

}

void DepthFirstPaths::pathTo(int d, vector<int> &v) {

	validate(d);
	if (!hasPathTo(d)) return;

	v.push_back(d);

	while (edgeTo[d] != S) {
		v.push_back(edgeTo[d]);
		d = edgeTo[d];
	}

	v.push_back(S);

	reverse(v);

} 

void DepthFirstPaths::reverse(vector<int> &v) {
	
	int i = 0, j = v.size()-1;

	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++;
		j--;
	}

}