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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
ll arr[maxN];
ll pre[maxN];

int main()
{
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		ll s = 0;
		FOR(i,0,n){
			rl(arr[i]);
			s += arr[i];
			pre[i] = arr[i];
		}
		FOR(i,1,n)
			pre[i] += pre[i-1];
		ll mn = 0;
		ll mn2 = pre[0];
		ll ans = -1;
		FOR(i,0,n){
			if (i==n-1){
				ans = max( ans , pre[i]-mn2 );
			}
			else{
				ans = max( ans , pre[i] - mn );
				mn = min( mn , pre[i] );
				mn2 = min( mn2 , pre[i] );
			}
		}
		//printf("%lld %lld\n", s, ans);
		if ( ans >= s )
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}