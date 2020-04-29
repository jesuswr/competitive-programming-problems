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
int mat[11][101];

int main(){
	int r,c;
	while(scanf("%d %d", &r, &c) != EOF){
		FOR(i,0,r)
			FOR(j,0,c)
				ri(mat[i][j]);

		ROF(j,c-2,-1)
			FOR(i,0,r){
				mat[i][j] += min( mat[i][j+1], min( mat[(i+r-1)%r][j+1], mat[(i+1)%r][j+1] ) );
			}

		int ans = INF, ind;
		FOR(i,0,r)
			if ( ans > mat[i][0] ){
				ind = i;
				ans = mat[ind][0];
			}
		deque<int> q;
		q.push_back(ind);
		FOR(i,1,c){
			int curr = q.back();
			int l = mat[curr][i];
			int u = mat[(curr+r-1)%r][i];
			int d = mat[(curr+1)%r][i];
			int mn = INF;
			if ( l == min(l,min(u,d)))
				mn = min(mn,curr);
			if ( u == min(l,min(u,d)))
				mn = min(mn,(curr+r-1)%r);
			if ( d == min(l,min(u,d)))
				mn = min(mn,(curr+1)%r);
			q.push_back(mn);
		}
		while(!q.empty()){
			if (q.size()>1)
				printf("%d ", q.front()+1);
			else
				printf("%d", q.front()+1);
			q.pop_front();
		}
		printf("\n");
		printf("%d\n",ans );
	}
	return 0;
}