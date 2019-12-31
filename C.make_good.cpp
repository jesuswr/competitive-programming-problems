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
ll arr[maxN];

int main()
{
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,n)
			rl(arr[i]);
		ll sum, xr;
		sum = xr = 0;
		FOR(i,0,n){
			sum += arr[i];
			xr = xr^arr[i];
		}
		bool odd = false;
		if ( sum & 1 )
			odd = true;

		if ( sum/2 == xr && !odd){
			printf("0\n");
			printf("\n");
		}
		else if (!odd){
			printf("2\n");
			printf("%lld %lld\n",xr,sum+xr );
		}
		else{
			sum += 1;
			xr = xr^1;
			if ( sum/2 == xr){
				printf("1\n");
				printf("1\n");
			}
			else{
				printf("3\n");
				printf("1 %lld %lld\n",xr,sum+xr );
			}
		}
	}
	return 0;
}