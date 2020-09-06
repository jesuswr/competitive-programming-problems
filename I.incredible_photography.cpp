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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
int h[MAXN];
int l[MAXN], r[MAXN];

bool vis[MAXN];
ll dp[MAXN];

ll f(int pos) {
	if (vis[pos])
		return dp[pos];
	vis[pos] = true;
	dp[pos] = 0;
	if (l[pos] != -1)
		dp[pos] = max(dp[pos], f(l[pos]) + pos - l[pos]);
	if (r[pos] != -1)
		dp[pos] = max(dp[pos], f(r[pos]) + r[pos] - pos);
	return dp[pos];
}

int main() {
	ri(n);
	FOR(i, 0, n) {
		ri(h[i]);
	}
	stack<int> aux;
	FOR(i, 0, n) {
		int lol = INF;
		while (!aux.empty() && h[aux.top()] <= h[i]) {
			if (h[aux.top()] == h[i])
				lol = min(lol, aux.top());
			aux.pop();
		}
		if (aux.empty())
			l[i] = -1;
		else
			l[i] = aux.top();
		if (lol == INF)
			aux.push(i);
		else
			aux.push(lol);
	}
	while (!aux.empty())
		aux.pop();
	ROF(i, n - 1, -1) {
		int lol = -1;
		while (!aux.empty() && h[aux.top()] <= h[i]) {
			if (h[aux.top()] == h[i])
				lol = max(lol, aux.top());
			aux.pop();
		}
		if (aux.empty())
			r[i] = -1;
		else
			r[i] = aux.top();
		if (lol == -1)
			aux.push(i);
		else
			aux.push(lol);
	}
	FOR(i, 0, n) {
		printf("%lld ", f(i));
	}
	printf("\n");


	return 0;
}