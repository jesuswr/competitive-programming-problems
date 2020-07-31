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
const int maxN = 5e5; // CAMBIAR ESTE

// GJNM
ll A[maxN];
ll B[maxN];

int main() {
	ll n, I;
	rll(n, I);

	ll ind_bits = (I * 8) / n;
	ind_bits = min(ind_bits, 30ll);
	ll range_sz = (1 << ind_bits);

	ll mx = -1;
	ll mn = INF;
	FOR(i, 0, n) {
		rl(A[i]);
	}
	sort(A, A + n);
	int i = 0, i2 = 0;
	while ( i < n ) {
		int aux_i = i;
		while (A[aux_i] == A[i]) {
			B[i2]++;
			aux_i++;
		}
		i2++;
		i = aux_i;
	}
	int m = i2;
	FOR(i, 1, m) {
		B[i] += B[i - 1];
	}
	ll ans = INF;
	FOR(i, 0, m) {
		int left = i, right = min(i + range_sz - 1, (ll)m - 1);
		ans = min(ans, n - (B[right] - ( left > 0 ? B[left - 1] : 0)));
	}
	printf("%lld\n", ans);

	return 0;
}