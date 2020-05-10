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
const int maxN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int n, cycle_size;
ll k;
ll A[maxN];
bool vis[maxN], cyc[maxN];
vi cycle, ord;

void dfs(int x){
	if ( cyc[x] )
		return;

	if ( vis[x] == false ){
		vis[x] = true;
		ord.pb(x);
	}
	else{
		cyc[x] = true;
		cycle.pb(x);
	}

	dfs(A[x]);
}

int main(){
	ri(n);
	rl(k);
	FOR(i,0,n){
		rl(A[i]);
		A[i]--;
	}
	dfs(0);
	int O = ord.size()-1;
	int C = cycle.size();
	//for(int x : ord)
	//	printf("%d ",x+1 );
	//printf("\n");
	//for(int x : cycle)
	//	printf("%d ",x+1 );
	//printf("\n");
	if ( k <= O ){
		printf("%d\n", ord[k]+1);
	}
	else{
		if ( O == C-1 ){
			printf("%d\n", cycle[k%C]+1);
		}
		else{
			k -= (O-C);
			k--;
			//printf("%lld %d %d\n",k,O,C );
			printf("%d\n",cycle[k%C]+1 );
		}
	}
	return 0;
}