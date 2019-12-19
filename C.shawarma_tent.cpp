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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main()
{
	ll n, sx, sy;
	ll x, y;
	rl(n);
	rll(sx,sy);
	ll ponlaArriba, ponlaAbajo, ponlaDer, ponlaIzq;
	ponlaIzq = ponlaDer = ponlaAbajo = ponlaArriba = 0;
	FOR(i,0,n){
		rll(x,y);
		if ( x > sx ) ponlaDer++;
		if ( x < sx ) ponlaIzq++;
		if ( y > sy ) ponlaArriba++;
		if ( y < sy ) ponlaAbajo++;
	}
	if ( sx == 0 ) ponlaIzq = -1;
	if ( sx == 1e9 ) ponlaDer = -1;
	if ( sy == 0 ) ponlaAbajo = -1;
	if ( sy == 1e9 ) ponlaArriba = -1;
	if ( ponlaIzq >= ponlaDer && ponlaIzq >= ponlaArriba && ponlaIzq >= ponlaAbajo ){
		printf("%lld\n", ponlaIzq);
		printf("%lld %lld\n", sx-1 , sy);
	}
	else if ( ponlaDer >= ponlaIzq && ponlaDer >= ponlaArriba && ponlaDer >= ponlaAbajo ){
		printf("%lld\n", ponlaDer);
		printf("%lld %lld\n", sx+1 , sy);
	}
	else if ( ponlaArriba >= ponlaIzq && ponlaArriba >= ponlaDer && ponlaArriba >= ponlaAbajo ){
		printf("%lld\n", ponlaArriba);
		printf("%lld %lld\n", sx , sy+1);
	}
	else if ( ponlaAbajo >= ponlaIzq && ponlaAbajo >= ponlaDer && ponlaArriba <= ponlaAbajo ){
		printf("%lld\n", ponlaAbajo);
		printf("%lld %lld\n", sx , sy-1);
	}
	return 0;
}