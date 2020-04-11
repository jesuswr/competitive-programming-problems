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
int mat[501][501];


int F(int r, int c){
	if ( mat[r][c] != 0 )
		return mat[r][c];
	if ( c == 1 || r == c )
		return mat[r][c] = 1;
	else
		return mat[r][c] = F(r-1,c-1) + F(r-1,c);

}

int main(){
	int t;
	mat[1][1] = 1;
	FOR(i,1,501)
		F(500,i);
	ri(t);
	FOR(k,1,t+1){
		int n;
		ri(n);
		
		printf("Case #%d:\n",k );
		int i = 2, j = 1;
		printf("1 1\n");
		if ( n >= 999 ){
			printf("2 1\n");
			printf("3 2\n");
			printf("4 2\n");
			printf("5 2\n");
			i = 5;
			j = 1;
			n -= 10;
		}
		n--;
		while( n != 0 ){
			if ( n == mat[i][j+1]){
				printf("%d %d\n",i, j+1 );
				n = 0;
			}
			else if ( i > 2 &&  mat[i-1][j+1] == n ){
				printf("%d %d\n",i-1, j+1 );
				n = 0;
			}
			else{
				printf("%d %d\n",i++,j );
				n--;
			}
		}
		
	}
	return 0;
}