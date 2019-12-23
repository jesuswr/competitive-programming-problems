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
char a[5005], b[5005], c[5005];

int main()
{
	int t;
	ri(t);
	while( t-- ){
		scanf("%s %s",a,b);
		if ( strcmp(a,b) < 0 ){
			printf("%s\n", a);
		}
		else{
			int la, lb;
			la = strlen(a);
			lb = strlen(b);
			strcpy(c,a);
			sort(c,c+la);
			FOR(i,0,la){
				if ( a[i] == c[i] ) continue;
				int ind = -1;
				FOR(j,0,la){
					if ( a[j] == c[i] ){
						ind = max( ind , j );
					}
				}
				swap( a[i] , a[ind] );
				break;
			}
			if ( strcmp(a,b)<0) printf("%s\n",a );
			else printf("---\n");
			
		}
	}
	return 0;
}