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
pii arr[1010];
map< pii , int > mp;

int main()
{
	int n;
	ri(n);
	FOR(i,0,n)
		rii(arr[i].f,arr[i].s);
	FOR(i,0,n){
		int x,y;
		rii(x,y);
		FOR(j,0,n){
			if ( mp.find( {x+arr[j].f,y+arr[j].s}) == mp.end() )
				mp[{x+arr[j].f,y+arr[j].s}] = 1;
			else
				mp[{x+arr[j].f,y+arr[j].s}]++;
			if ( mp[{x+arr[j].f,y+arr[j].s}] == n ){
				printf("%d %d\n", x+arr[j].f,y+arr[j].s);
				return 0;
			}
		}
	}
	return 0;
}