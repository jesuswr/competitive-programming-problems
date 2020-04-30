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
int dp[35][305][305], cap[35], ncpc[35][25], bcew[35][25]; // indice t1 t2

int f(int ind, int t1, int t2){
	if ( ind<0 && t1 == 0 && t2 == 0 )
		return 0;
	if ( ind < 0 || t1 < 0 || t2 < 0)
		return INF;

	if ( dp[ind][t1][t2] != -INF )
		return dp[ind][t1][t2];

	int &ret = dp[ind][t1][t2];
	ret = INF;
	FOR(i,0,cap[ind]+1)
		ret = min(ret, ncpc[ind][i] + bcew[ind][cap[ind]-i] + f(ind-1, t1-i, t2 -(cap[ind]-i)) ); 
	
	return ret;
}

void construct_sol(int ind, int t1, int t2, stack<int> &st){
	if ( ind == 0 ){
		st.push(t1);
		return;
	}

	FOR(i,0,cap[ind]+1){
		if ( dp[ind-1][t1-i][t2-(cap[ind]-i)] + ncpc[ind][i] + bcew[ind][cap[ind]-i] == dp[ind][t1][t2] ){
			st.push(i);
			construct_sol(ind-1, t1-i, t2-(cap[ind]-i), st);
			return;
		}
	}
}


int main(){
	int t1, t2;
	bool first = true;
	while(scanf("%d %d", &t1, &t2), t1 != 0 || t2 != 0){
		if ( first )
			first = false;
		else
			printf("\n");
		int n;
		ri(n);
		FOR(i,0,n){
			ri(cap[i]);
			ncpc[i][0] = bcew[i][0] = 0;
			FOR(j,0,cap[i])
				ri( ncpc[i][j+1] );
			FOR(j,0,cap[i])
				ri( bcew[i][j+1] );
		}

		FOR(i,0,n)
			FOR(j,0,t1+1)
				FOR(k,0,t2+1)
					dp[i][j][k] = -INF;

		printf("%d\n",f(n-1,t1,t2) );
		stack<int> ans;
		construct_sol(n-1,t1,t2,ans);
		while(!ans.empty()){
			printf("%d",ans.top() );
			ans.pop();
			if ( ans.size()>0 )
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}