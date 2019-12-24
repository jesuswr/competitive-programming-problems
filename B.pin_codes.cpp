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
char w[11][8];
bool f[11];

int main()
{
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,10) f[i] = false;
		int cnt = 0;
		FOR(i,0,n){
			scanf("%s",w[i]);
			f[w[i][0]-'0'] = true;
		}
		FOR(i,0,n){
			FOR(j,0,n){
				if ( i == j )
					continue;
				if ( strcmp(w[i],w[j]) == 0 ){
					FOR(k,0,10){
						if ( !f[k] ) {
							w[i][0] = (int)('0'+k);
							f[k] = true;
							cnt++;
							j = 10;
							break;
						}
					}
				}
			}
		}
		printf("%d\n",cnt );
		FOR(i,0,n) printf("%s\n", w[i]);
	}
	return 0;
}