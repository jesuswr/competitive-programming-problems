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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
ll n, m;
ll a[2*maxN];
ll s2[2*maxN];

int main()
{
	rll(n,m);
	FOR(i,0,n) rl(a[i]);
	sort(a,a+n);
	ll sum = 0;
	ll sum2 = 0;
	for( int i = 0 ; i < n; i += m){
		for( int j = i ; j < min(i + m,n) ; j ++){
			sum += s2[j%m];
			s2[j%m] += a[j];
			sum += a[j];
			printf("%lld ", sum);
		}
	}
	printf("\n");
	return 0;
}
