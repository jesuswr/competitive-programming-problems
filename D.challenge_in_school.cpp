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
ll n,k;
char A[maxN];
vi moves[maxN];

int main(){
	rll(n,k);
	scanf("%s", A);

	bool act = true;
	ll curr = 0;
	ll moves_cnt = 0;
	while(act){
		if ( moves_cnt > n*n ){
			printf("-1\n");
			return 0;
		}
		act = false;
		FOR(i,0,n-1){
			if ( A[i] == 'R' && A[i+1] == 'L' ){
				A[i] = 'L', A[i+1] = 'R';
				act = true;
				moves[curr].pb(i+1);
				i++;
				moves_cnt++;
			}
		}
		if ( act )
			curr++;
	}
	if ( k > moves_cnt || k < curr ){
		printf("-1\n");
		return 0;
	}
	ll ext_moves = k - curr;
	FOR(i,0,curr){
		int j = 0;
		while( ext_moves > 0 && j < moves[i].size()-1 ){
			ext_moves--;
			printf("%d %d\n",1, moves[i][j++] );
		}

		if ( j < moves[i].size() ){
			printf("%d ",(int)moves[i].size() - j );
			for(; j < moves[i].size(); j++){
				printf("%d ", moves[i][j]);
			}
			printf("\n");
		}
	}
	

	return 0;
}