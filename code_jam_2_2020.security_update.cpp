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
const int maxN = 105; // CAMBIAR ESTE

// GJNM
map< pii, int > ans;
map< int, pii> indPair;

vi act[maxN];

int c,d;
int cost[maxN];
bool vis[maxN];
vi g[maxN];

void dfs(int x, int p){
	vis[x] = true;
	for(int y : g[x]){
		if ( vis[y] ){
			if ( cost[y] < p ){
				cost[x] = p;
				ans[{x,y}] = ans[{y,x}] = p - cost[y];
			}
			
		}
	}
}

int main(){
	int t;
	ri(t);
	FOR(w,1,t+1){
		vii pos,neg;
		rii(c,d);
		cost[0] = 0;
		FOR(i,1,c){
			ri(cost[i]);
			if ( cost[i] < 0 )
				neg.pb({-cost[i],i});
			else
				pos.pb({cost[i],i});
		}
		FOR(i,0,d){
			int a,b;
			rii(a,b);
			a--,b--;
			g[a].pb(b);
			g[b].pb(a);
			indPair[i] = {a,b};
		}

		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end());
		
		int N = neg.size();
		int P = pos.size();

		int ni = 0;
		int pi = 0;

		vis[0] = true;
		int curr = 1;
		int lastadd = 0;
		while( pi < P || ni < N ){
			int add = 0;
			while( ni < N && curr == neg[ni].F ){
				dfs( neg[ni].S , lastadd + 1);
				add++;
				ni++;
			}
			curr += add;

			if ( add ){
				lastadd++;
				continue;
			}

			dfs( pos[pi].S , pos[pi].F);
			lastadd = pos[pi].F;
			pi++;
			curr++;
		}

		printf("Case #%d: ",w);
		FOR(i,0,d){
			if ( ans.find(indPair[i]) != ans.end() )
				printf("%d ",ans[ indPair[i] ] );
			else
				printf("1000000 ");
		}
		printf("\n");


		FOR(i,0,c){
			vis[i] = false;
			g[i].clear();
			act[i].clear();
		}
		ans.clear();
		indPair.clear();


	}
	return 0;
}