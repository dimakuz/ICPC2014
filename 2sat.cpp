//BEGIN
class TwoSatSolver {
public:
	size_t atoms, size;
	vector<vector<size_t> > alist, alist_rev;
	vector<bool> visited, solution;
	list<size_t> post_order;

	TwoSatSolver(size_t atoms)
		: atoms(atoms), size(atoms * 2 + 1), alist(size),
		  alist_rev(size), visited(size, false), solution(size, false)
	{}

	size_t to_index(int a) {
		if (a < 0)
			a = -a + atoms;
		return a;
	}

	void add_clause(int a, int b) {
		a = to_index(a);
		b = to_index(b);
		add_edge(not_(a), b);
		add_edge(not_(b), a);
	}

	void add_edge(size_t from, size_t to) {
		alist[from].push_back(to);
		alist_rev[to].push_back(from);
	}

	void dfs(size_t from) {
		visited[from] = true;
		for (auto itr : alist[from]) {
			if (!visited[itr])
				dfs(itr);
		}
		post_order.push_back(from);
	}

	void dfsr(size_t from) {
		visited[from] = false;
		solution[from] = true;
		for (auto itr : alist_rev[from]) {
			if (visited[itr])
				dfsr(itr);
		}
	}

	size_t not_(size_t n) {
		if (n > atoms)
			return n - atoms;
		return n + atoms;
	}

	bool satisfiable() {
		for (size_t i = 1; i < size; i++)
			if (!visited[i])
				dfs(i);

		for (auto it = post_order.rbegin(); it != post_order.rend(); it++)
			if (visited[*it] && visited[not_(*it)])
				dfsr(*it);

		for (size_t i = 1; i <= atoms; i++)
			if (solution[i] && solution[not_(i)])
				return false;
		return true;
	}
};
//END
