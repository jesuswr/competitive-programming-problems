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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
int a[maxN], b[maxN];

int main()
{
	int t;
	ri(t);
	while(t--){
		int n;
		ri(n);
		FOR(i,0,n) ri(a[i]);
		FOR(i,0,n) ri(b[i]);
		int i = 0;
		int c = 0;
		int d = 0;
		bool ans = true;
		while( i < n ){
			if ( a[i] - b[i] == 0 ){
				i++;
			}
			else{
				if ( a[i] > b[i] ) {
					ans = false;
					break;
				}
				else{
					d = b[i] - a[i];
					c++;
					while ( i < n && b[i] - a[i] == d){
						i++;
					}
				}
			}
		}
		if ( c > 1 || !ans) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}