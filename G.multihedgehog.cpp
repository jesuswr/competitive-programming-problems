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
const int maxN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int v, k;
int D[maxN];
vi G[maxN];
queue<int> L;

int main() {
	rii(v, k);
	FOR(i, 0, v - 1) {
		int a, b;
		rii(a, b);
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);
		D[a]++, D[b]++;
	}
	FOR(i,0,v){
		if ( D[i] == 1 )
			L.push(i);
	}

	FOR(i,0,k){
		if ( L.size() == 0 ){
			printf("No\n");
			return 0;
		}

		map<int,int> mp;
		while( !L.empty() ){
			int x = L.front(); L.pop();
			D[x] = 0;
			for(auto y : G[x]){
				if ( D[y] > 0 ){
					D[y]--;
					mp[y]++;
				}
			}
		}

		for(auto p : mp){
			if ( p.S < 3 ){
				printf("No\n");
				return 0;
			}
			L.push(p.F);
		}
	}

	if ( L.size() == 1 && D[L.front()] == 0 )
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}