
class Graph {

private : int v;
		  int e;	
          Queue<int> ** adj;

public  : Graph(int v);
		  Graph(string s);
          int V();
          int E();
          void addEdge(int V, int W);
          void adjVertices(int V, vector<int> &v);
          int degree(int V);
          void print();


private : void validateVertex(int V);

};

Graph::Graph(int V) {

	if (V < 0) throw invalid_argument("number of vertices can't be negative");

	v   = V;
	e   = 0;
	adj = new Queue<int>* [v];

	for (int i = 0; i < v; i++) adj[i] = new Queue<int>();

}

Graph::Graph(string s) {

	ifstream iF;
	iF.open(s.c_str());

	int E;

	iF >> v;
	iF >> E;

	e = 0;

	adj = new Queue<int>* [v];

	for (int i = 0; i < v; i++) adj[i] = new Queue<int>();

	for (int i = 0; i < E; i++) {
		int a, b;
		iF >> a;
		iF >> b;
 		addEdge(a, b);
	}

	iF.close();

}

int Graph::V() {
	return v;
}

int Graph::E() {
	return e;
}

void Graph::validateVertex(int V) {
	if (V < 0 || V >= v) throw invalid_argument("vertex not valid");
}

void Graph::addEdge(int V, int W) {
	validateVertex(V);
	validateVertex(W);
	(*adj[V]).enqueue(W);
	(*adj[W]).enqueue(V);
	e++;
}

void Graph::adjVertices(int V, vector<int> &v) {
	validateVertex(V);
	(*adj[V]).items(v);
}

int Graph::degree(int V) {
	validateVertex(V);
	return (*adj[V]).size();
}

void Graph::print() {

	cout << "Vertices :: " << v << endl;
	cout << "Edges    :: " << e << endl;

	for (int i = 0; i < v; i++) {
		cout << i << " :: ";
		vector<int> w;
		adjVertices(i, w);
		for (int j = 0; j < w.size(); j++) cout << w[j] << " ";
		cout << endl;
	}

}







