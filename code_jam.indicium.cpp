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
int n, k;
int mat[50][50];
int ans[50][50];

void check_mat(){
	int cnt = 0;
	FOR(i,0,n){
		cnt += mat[i][i];
	}

	if ( cnt != k || ans[0][0] != -1 )
		return;

	FOR(i,0,n){
		FOR(j,0,n){
			ans[i][j] = mat[i][j];
		}
	}
}

void something(int r, int c){
	if ( r == n ){
		check_mat();
		return;
	}

	FOR(i,1,n+1){
		bool valid = true;
		FOR(j,0,r){
			if ( mat[j][c] == i )
				valid = false;
		}
		FOR(j,0,c){
			if ( mat[r][j] == i )
				valid = false;
		}
		
		if ( !valid )
			continue;

		mat[r][c] = i;

		if ( c == n-1 )
			something(r+1, 0);
		else
			something(r, c+1);

	}
}

int main(){
	int t, t2;
	t = 1;
	ri(t2);
	while ( t <= t2 ){
		rii(n, k);
		ans[0][0] = -1;
		something(0,0);

		printf("Case #%d: ", t);
		if ( ans[0][0] == -1 ){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("POSSIBLE\n");
			FOR(i,0,n){
				FOR(j,0,n){
					printf("%d ",ans[i][j] );
				}
				printf("\n");
			}
		}
		t++;
	}
	return 0;
}