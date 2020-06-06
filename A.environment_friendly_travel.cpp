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
int xs,ys,xd,yd,b, car_co2, t, n;
int CO2[200];
vii G[2000];
pii coord[2000];

int dist(pii a, pii b){
	int fuck = (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
	FOR(i,0,INF){
		if ( i*i >= fuck )
			return i;
	}	
}

int cost(pii a, pii b, int c){
	return dist(a,b)*c;
}

int dp[2000][200];

int f(int node, int km){
	if ( km + dist(coord[node], {xd,yd}) > b )
		return INF;
	if ( dp[node][km] != -1 )
		return dp[node][km];

	dp[node][km] = cost(coord[node], {xd,yd}, car_co2);
	for(auto y : G[node]){
		dp[node][km] = min(dp[node][km], cost(coord[node], coord[y.F], CO2[y.S]) + f(y.F, km + dist(coord[node], coord[y.F])));
	}
	return dp[node][km];
}

int main(){
	rii(xs,ys);
	rii(xd,yd);
	ri(b);
	ri(car_co2);
	ri(t);
	FOR(i,1,t+1)
		ri(CO2[i]);
	ri(n);
	FOR(i,0,n){
		rii(coord[i].F, coord[i].S);
		int aux;
		ri(aux);
		FOR(_,0,aux){
			int e, m;
			rii(e,m);
			G[i].pb({e,m});
			G[e].pb({i,m});
		}
	}

	if ( dist({xs,ys},{xd,yd}) > b ){
		printf("-1\n");
		return 0;
	}

	int ans = cost({xs,ys}, {xd,yd}, car_co2);

	FOR(i,0,1500){
		FOR(j,0,150){
			dp[i][j] = -1;
		}
	}

	FOR(i,0,n){
		ans = min(ans, cost({xs,ys}, coord[i], car_co2) + f(i, dist({xs,ys}, coord[i])));
	}
	printf("%d\n", ans);
	return 0;
}