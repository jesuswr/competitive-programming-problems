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
const int maxN = 1e5+20; // CAMBIAR ESTE

// GJNM
int n, x;
int A[maxN];
set<int> IND[maxN];
set<int> all;

int main(){
	int t;
	ri(t);
	while(t--){
		rii(n, x);
		FOR(i,0,n){
			IND[i+1].clear();
			ri(A[i+1]);
		}
		IND[0].clear();
		all.clear();

		IND[0].insert(0);
		all.insert(0);
		FOR(i,1,n+1){
			A[i] = (A[i] + A[i-1])%x;
			IND[A[i]].insert(i);
			all.insert(i);
		}
		int ans = -1;


		FOR(i,0,x){
			if ( IND[i].size() == 0 )
				continue;
			int mx = -1;
			for(auto x : IND[i] ){
				mx = max(mx, x);
				all.erase(x);
			}

			if ( all.size() != 0 ){
				ans = max(ans, mx - *(all.lower_bound(-1)) );
			}

			for(auto x : IND[i] ){
				all.insert(x);
			}
		}

		FOR(i,0,x)
			IND[i].clear();
		all.clear();

		printf("%d\n", ans);
	}
	return 0;
}