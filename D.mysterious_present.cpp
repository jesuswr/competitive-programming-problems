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
const int maxN = 5010; // CAMBIAR ESTE

// GJNM
piii A[maxN];
int n;
pii a;
int dp[maxN];
int nxt[maxN];

int f(int ind) {
	if ( dp[ind] != 0 )
		return dp[ind];

	dp[ind] = 1;
	nxt[ind] = -1;
	FOR(i, ind + 1, n) {
		if ( A[i].F > A[ind].F && A[i].S.F > A[ind].S.F && f(i) + 1 > dp[ind] ) {
			dp[ind] = f(i) + 1;
			nxt[ind] = i;
		}
	}
	return dp[ind];
}

int main() {
	riii(n, a.F, a.S);
	FOR(i, 0, n) {
		rii(A[i].F, A[i].S.F);
		A[i].S.S = i;
	}
	sort(A, A + n);
	int max_ans = 0;
	int max_ans_i = -1;
	ROF(i, n - 1, -1) {
		if ( a.F < A[i].F && a.S < A[i].S.F && f(i) > max_ans) {
			max_ans = f(i);
			max_ans_i = i;
		}
	}
	printf("%d\n", max_ans);
	while ( max_ans_i != -1 ) {
		printf("%d ", A[max_ans_i].S.S + 1);
		max_ans_i = nxt[max_ans_i];
		if ( max_ans_i == -1 )
			printf("\n");
	}
	return 0;
}