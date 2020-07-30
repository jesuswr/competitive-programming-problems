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

typedef unsigned long long ll;
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
const ll LLINF = 2e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

ll solve(vector<ll> A, vector<ll> B) { // muevo todos los de A a B
	int na = A.size(), nb = B.size();

	ll a_sum = 0;
	for (ll a : A)
		a_sum += a;

	ll ans = LLINF;
	ll prev = 0;
	FOR(i, 0, nb) {
		ans = min(ans, prev + a_sum * (nb - i));
		prev += B[i];
	}

	return ans;

}

int main() {
	int na, nb;
	rii(na, nb);
	vector<ll> A(na), B(nb);
	FOR(i, 0, na) {
		rl(A[i]);
	}
	FOR(i, 0, nb) {
		rl(B[i]);
	}
	sort(A.begin(), A.end()), sort(B.begin(), B.end());

	ll ans = min(solve(A, B), solve(B, A));
	printf("%lld\n", ans);
	return 0;
}