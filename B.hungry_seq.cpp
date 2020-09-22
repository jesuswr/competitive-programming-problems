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
const int MAXN = 1e6+3e5; // CAMBIAR ESTE

// GJNM
bool is_not_prime[MAXN];
vi primes;

int main() {
	FOR(i, 2, MAXN) {
		if (is_not_prime[i])
			continue;
		int j = i+i;
		while(j < MAXN){
			is_not_prime[j] = true;
			j += i;
		}
		primes.pb(i);
	}
	int n; ri(n);
	FOR(i,0,n)
		printf("%d ", primes[i]);
	printf("\n");
	return 0;
}