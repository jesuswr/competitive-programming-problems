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
#include <tuple>

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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
int n, m;
pair<ll, ll> I[maxN];
tuple<ll, ll, ll> D[maxN];
set<pair<ll, ll>> A;
int ANS[maxN];

int main() {
	rii(n, m);
	FOR(i, 0, n) {
		rll(I[i].F, I[i].S);
	}
	FOR(i, 0, m) {
		ll aux;
		rl(aux);
		A.insert({aux, (ll)i});
	}
	FOR(i, 0, n - 1) {
		ll mx = I[i + 1].S - I[i].F;
		ll mn = I[i + 1].F - I[i].S;
		D[i] = {mx, mn, i};
	}
	sort(D, D + n - 1);
	FOR(i, 0, n - 1) {
		ll mn = get<1>(D[i]), mx = get<0>(D[i]);
		int ind = get<2>(D[i]);
		auto it = A.lb({mn, -1});
		if ( it == A.end() ) {
			printf("No\n");
			return 0;
		}
		if ( (*it).F > mx ) {
			printf("No\n");
			return 0;
		}
		ANS[ind] = (*it).S + 1;
		A.erase(it);
	}
	printf("Yes\n");
	FOR(i,0,n-1){
		printf("%d ", ANS[i]);
	}
	printf("\n");

	return 0;
}