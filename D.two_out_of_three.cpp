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
const int maxN = 1010; // CAMBIAR ESTE

// GJNM
int n;
int A[maxN];
int dp[maxN][maxN];
pii nxt[maxN][maxN];
bool stp[maxN][maxN];

int f(int left, int ind) {
	if ( dp[left][ind] != 0 )
		return dp[left][ind];

	int &ret = dp[left][ind];
	if ( ind == n - 1 ) {
		nxt[left][ind] = { left, ind};
		stp[left][ind] = true;
		return ret = max(A[left], A[ind]);
	}
	if ( ind == n ) {
		nxt[left][ind] = { left, -1};
		stp[left][ind] = true;
		return ret = A[left];
	}
	int a1 = max(A[left], A[ind]) + f(ind + 1, ind + 2);
	int a2 = max(A[left], A[ind + 1]) + f(ind, ind + 2);
	int a3 = max(A[ind], A[ind + 1]) + f(left, ind + 2);

	if ( a1 <= a2 && a1 <= a3 ) {
		nxt[left][ind] = {left, ind};
		return ret = a1;
	}
	else if ( a2 <= a3 ) {
		nxt[left][ind] = {left, ind + 1};
		return ret = a2;
	}
	else {
		nxt[left][ind] = {ind, ind + 1};
		return ret = a3;
	}
}

int main() {
	ri(n);
	FOR(i, 0, n) {
		ri(A[i]);
	}
	int ans = f(0, 1);
	printf("%d\n", ans);
	int l = 0, i = 1;
	while (true) {
		printf("%d", nxt[l][i].F + 1);
		if ( nxt[l][i].S != -1 ) {
			printf(" %d", nxt[l][i].S + 1);
		}
		printf("\n");
		if (stp[l][i])
			break;
		l = l ^ i ^ (i + 1) ^ nxt[l][i].F ^ nxt[l][i].S;
		i += 2;
	}
	return 0;
}