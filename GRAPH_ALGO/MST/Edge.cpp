

class Edge {

private : int v1, v2;
		  double w;

public  : Edge();
		  void set(int a, int b, double c);
		  int either();
		  int other(int vertex);
		  double weight();
		  bool operator ==(Edge & that);
		  bool operator < (Edge & that);
		  bool operator <=(Edge & that);
		  bool operator > (Edge & that);
		  bool operator >=(Edge & that);
		  friend ostream & operator << (ostream & os, Edge & that);

};

Edge::Edge() {

}

void Edge::set(int a, int b, double c) {
	v1 = a;
	v2 = b;
	w  = c;
}

int Edge::either() {
	return v1;
}

int Edge::other(int vertex) {
	if      (vertex == v1) return v2;
	else if (vertex == v2) return v1;
	else                   throw invalid_argument("not a valid vertex od this edge");
}

double Edge::weight() {
	return w;
}

bool Edge::operator == (Edge & that) {
	if (w == that.weight()) return 1;
	else return 0;
}

bool Edge::operator < (Edge & that) {
	if (w < that.weight()) return 1;
	else return 0;
}

bool Edge::operator <= (Edge & that) {
	if (w <= that.weight()) return 1;
	else return 0;
}

bool Edge::operator > (Edge & that) {
	if (w > that.weight()) return 1;
	else return 0;
}

bool Edge::operator >= (Edge & that) {
	if (w >= that.weight()) return 1;
	else return 0;
}

ostream & operator << (ostream & os, Edge & that) {
	int a = that.either();
	int b = that.other(a);
	os << a << "-" << b << " " << that.weight();
	return os;
}