
class EdgeWeightedGraph {

private : int v, e;
		  Queue<Edge> ** adj;

public  : EdgeWeightedGraph(int V);
		  EdgeWeightedGraph(string s);
		  int V();
		  int E();
		  void addEdge(Edge & E);
		  vector<Edge> & adjEdges(int V);
		  void adjEdges(vector<Edge> & vect, int V);
		  int degree(int V);
		  vector<Edge> & edges();
		  friend ostream & operator << (ostream & os, EdgeWeightedGraph & G);

private : void validateVertex(int V);

};

EdgeWeightedGraph::EdgeWeightedGraph(int V) {

	if (V < 0) throw invalid_argument("vertices can't be negative");

	v = V;
	e = 0;

	adj = new Queue<Edge>* [v];
	for (int i = 0; i < v; i++) adj[i] = new Queue<Edge>();

}

EdgeWeightedGraph::EdgeWeightedGraph(string s) {

	int n = 0;

	ifstream of;
	of.open(s.c_str());

	of >> v;
	of >> n;

	adj = new Queue<Edge>* [v];
	for (int i = 0; i < v; i++) adj[i] = new Queue<Edge>();

	for (int i = 0; i < n; i++) {
		int a, b;
		double c;
		of >> a;
		of >> b;
		of >> c;
		Edge E;
		E.set(a, b, c);
		addEdge(E);
	}

	of.close();

}

int EdgeWeightedGraph::V() {
	return v;
}

int EdgeWeightedGraph::E() {
	return e;
}

void EdgeWeightedGraph::addEdge(Edge & E) {
	int v1 = E.either();
	int v2 = E.other(v1);
	validateVertex(v1);
	validateVertex(v2);
	(*adj[v1]).enqueue(E);
	(*adj[v2]).enqueue(E);
	e++;
}

vector<Edge> & EdgeWeightedGraph::adjEdges(int V) {
	validateVertex(V);
	return (*adj[V]).items();
}

void EdgeWeightedGraph::adjEdges(vector<Edge> & vect, int V) {
	validateVertex(V);
	(*adj[V]).items(vect);
}

int EdgeWeightedGraph::degree(int V) {
	validateVertex(V);
	return (*adj[V]).size();
}

vector<Edge> & EdgeWeightedGraph::edges() {

	vector<Edge> * list = new vector<Edge>();

	for (int i = 0; i < v; i++) {

		int sL = 0;

		for (Edge E : (*adj[i]).items()) {
			if (E.other(i) > i) {
				(*list).push_back(E);
			} else if (E.other(i) == i) {
				if (sL % 2 == 0) (*list).push_back(E);
				sL++;
			}
		}

	} 

	return (*list);

}

ostream & operator << (ostream & os, EdgeWeightedGraph & G) {

	os << G.V() << endl;
	os << G.E() << endl;
	for (Edge & E : G.edges()) os << E << endl;

	return os;

}

void EdgeWeightedGraph::validateVertex(int V) {
	if (V < 0 || V >= v) throw invalid_argument("not a valid vertex");
}

