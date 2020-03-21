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
char mat[105][105];
bool vis[105][105];

int main(){
	int r,c;
	rii(r,c);
	priority_queue< pair< int , pair< int , pair< int , int > > > > pq;
	int ans = INF;
	FOR(i,0,r){
		scanf("%s",mat[i]);
	}

	if ( mat[0][0] == '#' )
		pq.push({-1,{-1,{0,0}}});
	else
		pq.push({0,{0,{0,0}}});

	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		if ( p.s.s.f == r-1 && p.s.s.s == c-1 ){
			ans = -p.f;
			break;
		}
		int row = p.s.s.f;
		int col = p.s.s.s;

		if ( p.s.f == 0 ){ // white
			if ( row < r-1 && mat[row+1][col] == '.' && !vis[row+1][col])
				pq.push({ p.f , { 0 , { row+1 , col } } } );
			if ( col < c-1 && mat[row][col+1] == '.' && !vis[row][col+1])
				pq.push({ p.f , { 0 , { row , col+1 } } } );
			if ( row < r-1 && mat[row+1][col] == '#' && !vis[row+1][col])
				pq.push({ p.f-1 , { -1 , { row+1 , col } } } );
			if ( col < c-1 && mat[row][col+1] == '#' && !vis[row][col+1])
				pq.push({ p.f-1 , { -1 , { row , col+1 } } } );

		}
		else{ // black
			if ( row < r-1 && mat[row+1][col] == '.' && !vis[row+1][col])
				pq.push({ p.f , { 0 , { row+1 , col } } } );
			if ( col < c-1 && mat[row][col+1] == '.' && !vis[row][col+1])
				pq.push({ p.f , { 0 , { row , col+1 } } } );
			if ( row < r-1 && mat[row+1][col] == '#' && !vis[row+1][col])
				pq.push({ p.f , { -1 , { row+1 , col } } } );
			if ( col < c-1 && mat[row][col+1] == '#' && !vis[row][col+1])
				pq.push({ p.f , { -1 , { row , col+1 } } } );
		}
		vis[row][col] = true;
	}

	

	printf("%d\n",ans );
	return 0;
}