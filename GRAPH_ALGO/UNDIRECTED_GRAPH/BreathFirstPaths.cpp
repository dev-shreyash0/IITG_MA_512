
class BreathFirstPaths {

private: int * marked;
		 int * edgeTo;
		 int * distTo;
		 int n;         // number of vertices in graph
		 int s;         // source vertex
		 int c;         // number of vertices in connected component containing source vertex

public : BreathFirstPaths(Graph &G, int S);
		 int  distanceTo(int V);
		 bool hasPathTo(int V); 
		 void pathTo(int d, vector<int> &v);
		 int  count();

private: void bfs(Graph &G, int S);
	     void validateVertex(int V);
	     void reverse(vector<int> &v);

};

BreathFirstPaths::BreathFirstPaths(Graph &G, int S) {

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

int BreathFirstPaths::count() {
	return c;
}

int BreathFirstPaths::distanceTo(int V) {
	validateVertex(V);
	return distTo[V];
}

bool BreathFirstPaths::hasPathTo(int V) {
	validateVertex(V);
	return marked[V];
}

void BreathFirstPaths::pathTo(int d, vector<int> &v) {

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

void BreathFirstPaths::reverse(vector<int> &v) {
	
	int i = 0, j = v.size()-1;

	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++;
		j--;
	}

}

void BreathFirstPaths::bfs(Graph &G, int S) {

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

void BreathFirstPaths::validateVertex(int V) {
	if (V < 0 || V >= n) throw invalid_argument("not valid vertex");
}