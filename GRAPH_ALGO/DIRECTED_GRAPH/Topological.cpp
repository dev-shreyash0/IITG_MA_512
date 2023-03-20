

class Topological {

private : vector<int> * ord;
	  int * ra;
	  int n;
	  bool hc;

public  : Topological(DiGraph &G);
	  bool hasOrder();
	  void order(vector<int> &v);
	  int rank(int v);

private : void validateVertex(int v);

};

Topological::Topological(DiGraph &G) {
	
	n = G.V();

	ord = new vector<int>();
	ra = new int[n];

	DirectedCycle finder(G);

	if (finder.hasCycle()) {
		hc = 0;
		return;
	} else {

		hc = 1;
		
		DepthFirstOrder dfo(G);

		dfo.reversePost(*ord);

		int i = 0;

		for (int j = 0; j < (*ord).size(); j++) ra[(*ord)[j]] = i++;
	}

}

bool Topological::hasOrder() {
	return hc;
}

void Topological::order(vector<int> &v) {
	for (int i = 0; i < n; i++) v.push_back((*ord)[i]);
}

int Topological::rank(int v) {
	validateVertex(v);
	if (!hc) return -1;
	else return ra[v];
}

void Topological::validateVertex(int v) {
	if (v < 0 || v >= n) throw invalid_argument("not valid vertex");
}



