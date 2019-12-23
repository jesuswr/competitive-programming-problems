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
const int maxN = 1e7+1e6+1e5+1e4+1e3+1e2+1; // CAMBIAR ESTE
const ll MOD = 1e9+7;

// GJNM
string s;

int main()
{
	int t;
	ri(t);
	while(t--){
		int x;
		ri(x);
		cin >> s;
		ll ans = s.length();
		FOR(i,1,x+1){
			//printf("entro %lld\n",ans );
			int l = s[i-1]-'0';
			if ( l == 1 )
				continue;
			else{
				ll aux = s.length();
				l--;
				if ( aux < x ){
					while( l-- )
						FOR(j,i,aux) 
							s.pb(s[j]);
					ans = s.length();
				}
				else{
					ans += ( (ans - i + MOD)%MOD)*l;
					ans %= MOD;
				}
			}
			//printf("salio %lld\n",ans );
		}
		printf("%lld\n", ans);
	}
	return 0;
}