class EagerPrimMST {

private : Edge ** edgeTo;
		  double * distTo;
		  bool * marked;
		  IndexMinPQ<double> * pq;

		  int n;

public  : EagerPrimMST(EdgeWeightedGraph & G);
		  vector<Edge> & edges();
		  double weight();

private : void prim(EdgeWeightedGraph & G, int s);
		  void scan(EdgeWeightedGraph & G, int s);

};

EagerPrimMST::EagerPrimMST(EdgeWeightedGraph & G) {

	n = G.V();

	edgeTo = new Edge*[n];
	distTo = new double[n];
	marked = new bool[n];
	pq     = new IndexMinPQ<double>(n);

	for (int i = 0; i < n; i++) {
		distTo[i] = DBL_MAX;
		edgeTo[i] = NULL;
	}

	for (int i = 0; i < n; i++) if (!marked[i]) prim(G, i);

}

double EagerPrimMST::weight() {
	double w = 0;
	for (Edge & E : edges()) w += E.weight();
	return w;
}

void EagerPrimMST::prim(EdgeWeightedGraph & G, int s) {
	distTo[s] = 0.0;
	(*pq).insert(s, distTo[s]);
	while (!(*pq).isEmpty()) {
		int v = (*pq).delMin();
		scan(G, v);
	}
}

void EagerPrimMST::scan(EdgeWeightedGraph & G, int s) {
	marked[s] = 1;
	for (Edge & E : G.adjEdges(s)) {
		int w = E.other(s);
		if (marked[w]) continue;
		if (E.weight() < distTo[w]) {
			distTo[w] = E.weight();
		    edgeTo[w] = &E;
		    if ((*pq).contains(w)) (*pq).decreaseKey(w, distTo[w]);
		    else (*pq).insert(w, distTo[w]);
		}
	}
}

vector<Edge> & EagerPrimMST::edges() {
	vector<Edge> * mst = new vector<Edge>();
	for (int i = 0; i < n; i++) if (edgeTo[i] != NULL) (*mst).push_back(*(edgeTo[i]));
  	return (*mst);
}

