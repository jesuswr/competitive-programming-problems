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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll h[1009];
int a[1009];
int tem[1009];

int main(){
	int n;
	ri(n);
	FOR(i,0,n)
		rl(h[i]);
	ll ans = -1;
	ll mn;
	FOR(i,0,n){
		ll cnt = 0;
		mn = h[i];
		FOR(j,i,n){
			mn = min(mn,h[j]);
			tem[j] = mn;
			cnt += mn;
		}
		mn = h[i];
		ROF(j,i-1,-1){
			mn = min(mn,h[j]);
			tem[j] = mn;
			cnt += mn;
		}

		if (cnt>ans){
			ans = cnt;
			FOR(j,0,n)
				a[j] = tem[j];
		}
	}
	FOR(i,0,n)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}