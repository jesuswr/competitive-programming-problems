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
const int maxN = 1e6; // CAMBIAR ESTE

// GJNM
int n, m;
int A[maxN], B[maxN];
int X[maxN], Y[maxN], K[maxN];
int Q[maxN];
int ANS[maxN];
bool TYPE[maxN];

set<pii> pending;

int main() {
	rii(n, m);
	FOR(i, 0, n)
		ri(A[i]);
	FOR(i, 0, n)
		ri(B[i]);

	FOR(i, 0, m) {
		int aux;
		ri(aux);
		if ( aux == 2 ) {
			TYPE[i] = true;
			ri(Q[i]);
		}
		else {
			riii(X[i], Y[i], K[i]);
		}
	}

	ROF(i, m - 1, -1) {
		if ( TYPE[i] ) {
			pending.insert({Q[i], i});
		}
		else {
			vector<pii> aux;
			for(auto it = pending.lower_bound({Y[i], -1}); it != pending.lower_bound({Y[i]+K[i],-1}) && it != pending.end(); it++  ){
				//printf("%d: %d %d\n", i+1, (*it).F, (*it).S);
				aux.pb(*it);
			}
			for(auto p : aux){
				pending.erase(p);
				ANS[p.S] = A[X[i] + (p.F - Y[i])-1];
				//printf("%d: en %d pongo lo de %d\n",i+1, p.F,  X[i] + (p.F - Y[i]) );
			}

		}
	}
	for(auto p : pending){
		ANS[p.S] = B[p.F-1];
	}
	FOR(i,0,m){
		if ( TYPE[i]  )
			printf("%d\n", ANS[i]);
	}
	return 0;
}