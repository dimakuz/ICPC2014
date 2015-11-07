//BEGIN
#define MAX_SIZE 100000
int uf_parent[MAX_SIZE], uf_rank[MAX_SIZE];

void Make_Set(const int x){
	uf_parent[x] = x;
	uf_rank[x] = 1;
}

int Find(const int x){
	if(uf_parent[x] != x)
		uf_parent[x] = Find(uf_parent[x]);
	return uf_parent[x];
}

void Union(const int x, const int y){
	int PX = Find(x), PY = Find(y);

	if (PX == PY)
		return;

	if(uf_rank[PX] > uf_rank[PY]) {
		uf_parent[PY] = PX;
		uf_rank[PX] += uf_rank[PY];
	} else {
		uf_parent[PX] = PY;
		uf_rank[PY] += uf_rank[PX];
	}
}
//END
