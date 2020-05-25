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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int mat[51][51];

int main(){
	int t;
	ri(t);
	while(t--){
		int n,m,a,b;
		rii(n,m), rii(a,b);
		if ( n * a != m * b ){
			printf("NO\n");
			continue;
		}

		if ( n == 1 || m == 1 ){
			printf("YES\n");
			FOR(i,0,n){
				FOR(j,0,m){
					printf("%d", a>0);
				}
				printf("\n");
			}
			continue;
		}

		FOR(i,0,n) 
			FOR(j,0,m)
				mat[i][j] = 0;

		int d = a;
		

		int r = 0;
		int col = 0;
		while( r < n ){
			FOR(i,0,a)
				mat[r][ (i+col)%m ] = 1;
			col += d;
			r++;
		}
		printf("YES\n");

		FOR(i,0,n){
			FOR(j,0,m){
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}