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
int r,c;
char M[100][100];
bool vis_bad[100][100];

bool dfs_bad(int row, int col);

bool dfs_bad_aux(int row,int col){
	if ( M[row][col] == 'G' )
		return false;
	
	if ( M[row][col] == '.' )
		M[row][col] = '#';
	else if ( M[row][col] == 'B' && !vis_bad[row][col] ){
		if ( !dfs_bad(row, col) )
			return false;
	}
	
	return true;
}


bool dfs_bad(int row, int col){
	vis_bad[row][col] = true;

	if ( row < r-1 ){
		if ( dfs_bad_aux(row+1, col) == false )
			return false;
	}
	if ( row > 0 ){
		if ( dfs_bad_aux(row-1, col) == false )
			return false;
	}
	if ( col < c-1 ){
		if ( dfs_bad_aux(row, col+1) == false )
			return false;
	}
	if ( col > 0 ){
		if ( dfs_bad_aux(row, col-1) == false )
			return false;
	}
	return true;
}

bool vis_good[100][100];

void dfs_good(int row, int col){
	if (vis_good[row][col])
		return;
	vis_good[row][col] = true;

	if ( row < r-1 && (M[row+1][col] != '#') ){
		dfs_good(row+1,col);
	}
	if ( row > 0 && (M[row-1][col] != '#')){
		dfs_good(row-1, col);
	}
	if ( col < c-1 && (M[row][col+1] != '#') ){
		dfs_good(row, col+1);
	}
	if ( col > 0 && (M[row][col-1] != '#') ){
		dfs_good(row, col-1);
	}
}

bool solve(){
	memset(vis_bad, false, sizeof(vis_bad));
	memset(vis_good, false, sizeof(vis_good));
	FOR(i,0,r){
		FOR(j,0,c){
			if ( M[i][j] == 'B' && !vis_bad[i][j] ){
				if ( !dfs_bad(i,j) )
					return false;
			}
		}
	}

	if ( M[r-1][c-1] == '.' )
		dfs_good(r-1,c-1);

	FOR(i,0,r){
		FOR(j,0,c){
			if ( M[i][j] == 'G' && !vis_good[i][j] )
				return false;
			if ( M[i][j] == 'B' && vis_good[i][j] )
				return false;
		}
	}
	return true;
}

int main(){
	int t;
	ri(t);
	while(t--){
		rii(r,c);
		FOR(i,0,r){
			scanf("%s", M[i]);
		}
		if ( solve() )
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}