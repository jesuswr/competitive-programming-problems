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
char M[1005][1005];

int main(){
	int t;
	ri(t);
	while(t--){
		int n, m;
		ll x,y;
		rii(n,m), rll(x,y);
		y = min(2*x, y);
		FOR(i,0,n){
			scanf("%s", M[i]);
		}
		ll ans = 0;
		FOR(i,0,n){
			ll cnt = 0;
			FOR(j,0,m){
				if ( M[i][j] == '*' ){
					ans += (cnt/2)*y + (cnt%2)*x;
					cnt = 0;
				}
				else{
					cnt++;
				}
			}

			if ( cnt > 0 ){
				ans += (cnt/2)*y + (cnt%2)*x;
			}

		}
		printf("%lld\n", ans);
	}
	return 0;
}