
class GraphProcessing {

private : GraphProcessing();

public  : static int degree(Graph &G, int V);
		  static int maxDegree(Graph &G);
		  static double averageDegree(Graph &G);
		  static int numberOfSelfLoops(Graph &G);
	
};

GraphProcessing::GraphProcessing() {

}

int GraphProcessing::degree(Graph &G, int V) {

	vector<int> v;
	G.adjVertices(V, v);
	return v.size();

}

int GraphProcessing::maxDegree(Graph &G) {

	int max = 0;
	for (int i = 0; i < G.V(); i++) if (degree(G, i) > max) max = degree(G, i);
	return max;

}

double GraphProcessing::averageDegree(Graph &G) {
	return (2.0 * G.E())/G.V();
}

int GraphProcessing::numberOfSelfLoops(Graph &G) {

	int count;

	for (int i = 0; i < G.V(); i++) {
		vector<int> v;
		G.adjVertices(i, v);
		for (int j = 0; j < v.size(); j++) if (i == v[j]) count++;
	}

	return count/2;

}


