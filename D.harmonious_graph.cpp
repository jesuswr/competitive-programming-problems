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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
int father[2*maxN], siz[2*maxN], mn[2*maxN], mx[2*maxN];
int v,e;

void makeSet(int n, int m)
{
	for (int i = n; i <= m; ++i)
	{
		father[i] = -1;
		siz[i] = 0;
		mn[i] = mx[i] = i;
	}
}

int find(int x)
{
	if (father[x]==-1) return x;

	return father[x] = find(father[x]);
}

void unio(int x, int y)
{
	if (siz[x] > siz[y]) {
		father[y] = x;
		mn[x] = min(mn[x],mn[y]);
		mx[x] = max(mx[x],mx[y]);
	}
	else
	{
		father[x] = y;
		mn[y] = min(mn[x],mn[y]);
		mx[y] = max(mx[x],mx[y]);
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}


int main()
{
	rii(v,e);
	makeSet(1,v);
	FOR(i,0,e){
		int a,b;
		rii(a,b);
		if ( find(a) != find(b) ) unio(find(a),find(b));
	}
	int i = 1;
	ll ans = 0;
	while( i <= v){
		if ( find(i) == i ){
			for(int j = mn[i]+1 ; j < mx[i]+1; j++){
				if (find(j) != find(i)){
					ans ++;
					unio(find(i),find(j));
				}
			}
		}
		i++;
	}
	printf("%lld\n",ans );
	return 0;
}