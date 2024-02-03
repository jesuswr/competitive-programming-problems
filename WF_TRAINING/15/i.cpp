#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>
#include <queue>

using namespace std;

const int MAXN = 501;
const long long INFLL = 1e15;

int N, M;
vector< pair<int, long long> > G[MAXN];
long long DST[MAXN][MAXN];
bool E[MAXN][MAXN];
vector <pair<long long, int> > SRTD_DST[MAXN];

void input() {
    int das=scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) DST[i][j] = i == j ? 0 : INFLL;
    for(int _ = 0; _ < M; _++) {
        int u, v; long long w;
        das=scanf("%d %d %lld\n", &u, &v, &w);
        --u; --v;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
        DST[u][v] = DST[v][u] = min(DST[u][v], w);
        E[u][v] = E[v][u] = 1;
    }
}

tuple<int,int,long long> go(int u, int v) {
    vector<bool> used(N);
    int ptr = 0, ptr2 = N-1;
    tuple<int, int, long long> ans = {-1,-1,INFLL};
    for(int i = 0; i < N; i++) {
        auto [dst_fu, fu] = SRTD_DST[u][i];
        while(ptr < N && dst_fu == SRTD_DST[u][ptr].first) {
            used[SRTD_DST[u][ptr].second] = 1;
            ptr++;
        }

        while(ptr2 >= 0 && used[ SRTD_DST[v][ptr2].second ]) --ptr2;

        if (fu == v) continue;

        int fv = ptr2 >= 0 ? SRTD_DST[v][ptr2].second : v;
        long long dst_fv = DST[v][fv];
        long long dia = dst_fu + dst_fv + DST[u][v];

        if (dst_fu <= dst_fv + DST[u][v] && dst_fv <= dst_fu + DST[u][v]) {
            long long curr_dia = get<2>(ans);
            if (dia < curr_dia) {
                ans = {fu, fv, dia};
            }
        }
    }
    return ans;
}

int main() {
    input();
    long long mn_dia = INFLL;
    vector<int> vals(4);
    for(int u = 0; u < N; u++) {
        SRTD_DST[u].resize(N);
        for(int v = 0; v < N; v++) SRTD_DST[u][v] = make_pair(DST[u][v], v);
        sort(SRTD_DST[u].begin(), SRTD_DST[u].end());
    }
    for(int u = 0; u < N; u++) {
        for(int v = 0; v < N; v++) {
            if (u == v || !E[u][v]) continue;
            auto [fu, fv, dia] = go(u,v);
            if (dia < mn_dia) {
                mn_dia = dia;
                vals[0] = u;
                vals[1] = v;
                vals[2] = fu;
                vals[3] = fv;
            }
        }
    }
    

    int center0 = vals[0], center1 = vals[1], furthest0 = vals[2], fv = vals[3];
    long long ans = min_dia;

    ans /= 2;
	vector<LL> tree_dist(n, inf);
	tree_dist[center0] = ans - dist[center0][furthest0];
	tree_dist[center1] = graph[center0][center1] - tree_dist[center0];
	REP(iter, n)
		REP(v, n)
			REP(u, n)
				tree_dist[u] = min(tree_dist[u], tree_dist[v] + graph[v][u]);
 
	vector<pair<int, int>> cur = {{center0, center1}};
	REP(i, n)
		if(i != center0 and i != center1) {
			int from = -1;
			REP(k, n)
				if(k != i)
					if(tree_dist[i] == tree_dist[k] + graph[i][k])
						from = k;
			assert(from != -1);
			assert(i != from);
			cur.emplace_back(i, from);
		}
	assert(ssize(cur) == n - 1);
 
	cout << ans << '\n';
	for (auto [a, b] : cur)
		cout << a + 1 << ' ' << b + 1 << '\n';
 
}