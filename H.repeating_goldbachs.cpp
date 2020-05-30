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
const int maxN = 1e6+10; // CAMBIAR ESTE

// GJNM
bool IS_NOT_PRIME[maxN];
set<int> PRIMES;

int main(){
	IS_NOT_PRIME[0] = IS_NOT_PRIME[1] = false;
	int x;
	ri(x);
	FOR(i,2,x+1){
		if ( IS_NOT_PRIME[i] )
			continue;
		int aux = 2;
		while( aux*i <= x ){
			IS_NOT_PRIME[i*aux] = true;
			aux++;
		}
		PRIMES.insert(i);
	}

	int steps = 0;
	while( x >= 4 ){
		steps++;
		for(int p : PRIMES){
			if ( !IS_NOT_PRIME[x-p] ){
				x = x-p - p;
				break;
			}
		}
	}
	printf("%d\n", steps);
	return 0;
}