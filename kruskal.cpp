//BEGIN
#include <vector>
#include <queue>
#include <map>

using namespace std;


template <typename T>
struct kruskal {
	typedef pair<T ,pair<int, int> > PTII;
	typedef vector<PTII> VPTII;
	typedef priority_queue<PTII, vector<PTII>, greater<PTII> >  Q;

	Q q;
	size_t N;

	kruskal(size_t N) : N(N) {}

	void add_edge(int from, int to, T weight) {
		q.push(make_pair(weight, make_pair(from, to)));
		q.push(make_pair(weight, make_pair(to, from)));
	}

	VPTII run() {
	    VPTII mst_routes;

	    map<int,int> connected;
	    for (int i = 0; i < N; ++i)
		connected[i] = i;

	    while(!q.empty())
	    {
		int u = q.top().second.first;
		int v = q.top().second.second;
		T w = q.top().first;

		int parent_u = connected[u], parent_v = connected[v];
		if(parent_u != parent_v) {
		    mst_routes.push_back(make_pair(w, make_pair(u, v)));
		    for (int i = 0; i < N; ++i) // UNION(u,v)
		    {
			if(connected[i] == parent_v)
			    connected[i] = parent_u;
		    }
		}
		q.pop();
	    }
	    return mst_routes;
	}
};
//END
