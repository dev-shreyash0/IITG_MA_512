
class DepthFirstOrder {

private: bool * marked;
	 int * preNum;
	 int * postNum;
	 Queue<int> * pre;
	 Queue<int> * post;
	 int pr;
	 int po;
	 int n;

public : DepthFirstOrder(DiGraph &G);
	 void preOrder(vector<int> &v);
	 void postOrder(vector<int> &v);
	 void reversePost(vector<int> &v);
	 int preOrder(int v);
	 int postOrder(int v);

private: void dfs(DiGraph &G, int v);
	 void validateVertex(int v);
	 void reverse(vector<int> &v);

};

DepthFirstOrder::DepthFirstOrder(DiGraph &G) {
	
	n = G.V();
	pr = 0;
	po = 0;

	marked = new bool[n];
	preNum = new int[n];
	postNum = new int[n];

	pre = new Queue<int>();
	post = new Queue<int>();

	for (int i = 0; i < n; i++) marked[i] = 0;

	for (int i = 0; i < n; i++) if (!marked[i]) dfs(G, i);

}

void DepthFirstOrder::preOrder(vector<int> &v) {
	(*pre).items(v);
}

void DepthFirstOrder::postOrder(vector<int> &v) {
        (*post).items(v);
}

void DepthFirstOrder::reversePost(vector<int> &v) {
        (*post).items(v);
	reverse(v);
}

int DepthFirstOrder::preOrder(int v) {
	validateVertex(v);
        return preNum[v];
}

int DepthFirstOrder::postOrder(int v) {
        validateVertex(v);
	return postNum[v];
}   

void DepthFirstOrder::validateVertex(int v) {
	if (v < 0 || v >= n) throw invalid_argument("vertex not valid");
}

void DepthFirstOrder::dfs(DiGraph &G, int v) {
	
	marked[v] = 1;
	preNum[v] = pr++;
	(*pre).enqueue(v);

	vector<int> w;
	G.adjVertices(v, w);

	for (int i = 0; i < w.size(); i++) if (!marked[w[i]]) dfs(G, w[i]);

	postNum[v] = po++;
	(*post).enqueue(v);

}

void DepthFirstOrder::reverse(vector<int> &v) {
	
	int i = 0, j = v.size()-1;
	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++;
		j--;
	}

}
