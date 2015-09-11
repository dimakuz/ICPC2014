//BEGIN
#include <vector>
#include <queue>

using namespace std;

template <typename T>
struct prims {
	struct E {
		int from;
		int to;
		T weight;

		E(int from, int to, T weight) : from(from), to(to), weight(weight) {}
		bool operator < (const E &r) const {
			return r.weight < weight;
		}
	};
	typedef vector<E> VE;
	typedef vector<VE> VVE;

	VVE alist;

	prims(size_t size) : alist(size, VE()) {}

	void add_edge(int from, int to, T weight) {
		_add_edge(from, to, weight);
		_add_edge(to, from, weight);
	}

	void _add_edge(int from, int to, T weight) {
		alist[from].push_back(E(from, to, weight));
	}


	VVE run(int start) {
		VVE result(alist.size(), VE());
		vector<bool> visited(alist.size(), false);
		priority_queue<E> q;

		for (int i = 0; i < alist[start].size(); i++)
			q.push(alist[start][i]);
		visited[start] = true;

		while (!q.empty()) {
			E cur = q.top();
			q.pop();
			if (visited[cur.to])
				continue;

			visited[cur.to] = true;
			result[cur.from].push_back(cur);

			for (int i = 0; i < alist[cur.to].size(); i++) {
				if (!visited[alist[cur.to][i].to])
					q.push(alist[cur.to][i]);
			}
		}
		return result;
	}
};
//END
