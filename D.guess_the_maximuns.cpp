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
int n,k;
vi sets[1010];
map<int,int> in_set;
char resp[100];
int A[maxN];

int query(int l,int r){
	printf("? %d ", r-l+1);
	FOR(i,l,r+1)
		printf("%d ",i );

	printf("\n");
	fflush(stdout);
	int ans;
	ri(ans);
	return ans;
}

int query2(int rm){
	vector<int> q;
	FOR(i,1,n+1){
		if ( in_set[i] == rm )
			continue;
		q.pb(i);
	}
	printf("? %d ", (int)q.size());
	for(auto x : q )
		printf("%d ", x);
	printf("\n");
	fflush(stdout);
	int ans;
	ri(ans);
	return ans;
}



int main(){
	int t;
	ri(t);
	while(t--){
		in_set.clear();
		rii(n,k);
		FOR(i,1,n+1)
			in_set[i] = INF;
		FOR(i,0,k){
			sets[i].clear();
			int c;
			ri(c);
			FOR(j,0,c){
				int aux;
				ri(aux);
				sets[i].pb(aux);
				in_set[aux] = i;
			}
		}
		int mx = query(1,n);
		int lo = 1, hi = n;
		while( lo<hi ){
			int mid = lo + (hi-lo)/2;
			if (query(lo,mid) == mx)
				hi = mid;
			else
				lo = mid+1;
		}
		int mx2 = query2(in_set[hi]);
		printf("! ");
		FOR(i,0,k){
			if ( in_set[lo] == i )
				printf("%d ", mx2);
			else
				printf("%d ", mx);
		}
		printf("\n");
		fflush(stdout);

		scanf("%s",resp);
		if ( resp[0] == 'I')
			return 0;
	}

	return 0;
}