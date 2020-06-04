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
int n;
int A[maxN];
set<int> pos_ans, original;

bool valid(int x){
	set<int> nw;
	FOR(i,0,n){
		nw.insert(A[i] ^ x);
	}
	for(auto x : nw){
		if ( original.count(x) > 0 )
			continue;
		return false; 
	}
	return true;
}

int main(){
	int t;
	ri(t);
	while(t--){
		ri(n);
		FOR(i,0,n){
			ri(A[i]);
			original.insert(A[i]);
		}

		FOR(i,1,n){
			if ( (A[i] ^ A[0]) > 0)
				pos_ans.insert( A[i] ^ A[0] );
		}

		int ans = INF;

		for(auto x : pos_ans){
			if ( valid(x) )
				ans = min(ans, x);
		}
		
		if ( ans == INF )
			printf("-1\n");
		else
			printf("%d\n", ans);

		pos_ans.clear();
		original.clear();
	}
	return 0;
}