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
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
pii sumL[maxN];
pii sumR[maxN];
int arr[2*maxN];
map<int,int> mp;

int main()
{
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,2*n) ri(arr[i]);
		FOR(i,0,n){
			if ( arr[i] == 1 ){
				sumL[i].f = 1;
				sumL[i].s = 0;
			}
			else if ( arr[i] == 2 ){
				sumL[i].f = 0;
				sumL[i].s = 1;
			}
			if ( arr[2*n-1-i] == 1 ){
				sumR[i].f = 1;
				sumR[i].s = 0;
			}
			else if ( arr[2*n-1-i] == 2 ){
				sumR[i].f = 0;
				sumR[i].s = 1;
			}
		}
		FOR(i,1,n){
			sumL[i].f += sumL[i-1].f;
			sumL[i].s += sumL[i-1].s;
			sumR[i].f += sumR[i-1].f;
			sumR[i].s += sumR[i-1].s;
		}
		FOR(i,0,n){
			if ( mp.find(sumR[i].f-sumR[i].s) == mp.end()){
				mp[sumR[i].f-sumR[i].s] = i;
			}
			else{
				mp[sumR[i].f-sumR[i].s] = max( mp[sumR[i].f-sumR[i].s] , i );
			}
		}
		int ans = 2*n;
		if ( mp.find(0) != mp.end()){
			ans = n + n- mp[0] -1;
		}
		FOR(i,0,n){
			if ( mp.find(sumL[i].s-sumL[i].f) != mp.end()){
				ans = min( ans , n-i-1+n-mp[(sumL[i].s-sumL[i].f)]-1);
			}
			else if ( sumL[i].s == sumL[i].f ){
				ans = min( ans , n + n-1-i );
			}
		}
		printf("%d\n", ans);
		mp.clear();

	}
	return 0;
}