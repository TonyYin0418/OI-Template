#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM = 2e5, MAXN = 210, inf = 0x3f3f3f3f;
int n, m, S, T;
struct Edge{
	int to, val, nxt;
} edge[MAXM];
int head[MAXN], e_cnt = 1;
inline void Add(int u, int v, int w) {
	edge[++e_cnt] = (Edge){v, w, head[u]};
	head[u] = e_cnt;
}
inline void add_edge(int u, int v, int w) {
	Add(u, v, w);
	Add(v, u, 0);
}
int lev[MAXN];
inline bool bfs() {
	memset(lev, -1, sizeof(lev)); lev[S] = 0;
	queue<int> q; q.push(S);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].to, w = edge[i].val;
			if(lev[v] == -1 && w) {
				lev[v] = lev[u] + 1;
				q.push(v);
			}
		}
	}
	return lev[T] != -1;
}
int dfs(int x, int flow) {
	if(x == T) return flow;
	int ret = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int v = edge[i].to, w = edge[i].val;
		if(lev[v] == lev[x] + 1 && w) {
			int tmp = dfs(v, min(flow, w));
			ret += tmp, flow -= tmp;
			edge[i].val -= tmp, edge[i ^ 1].val += tmp;
			if(!flow) break;
		}
	}
	if(!ret) lev[x] = -1;
	return ret;
}
inline int Dinic() {
	int ret = 0;
	while(bfs()) ret += dfs(S, inf);
	return ret;
}
signed main() {
	cin >> n >> m >> S >> T;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	cout << Dinic() << endl;
	return 0;
}