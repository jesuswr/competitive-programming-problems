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
int father[maxN], siz[maxN];
int sweep[2*maxN];
set<int,greater<int>> open;
int A[maxN],B[maxN];

void makeSet(int n, int m)
{
	for (int i = n; i <= m; ++i)
	{
		father[i] = -1;
		siz[i] = 0;
	}
}

int find(int x)
{
	if (father[x]==-1) return x;

	return father[x] = find(father[x]);
}

void unio(int x, int y)
{
	x = find(x);
	y = find(y);
	if (siz[x] > siz[y]) father[y] = x;
	else
	{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}


int main()
{
	int n;
	ri(n);
	FOR(i,1,n+1){
		rii(A[i],B[i]);
		sweep[A[i]] = i;
		sweep[B[i]] = -i;
	}
	makeSet(1,n);
	int cc = n;
	FOR(i,1,2*n+1){
		if ( sweep[i] > 0 ){
			//printf("Abrio el %d, que empieza en %d\n",sweep[i],i );
			open.insert(i);
		}
		else{
			int roof = A[-sweep[i]];
			for(int y : open){
				if ( y <= roof ) break;
				if ( find(sweep[y]) == find(-sweep[i]) ){
					printf("NO\n");
					return 0;
				}
				unio(sweep[y],-sweep[i]);
				cc--;
			}
			//printf("Cerro el %d, que termina en %d\n",-sweep[i],i );
			//printf("%d\n",roof );
			open.erase(roof);
		}
	}
	if ( cc == 1 ) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}