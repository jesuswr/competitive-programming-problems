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
ll k;


ll getans(){
	ll c = 0;
	ll ans = 0;
	ll mcd = 0;
	for( ll i = 2; i*i <= k ; i++){
		if ( k%i == 0 ){
			c++;
			if ( c == 1 ){
				mcd = i;
			}
			else{
				mcd = __gcd(mcd,i);
			}
		}
		if ( i != k/i && k%i == 0){
			c++;
			mcd = __gcd(mcd,k/i);

		}
	}
	if ( c == 0 ) return k;
	else return mcd;
	
}

int main()
{
	rl(k);
	ll ans = getans();
	printf("%lld\n", ans);
	return 0;
}