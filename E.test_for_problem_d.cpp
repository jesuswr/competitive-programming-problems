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
const int maxN = 5e5+5; // CAMBIAR ESTE

// GJNM
vi g[maxN];
bool vis[maxN];
queue<int> order;
stack<int> open;
pii out[maxN];

int main()
{
	int n;
	ri(n);
	FOR(i,0,n-1){
		int a , b;
		rii(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	vis[1] = true;
	open.push(1);
	order.push(1);
	while(!open.empty()){
		int x = open.top();
		open.pop();
		for(int y : g[x]){
			if ( vis[y] ) continue;
			vis[y] = true;
			open.push(y);
			order.push(y);
		}
		order.push(-x);
	}
	int aux;
	int ind = 1;
	while( !order.empty() ){
		aux = order.front();
		if ( aux > 0 )
			out[aux].f = ind++;
		else
			out[-aux].s = ind++;

		order.pop();
	}
	FOR(i,1,n+1)
		printf("%d %d\n", out[i].f,out[i].s);
	return 0;
}