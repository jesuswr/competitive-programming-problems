#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define riii(a,b,c) ri(a), ri(b), ri(c)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

ii edges[MAXN];
bool sp[MAXN];
vi G[MAXN];
vi GR[MAXN];

int n, m, q;

int dp[MAXN];
int getSize(int e) {
	if (e == 1) return m;
	if (dp[e] != -1) return dp[e];

	int v = edges[e].F;
	if (sp[v]) {
		int vInput = getSize(GR[v][0]);
		int sz = (vInput + 1) / 2;
		if (e == G[v][0]) return dp[e] = sz;
		else return dp[e] = vInput - sz;
	}
	else {
		int vInput1 = getSize(GR[v][0]);
		int vInput2 = getSize(GR[v][1]);
		return dp[e] = vInput1 + vInput2;
	}
}

char tmp[5];

int query(int e, int k) {
	if (k > getSize(e)) return -1;
	if (e == 1) return k;

	int newK = -1, newE = -1;
	int v = edges[e].F;
	if (sp[v]) {
		newK = 2 * k;
		if (e == G[v][0]) newK--;
		newE = GR[v][0];
	}
	else {
		int sz1 = getSize(GR[v][0]);
		int sz2 = getSize(GR[v][1]);
		int minSize = min(sz1, sz2);
		int big = (sz1 > sz2) ? 0 : 1;
		if (k <= 2 * minSize) {
			newK = (k + 1) / 2;
			newE = GR[v][(k + 1) % 2];
		}
		else {
			newK = k - minSize;
			newE = GR[v][big];
		}
	}
	return query(newE, newK);
}

int main() {
	ms(dp, -1);

	riii(m, n, q);
	FOR(i, 0, n) {
		int x, y, z;
		scanf("%s", tmp);
		riii(x, y, z);
		sp[i] = (tmp[0] == 'S');

		if (sp[i]) {
			GR[i].pb(x);
			G[i].pb(y);
			G[i].pb(z);

			edges[x].S = i;
			edges[y].F = i;
			edges[z].F = i;
		}
		else {
			GR[i].pb(x);
			GR[i].pb(y);
			G[i].pb(z);

			edges[x].S = i;
			edges[y].S = i;
			edges[z].F = i;
		}
	}

	FOR(i, 0, q) {
		int x, k;
		rii(x, k);
		int ans = query(x, k);
		if (ans != -1) printf("%d\n", query(x, k) );
		else printf("none\n");
	}
	return 0;
}