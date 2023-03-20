class DirectedBFS {

private: int * marked;
		 int * edgeTo;
		 int * distTo;
		 int n;         // number of vertices in DiGraph
		 int s;         // source vertex
		 int c;         // number of vertices in connected component containing source vertex

public : DirectedBFS(DiGraph &G, int S);
		 int  distanceTo(int V);
		 bool hasPathTo(int V); 
		 void pathTo(int d, vector<int> &v);
		 int  count();

private: void bfs(DiGraph &G, int S);
	     void validateVertex(int V);
	     void reverse(vector<int> &v);

};

DirectedBFS::DirectedBFS(DiGraph &G, int S) {

	n = G.V();

	marked = new int[n];
	edgeTo = new int[n];
	distTo = new int[n];

	for (int i = 0; i < n; i++) {
		marked[i] = 0;
		edgeTo[i] = -1;
		distTo[i] = -1;
	}

	s = S;
	c = 0;

	bfs(G, S);

}

int DirectedBFS::count() {
	return c;
}

int DirectedBFS::distanceTo(int V) {
	validateVertex(V);
	return distTo[V];
}

bool DirectedBFS::hasPathTo(int V) {
	validateVertex(V);
	return marked[V];
}

void DirectedBFS::pathTo(int d, vector<int> &v) {

	validateVertex(d);

	if (!hasPathTo(d)) return;

	v.push_back(d);

	while (edgeTo[d] != s) {
		v.push_back(edgeTo[d]);
		d = edgeTo[d];
	}

	v.push_back(s);

	reverse(v);

}

void DirectedBFS::reverse(vector<int> &v) {
	
	int i = 0, j = v.size()-1;

	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++;
		j--;
	}

}

void DirectedBFS::bfs(DiGraph &G, int S) {

	validateVertex(S);

	Queue<int> que;

	marked[S] = 1;
	c++;
	que.enqueue(S);
	distTo[S] = 0;

	while (!que.isEmpty()) {

		int v = que.dequeue();

		vector<int> vect;

		G.adjVertices(v, vect);

		for (int i = 0; i < vect.size(); i++) {
			if (!marked[vect[i]]) {
				edgeTo[vect[i]] = v;
				distTo[vect[i]] = distTo[v] + 1;
				marked[vect[i]] = 1;
				c++;
				que.enqueue(vect[i]);
			}
		}

	}

}

void DirectedBFS::validateVertex(int V) {
	if (V < 0 || V >= n) throw invalid_argument("not valid vertex");
}