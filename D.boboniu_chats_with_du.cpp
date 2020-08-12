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
#define rlll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll n, d, m;
priority_queue<ll> low, hi;
stack<ll> have_low;

int main() {
	rlll(n, d, m);
	FOR(i, 0, n) {
		ll aux; rl(aux);
		if ( aux > m )
			hi.push(aux);
		else
			low.push(aux);
	}
	ll have_days = 0;
	ll ans = 0;
	ll cnt = 0;
	while ( have_days < n && !low.empty()) {
		have_low.push(low.top());
		cnt += low.top(); low.pop();
		have_days++;
	}
	while ( have_days < n && !hi.empty()) {
		cnt += hi.top(); hi.pop();
		have_days += d + 1;
	}

	ans = max(ans, cnt);

	while ( !have_low.empty() && !hi.empty() ) {
		while (!have_low.empty() && have_days >= n) {
			cnt -= have_low.top(); have_low.pop();
			have_days--;
		}
		while ( have_days < n && !hi.empty()) {
			cnt += hi.top(); hi.pop();
			have_days += d + 1;
		}
		ans = max(ans, cnt);
	}
	printf("%lld\n", ans);

	return 0;
}