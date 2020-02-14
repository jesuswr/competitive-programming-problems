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
multiset<int> mset;


int main(){
	int n, me, op, skip;
	rii(n,me);
	rii(op,skip);
	FOR(i,0,n){
		int oph;
		ri(oph);
		oph = oph%(me+op);
		if ( oph == 0 ){
			mset.insert((op)/me + ( op%me ? 1 : 0));
			//printf("skip %d\n", (me+op)/me);
		}
		else if ( oph <= me ){
			mset.insert(0);
			//printf("skip 0\n");
		}
		else{
			mset.insert((oph-me)/me + ( (oph-me)%me ? 1 : 0));
			//printf("skip %d\n", (oph-me)/me + ( (oph-me)%me ? 1 : 0));

		}
	}
	int ans = 0;
	for( int s : mset ){
		if ( s <= skip ){
			skip -= s;
			ans++;
		}
		else 
			break;
	}
	printf("%d\n", ans);
	return 0;
}