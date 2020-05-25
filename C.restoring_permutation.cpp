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
int B[maxN];
set<int> vis;

int main(){
	int t;
	ri(t);
	while(t--){
		vis.clear();
		int n;
		ri(n);
		FOR(i,0,n){
			ri(B[2*i]);
			vis.insert(B[2*i]);
		}
		bool ans = true;
		FOR(i,0,n){
			int need = B[2*i]+1;
			while( vis.count(need) > 0 )
				need++;
			if ( need > 2*n ){
				ans = false;
				break;
			}
			B[2*i+1] = need;
			vis.insert(need);
		}
		if ( !ans )
			printf("-1");
		else
			FOR(i,0,2*n)
				printf("%d ", B[i]);

		printf("\n");

	}
	return 0;
}