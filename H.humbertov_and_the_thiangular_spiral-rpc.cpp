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
const int MAXN = 6e5; // CAMBIAR ESTE

// GJNM
pair<ll, ll> q[MAXN];
pair<ll, ll> ans[MAXN];

int main() {
	int t;
	ri(t);
	FOR(i, 0, t) {
		rl(q[i].F);
		q[i].S = i;
	}
	sort(q, q + t);
	int curr = 0;
	while ( curr < t && q[curr].F == 1 ) {
		ans[q[curr].S] = {0, 0};
		curr++;
	}
	while ( curr < t && q[curr].F == 2 ) {
		ans[q[curr].S] = { -1, 0};
		curr++;
	}
	while ( curr < t && q[curr].F == 3 ) {
		ans[q[curr].S] = {0, 1};
		curr++;
	}

	int move = 0; // 0 es der, 1 es izq, 2 es arriba
	ll act = 3;
	ll mx_u = 1, mx_r = 0, mx_l = -1, mx_d = 0;
	while (curr < t) {
		if ( move == 0 ) {
			ll curr_moves = mx_r + 2;
			while ( curr < t && q[curr].F <= act + curr_moves) {
				ans[q[curr].S] = {(q[curr].F - act) , mx_u - (q[curr].F - act)};
				curr++;
			}
			mx_d = mx_d - 1;
			mx_r = mx_r + 2;
			act += curr_moves;
		}
		else if ( move == 1 ) {
			ll curr_moves = (mx_r - mx_l) + 2;
			while ( curr < t && q[curr].F <= act + curr_moves ) {
				ans[q[curr].S] = {mx_r - (q[curr].F - act), mx_d};
				curr++;
			}
			mx_l = mx_l - 2;
			act += curr_moves;

		}
		else {
			ll curr_moves = mx_u + 1 - mx_d;
			while ( curr < t && q[curr].F <= act + curr_moves) {
				ans[q[curr].S] = {mx_l + (q[curr].F - act),  mx_d + (q[curr].F - act)};
				curr++;
			}
			mx_u = mx_u + 1;
			act += curr_moves;
			
		}

		move = (move + 1) % 3;
	}
	FOR(i, 0, t) {
		printf("%lld %lld\n", ans[i].F, ans[i].S);
	}

	return 0;
}