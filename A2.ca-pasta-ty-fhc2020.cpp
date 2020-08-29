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
const int MAXN = 1000010; // CAMBIAR ESTE

// GJNM
ll n, k;
ll As, Bs, Cs, Ax, Bx, Cx, Ay, By, Cy, Ds, Dx, Dy;
ll S[MAXN], X[MAXN], Y[MAXN];

void solve() {
	rll(n, k);
	FOR(i, 0, k) {
		rl(S[i]);
	}
	rll(As, Bs), rll(Cs, Ds);
	FOR(i, 0, k) {
		rl(X[i]);
	}
	rll(Ax, Bx), rll(Cx, Dx);
	FOR(i, 0, k) {
		rl(Y[i]);
	}
	rll(Ay, By), rll(Cy, Dy);
	FOR(i, k, n) {
		S[i] = (As * S[i - 2] + Bs * S[i - 1] + Cs) % Ds;
		X[i] = (Ax * X[i - 2] + Bx * X[i - 1] + Cx) % Dx;
		Y[i] = (Ay * Y[i - 2] + By * Y[i - 1] + Cy) % Dy;
	}

	ll tot_sum = 0;
	ll tot_x = 0;
	ll tot_x_y = 0;
	FOR(i, 0, n) {
		tot_sum += S[i];
		tot_x += X[i];
		tot_x_y += X[i] + Y[i];
	}
	if ( tot_sum < tot_x || tot_sum > tot_x_y ) {
		printf("-1\n");
		return;
	}

	ll over = 0, under = 0;
	FOR(i, 0, n) {
		if (S[i] > X[i] + Y[i])
			over += (S[i] - X[i] - Y[i]);
		else if (S[i] < X[i])
			under += X[i] - S[i];
	}
	printf("%lld\n", max(under, over));

	//ll ans = 0;
	//if (over >= under) {
	//	ans += under;
	//	FOR(i, 0, n) {
	//		if (S[i] > X[i] + Y[i]) {
	//			ll moves = min(S[i] - X[i] - Y[i], under);
	//			S[i] -= moves;
	//			under -= moves;
	//		}
	//		else if (S[i] < X[i]) {
	//			S[i] = X[i];
	//		}
	//	}
	//}
	//else {
	//
	//}

}

int main() {
	int t;
	ri(t);
	FOR(i, 1, t + 1) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}