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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main(){
	int t;
	ri(t);
	while(t--){
		ll x,y,p,q;
		rll(x,y), rll(p,q);
		ll op = p, oq = q;
		if ( (p == 0 && x != 0) || (p == q && x != y) ){
			printf("-1\n");
			continue;
		}
		if ( p == 0 && x == 0 ){
			printf("0\n");
			continue;
		}

		if ( x > op ){
			ll aux = (x+op-1)/op;
			p = max(op*aux,p);
			q = max(oq*aux,q);
		}
		if ( y > oq ){
			ll aux = (y+oq-1)/oq;
			p = max(op*aux,p);
			q = max(oq*aux,q);
		}
		if ( p-x > q-y ){
			ll d = p-x-q+y;
			ll aux = (d+oq-op-1)/(oq-op);
			p += aux*op;
			q += aux*oq;
		}		
		printf("%lld\n", q-y);
	}
	return 0;
}