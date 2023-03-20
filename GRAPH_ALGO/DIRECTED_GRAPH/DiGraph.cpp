class DiGraph {

private : int v;
		  int e;	
          Queue<int> ** adj;
          int * inD;

public  : DiGraph(int v);
		  DiGraph(string s);
          int V();
          int E();
          void addEdge(int V, int W);
          void adjVertices(int V, vector<int> &v);
          int outDegree(int V);
          int inDegree(int V);
          DiGraph reverse();
          void print();


private : void validateVertex(int V);

};

DiGraph::DiGraph(int V) {

	if (V < 0) throw invalid_argument("number of vertices can't be negative");

	v   = V;
	e   = 0;
	adj = new Queue<int>* [v];
	inD = new int[v];

	for (int i = 0; i < v; i++) inD[i] = 0;
	for (int i = 0; i < v; i++) adj[i] = new Queue<int>();

}

DiGraph::DiGraph(string s) {

	ifstream iF;
	iF.open(s.c_str());

	int E;

	iF >> v;
	iF >> E;

	e = 0;

	adj = new Queue<int>* [v];
	inD = new int[v];

	for (int i = 0; i < v; i++) inD[i] = 0;
	for (int i = 0; i < v; i++) adj[i] = new Queue<int>();

	for (int i = 0; i < E; i++) {
		int a, b;
		iF >> a;
		iF >> b;
 		addEdge(a, b);
	}

	iF.close();

}

int DiGraph::V() {
	return v;
}

int DiGraph::E() {
	return e;
}

void DiGraph::validateVertex(int V) {
	if (V < 0 || V >= v) throw invalid_argument("vertex not valid");
}

void DiGraph::addEdge(int V, int W) {
	validateVertex(V);
	validateVertex(W);
	(*adj[V]).enqueue(W);
	inD[W]++;
	e++;
}

void DiGraph::adjVertices(int V, vector<int> &v) {
	validateVertex(V);
	(*adj[V]).items(v);
}

int DiGraph::outDegree(int V) {
	validateVertex(V);
	return (*adj[V]).size();
}

int DiGraph::inDegree(int V) {
	validateVertex(V);
	return inD[V];
}

DiGraph DiGraph::reverse() {

	DiGraph D(v);

	for (int i = 0; i < v; i++) {
		vector<int> w;
		adjVertices(i, w);
		for (int j = 0; j < w.size(); j++) D.addEdge(w[j], i);
	}
	
	return D;

}

void DiGraph::print() {

	cout << "Vertices :: " << v << endl;
	cout << "Edges    :: " << e << endl;

	for (int i = 0; i < v; i++) {
		vector<int> w;
		adjVertices(i, w);
		for (int j = 0; j < w.size(); j++) cout << i << " --> " << w[j] << endl;
	}

}
