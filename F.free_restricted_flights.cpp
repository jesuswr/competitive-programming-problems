#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e4 + 10; // CAMBIAR ESTE

// GJNM
struct node {
	int to, cst;
};
int v, e;
int a, b, k;

vector<node> G[MAXN];
vector<node> Gi[MAXN];

int from_a[MAXN][11], from_b[MAXN][11], to_a[MAXN][11], to_b[MAXN][11];
int best_a[MAXN], best_b[MAXN];



int main() {
	rii(v, e);
	riii(a, b, k);
	FOR(i, 0, e) {
		int x, y, c;
		riii(x, y, c);
		G[x].pb({y, c});
		Gi[y].pb({x, c});
	}
	memset(from_a, INF, sizeof(from_a));
	memset(from_b, INF, sizeof(from_b));
	memset(to_a, INF, sizeof(to_a));
	memset(to_b, INF, sizeof(from_b));
	memset(best_a, INF, sizeof(best_a));
	memset(best_b, INF, sizeof(best_b));

	priority_queue< piii > dij;
	from_a[a][k] = 0;
	dij.push({ 0 , { k , a } });
	while (!dij.empty()) {
		int x = dij.top().S.S;
		int xc = -dij.top().F;
		int xk = dij.top().S.F;
		dij.pop();

		if (xc > from_a[x][xk])
			continue;

		for (auto aaaa : G[x]) {
			int y = aaaa.to;
			int yc = aaaa.cst;
			if ( from_a[y][xk] > xc + yc ) {
				from_a[y][xk] = xc + yc;
				dij.push({ -(xc + yc), {xk, y} });
			}
			if ( xk > 0 && from_a[y][xk - 1] > xc ) {
				from_a[y][xk - 1] = xc;
				dij.push({ -(xc), {xk - 1, y} });
			}
		}
	}

	from_b[b][k] = 0;
	dij.push({ 0 , { k , b } });
	while (!dij.empty()) {
		int x = dij.top().S.S;
		int xc = -dij.top().F;
		int xk = dij.top().S.F;
		dij.pop();

		if (xc > from_b[x][xk])
			continue;

		for (auto aaaa : G[x]) {
			int y = aaaa.to;
			int yc = aaaa.cst;
			if ( from_b[y][xk] > xc + yc ) {
				from_b[y][xk] = xc + yc;
				dij.push({ -(xc + yc), {xk, y} });
			}
			if ( xk > 0 && from_b[y][xk - 1] > xc ) {
				from_b[y][xk - 1] = xc;
				dij.push({ -(xc), {xk - 1, y} });
			}
		}
	}

	dij;
	to_a[a][k] = 0;
	dij.push({ 0 , { k , a } });
	while (!dij.empty()) {
		int x = dij.top().S.S;
		int xc = -dij.top().F;
		int xk = dij.top().S.F;
		dij.pop();

		if (xc > to_a[x][xk])
			continue;

		for (auto aaaa : Gi[x]) {
			int y = aaaa.to;
			int yc = aaaa.cst;
			if ( to_a[y][xk] > xc + yc ) {
				to_a[y][xk] = xc + yc;
				dij.push({ -(xc + yc), {xk, y} });
			}
			if ( xk > 0 && to_a[y][xk - 1] > xc ) {
				to_a[y][xk - 1] = xc;
				dij.push({ -(xc), {xk - 1, y} });
			}
		}
	}

	to_b[b][k] = 0;
	dij.push({ 0 , { k , b } });
	while (!dij.empty()) {
		int x = dij.top().S.S;
		int xc = -dij.top().F;
		int xk = dij.top().S.F;
		dij.pop();

		if (xc > to_b[x][xk])
			continue;

		for (auto aaaa : Gi[x]) {
			int y = aaaa.to;
			int yc = aaaa.cst;
			if ( to_b[y][xk] > xc + yc ) {
				to_b[y][xk] = xc + yc;
				dij.push({ -(xc + yc), {xk, y} });
			}
			if ( xk > 0 && to_b[y][xk - 1] > xc ) {
				to_b[y][xk - 1] = xc;
				dij.push({ -(xc), {xk - 1, y} });
			}
		}
	}
	/*
	printf("DESDE A\n");
	FOR(i, 0, v) {
		FOR(j, 0, k + 1) {
			printf("nodo:%d k:%d min:%d\n", i, k - j, from_a[i][j]);
		}
	}
	printf("DESDE B\n");
	FOR(i, 0, v) {
		FOR(j, 0, k + 1) {
			printf("nodo:%d k:%d min:%d\n", i, k - j, from_b[i][j]);
		}
	}
	printf("HACIA A\n");
	FOR(i, 0, v) {
		FOR(j, 0, k + 1) {
			printf("nodo:%d k:%d min:%d\n", i, k - j, to_a[i][j]);
		}
	}
	printf("HACIA B\n");
	FOR(i, 0, v) {
		FOR(j, 0, k + 1) {
			printf("nodo:%d k:%d min:%d\n", i, k - j, to_b[i][j]);
		}
	}
	*/

	FOR(i, 0, v) {
		FOR(k1, 0, k + 1) {
			FOR(k2, 0, k + 1) {
				if (k1 + k2 > k)
					continue;
				best_a[i] = min(best_a[i], from_a[i][k - k1] + to_a[i][k - k2]);
				best_b[i] = min(best_b[i], from_b[i][k - k1] + to_b[i][k - k2]);
			}
		}
	}
	int ans = INF;
	int n_ans;
	FOR(i, 0, v) {
		if (i == a || i == b)
			continue;
		if (ans > best_b[i] + best_a[i]) {
			ans = best_a[i] + best_b[i];
			n_ans = i;
		}
	}

	if (ans == INF) {
		printf(">:(\n");
	}
	else {
		printf("%d %d\n", n_ans, ans);
	}




	return 0;
}