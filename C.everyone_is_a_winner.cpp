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
queue<ll> p;

int main()
{
	int n;
	ri(n);
	FOR(i,0,n){
		ll x;
		rl(x);
		ll end = x;
		ll current = 0;
		while( current != x){
			ll ans = x+1;
			ll s = 1;
			while ( s <= end ){
				ll m = ( s + end ) / 2;
				if ( x/m >current && x/m<ans){
					ans = x/m;
					s = m + 1;
				}
				else
					end = m - 1;
			}
			current = ans;
			p.push(current);
		}
		printf("%d\n", (int)p.size()+1);
		printf("0 ");
		while(!p.empty()){
			current = p.front();
			p.pop();
			printf("%lld ", current);
		}
		printf("\n");
	}
	return 0;
}