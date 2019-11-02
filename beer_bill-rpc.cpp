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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char buf[1011];

int main()
{
	ll ans = 0;
	while ( scanf("%s",buf)>0){
		if ( buf[0] == '|'){
			ll c = strlen(buf)*42;
			ans += c;
		}
		else{
			ll aux = 0;
			ll i=0;
			while ( buf[i] != ','){
				aux = aux*10;
				aux += (int)(buf[i]-'0');
				i++;
			}
			ll m = strlen(buf) - i-2;
			ans += m * aux;
		}
	}
	if ( ans % 10 != 0)	ans += (10 - ans%10);
	printf("%lld,-\n", ans);
	return 0;
}