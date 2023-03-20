

class UF {

private : int * parent;
		  int * rank;
		  int components;
		  int elements;

public  : UF(int n);
		  int count();
		  void connect(int p, int q);
		  int find(int p);  

private : void validate(int p);

};

UF::UF(int n) {

	parent = new int[n];
	rank   = new int[n];

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i]   = 0;
	}

	components = n;
	elements   = n;

}

int UF::count() {
	return components;
}

int UF::find(int p) {

	validate(p);

	while (p != parent[p]) {
		parent[p] = parent[parent[p]];
		p = parent[p];
	}

	return p;

}

void UF::connect(int p, int q) {

	validate(p);
	validate(q);

	int rootP = find(p);
	int rootQ = find(q);

	if (rootP == rootQ) return;

	if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
	else if (rank[rootQ] < rank[rootP]) parent[rootQ] = rootP;
	else {
		parent[rootQ] = rootP;
		rank[rootP]++;
	}

	components--;

}

void UF::validate(int p) {
	if (p < 0 || p >= elements) throw invalid_argument("not a valid input to find()");
}