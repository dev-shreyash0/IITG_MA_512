

class KruskalMST {

vector<Edge> * mst;
double w;

public  : KruskalMST(EdgeWeightedGraph & G);
		  vector<Edge> & edges();
		  double weight();

};

KruskalMST::KruskalMST(EdgeWeightedGraph & G) {

	w = 0;
	mst = new vector<Edge>();

	IndexMinPQ<Edge> pq(G.E());
	int e = 0;

	for (Edge & E : G.edges()) pq.insert(e++, E);

	UF uf(G.V());

	while (!pq.isEmpty()) {

		Edge E = pq.minKey();
		int k = pq.delMin();

		int v1 = E.either();
		int v2 = E.other(v1);

		if (uf.find(v1) == uf.find(v2)) continue;

		(*mst).push_back(E);
		w += E.weight();
		uf.connect(v1, v2);

	}

}

vector<Edge> & KruskalMST::edges() {
	return (*mst);
}

double KruskalMST::weight() {
	return w;
}

