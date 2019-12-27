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
ll a[maxN+10];

int main()
{
	int t;
	ri(t);
	while(t--){
		ll n,s;
		rll(n,s);
		a[n] = LLINF;
		FOR(i,0,n)
			rl(a[i]);
		int i = 0;
		ll cnt = 0;
		while ( i < n && cnt +a[i] <= s ){
			cnt += a[i];
			i++;
		}
		if ( i == n ){
			printf("0\n");
		}
		else{
			ll mx = 0;
			int ind = 0;
			FOR(j,0,i+1){
				if ( mx < a[j] ){
					ind = j;
					mx = a[j];
				}
			}
			cnt -= a[ind];

			if ( cnt + a[i] + a[i+1] <= s ){
				printf("%d\n",ind+1 );
			}
			else
				printf("0\n");
		}
	}
	return 0;
}