// BEGIN
// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.
// Running time: O(|E| log |V|)
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

typedef signed long long int T;
typedef vector<T> VT;
typedef pair<T, T> PII;
typedef vector<PII> VP;
typedef vector<VP> VVP;
const T INFINITY = numeric_limits<T>::max();

struct dijkstra {
	size_t N;
	VVP E;
	VT D;
	dijkstra (size_t N) : N(N), E(N) {}
	void add_edge(T s, T t, T dist) {
		E[s].push_back(make_pair(dist, t));
	}
	void run(T from, T to) {
		D = VT(N, INFINITY);
		priority_queue<PII, VP, greater<PII> > Q;
		D[from] = 0;
		Q.push(make_pair(0, from));
		while (!Q.empty()) {
			PII p = Q.top();
			if (p.second == to) break;
			Q.pop();

			T here = p.second;
			for (VP::iterator it = E[here].begin(); it != E[here].end(); it++) {
				if (D[here] + it->first < D[it->second]) {
					D[it->second] = D[here] + it->first;
					Q.push(make_pair(D[it->second], it->second));
				}
			}
		}
	}
};
//END
