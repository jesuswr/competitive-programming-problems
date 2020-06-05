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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
ll A[maxN];
map<ll,ll> mp;

int main(){
	int n;
	ri(n);
	FOR(i,0,n)
		rl(A[i+1]);

	ll ans = 0;
	ll curr_sum = 0;
	mp[0] = 0;
	ll left = -1;
	FOR(i,1,n+1){
		curr_sum += A[i];
		if ( mp.find(curr_sum) != mp.end() ){
			left = max(left, mp[curr_sum]);
		}
		mp[curr_sum] = i;
		ans += (i-left-1);
	}
	printf("%lld\n", ans);
	return 0;
}