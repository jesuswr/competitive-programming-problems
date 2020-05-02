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
const int maxN = 1010; // CAMBIAR ESTE

// GJNM
char moves[maxN];

int main(){
	int t;
	ri(t);
	FOR(w,1,t+1){
		int x,y;
		rii(x,y);
		scanf("%s", moves);
		int n = strlen(moves);

		printf("Case #%d: ",w );
		if ( x==0 && y==0 )
			printf("0\n");
		else{
			bool ans = false;
			FOR(i,0,n){
				if ( moves[i] == 'S' )
					y--;
				else if ( moves[i] == 'N' )
					y++;
				else if ( moves[i] == 'E' )
					x++;
				else if ( moves[i] == 'W' )
					x--;

				if ( abs(x) + abs(y) <= i+1 ){
					printf("%d\n", i+1);
					ans = true;
					break;
				}
			}
			if ( !ans )
				printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}