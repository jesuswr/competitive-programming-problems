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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 3e5+5; // CAMBIAR ESTE

// GJNM
ll f[maxN],r[maxN];
bool m[maxN];

int main()
{
	int n;
	ri(n);
	ll b = 0;
	ll s = 0;
	FOR(i,0,n){
		rl(r[i]);
		if (i&1){
			b += (r[i]+1)/2;
		}
		else{
			b += (r[i])/2;

		}
		s += r[i];
	}
	printf("%lld\n", min(b,s-b));

	return 0;
}