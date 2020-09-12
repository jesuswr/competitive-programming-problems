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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
vector<ll> power_two, power_five;

int main() {
	ll n;
	rl(n);
	ll two = 1, five = 1;
	while (two <= n) {
		power_two.pb(two);
		two *= 2;
	}
	while (five <= n) {
		power_five.pb(five);
		five *= 5;
	}

	set<ll> ans;
	for (auto t : power_two) {
		for (auto f : power_five) {
			if (n / t < f)
				continue;
			if (n / f < t)
				continue;
			if (n % (t * f) == 0)
				ans.insert(t * f);
		}
	}

	printf("%d\n",(int)ans.size() );
	for(auto a : ans)
		printf("%lld\n", a);


	return 0;
}