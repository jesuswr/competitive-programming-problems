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
const int maxN = 2e5+10; // CAMBIAR ESTE

// GJNM
piii A[maxN];

ll BIT[maxN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val){ 
    for(; p < maxN; p += p&-p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
    	BIT[p] += val;
}
ll sumBIT(int p){
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}

ll BIT2[maxN];
// suma de rangos [0,n-1]
void updBIT2(int p, ll val){ 
    for(; p < maxN; p += p&-p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
    	BIT2[p] += val;
}
ll sumBIT2(int p){
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT2[p];
    return ret;
}

int main(){
	int n, t;
	rii(n,t);
	FOR(i,0,n){
		rii(A[i].S.F,A[i].F);
		A[i].S.S = i+1;
	}
	sort(A,A+n);
	

	int curr = 0;
	ll ans = -1;
	FOR(i,1,n+1){
		while(sumBIT2(n)-sumBIT2(i-1) < i && curr < n && sumBIT(n)-sumBIT(i-1) + A[curr].F <= t){
			updBIT2(A[curr].S.F,1);
			updBIT(A[curr].S.F,A[curr].F);
			curr++;
		}
		ans = max(ans, sumBIT2(n) - sumBIT2(i-1));
	}
	priority_queue<pii> pq;

	FOR(i,0,n){
		if ( ans == 0 )
			break;
		if ( A[i].S.F >= ans ){
			if ( pq.size()<ans ){
				pq.push({-A[i].F,A[i].S.S});
			}
			else if ( pq.size() == ans ){
				if ( -pq.top().F > A[i].F ){
					pq.pop();
					pq.push({-A[i].F,A[i].S.S});
				}
			}
		}
	}
	printf("%lld\n", ans);
	printf("%lld\n",ans );
	while(!pq.empty()){
		printf("%d ",pq.top().S );
		pq.pop();
	}
	printf("\n");
	return 0;
}