
class LazyPrimMST {

private : vector<Edge> * mst;
		  IndexMinPQ<Edge> * pq;
		  bool * marked;
		  double w;
		  int e;

public  : LazyPrimMST(EdgeWeightedGraph & G);
		  vector<Edge> & edges();
		  double weight();

private :void prim(EdgeWeightedGraph & G, int s);
         void scan(EdgeWeightedGraph & G, int s);

};

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph & G) {

	w = 0;
	e = 0;
	mst = new vector<Edge>();
	pq =  new IndexMinPQ<Edge>(G.E());
	marked = new bool[G.V()];

	for (int i = 0; i < G.V(); i++) marked[i] = 0;

	for (int i = 0; i < G.V(); i++) if (!marked[i]) prim(G, i);

}

vector<Edge> & LazyPrimMST::edges() {
	return (*mst);
}

double LazyPrimMST::weight() {
	return w;
}

void LazyPrimMST::prim(EdgeWeightedGraph & G, int s) {

	scan(G, s);
	
	while (!(*pq).isEmpty()) {

		Edge E = (*pq).minKey();

		int k = (*pq).delMin();

		int v1 = E.either();
		int v2 = E.other(v1);

		if (marked[v1] && marked[v2]) continue;

		(*mst).push_back(E);
		w += E.weight();

		if (!marked[v1]) scan(G, v1);
		if (!marked[v2]) scan(G, v2);
 	}


}

void LazyPrimMST::scan(EdgeWeightedGraph & G, int s) {

	marked[s] = 1;

	for (Edge & E : G.adjEdges(s)) if (!marked[E.other(s)]) (*pq).insert(e++,E);

}
