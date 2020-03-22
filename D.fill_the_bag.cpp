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
int bit_cnt[65];


int main(){
	int t;
	ri(t);
	while(t--){
		ll n, m;
		rll(n,m);
		FOR(j,0,64)
			bit_cnt[j] = 0;
		ll cnt = 0;
		FOR(i,0,m){
			ll aux;
			rl(aux);
			cnt += aux;
			FOR(j,0,64){
				if ( aux & (1<<j) )
					bit_cnt[j]++;
			}
		}
		if ( cnt < n ){
			printf("-1\n");
			continue;
		}
		ll i = 0;
		ll divs = 0;
		ll one = 1;
		while(i<64 && n>0){
			//FOR(i,0,64)
			//	printf("%d", bit_cnt[i]);
			//printf("\n");
			if ( n & (one<<i) ){
				//printf("chao\n");
				if ( bit_cnt[i] ){
					n -= (one<<i);
					bit_cnt[i]--;
				}
				else{
					ll j = i+1;
					bit_cnt[i] = 2;
					divs++;
					while( bit_cnt[j] == 0 && j<64){
						bit_cnt[j] = 1;
						j++;
						divs++;
					}
					bit_cnt[j]--;
				}
			}
			else{
				//printf("hhola\n");
				bit_cnt[i+1] += bit_cnt[i]/2;
				i++;
			}
		}
		printf("%lld\n", divs);
	}
	return 0;
}