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
int n,m;
char A[20][20];
bool vis[1<<10][11];
bool dp[1<<10][11];

int get_dif(int word, int ind){
	int btmsk = 0;
	FOR(i,0,n){
		if ( A[i][ind] != A[word][ind] )
			btmsk |= (1<<i);
	}
	return btmsk;
}

bool f(int btmsk, int ind){
	if ( ind == m )
		return dp[btmsk][ind] = true;

	if ( vis[btmsk][ind] )
		return dp[btmsk][ind];

	vis[btmsk][ind] = true;
	bool &ret = dp[btmsk][ind];
	ret = false;

	FOR(i,0,n){
		int aux_btmsk = get_dif(i,ind);
		if ( aux_btmsk & btmsk )
			continue;
		ret |= f(btmsk | aux_btmsk, ind+1);

	}
	return ret;
}

void construct_sol(int btmsk, int ind){
	if ( ind == m )
		return;

	FOR(i,0,n){
		int aux_btmsk = get_dif(i,ind);
		if ( aux_btmsk & btmsk )
			continue;
		if (f(btmsk | aux_btmsk, ind+1)){
			printf("%c", A[i][ind]);
			construct_sol(btmsk | aux_btmsk, ind+1);
			return;
		}

	}
}



int main(){
	int t;
	ri(t);
	while(t--){
		rii(n,m);
		FOR(i,0,n)
			scanf("%s", A[i]);

		FOR(i,0,1<<10)
			FOR(j,0,11)
				dp[i][j] = vis[i][j] = false;

		if ( !f(0,0) )
			printf("-1\n");
		else{
			construct_sol(0,0);
			printf("\n");
		}

	}

	return 0;
}