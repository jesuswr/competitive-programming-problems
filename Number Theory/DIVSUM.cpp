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
const int MAXN = 500010; // CAMBIAR ESTE

// GJNM
vi primes;
bool sieve[MAXN];

void pre_calc() {
	FOR(i, 2, MAXN) {
		if (sieve[i])
			continue;
		primes.pb(i);
		int j = i + i;
		while (j < MAXN) {
			sieve[j] = true;
			j += i;
		}
	}
}

int main() {
	pre_calc();
	int t;
	ri(t);
	while (t--) {
		int n; ri(n);
		int aux_n = n;
		vii prod;
		int curr = 0;
		while (n > 1) {
			int cnt = 0;
			while (n % primes[curr] == 0) {
				cnt++;
				n = n / primes[curr];
			}
			if (cnt > 0)
				prod.pb({primes[curr], cnt});
			curr++;
		}
		int ans = 1;
		for (auto p : prod) {
			ans *= (pow(p.F, p.S + 1) - 1) / (p.F - 1);
		}
		printf("%d\n", ans - aux_n);
	}

	return 0;
}