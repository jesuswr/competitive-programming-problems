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
ll A[maxN+10];
map<ll,int> cnt;


int main(){
	int t;
	ri(t);
	FOR(w,1,t+1){
		printf("Case #%d: ", w);
		int n,d;
		rii(n,d);
		ll mx = -1;
		FOR(i,0,n){
			rl(A[i]);
			cnt[A[i]]++;
			mx = max(mx, A[i]);
		}
		if ( d == 2 ){
			int ans = 1;
			for(auto p : cnt){
				ll sz = p.f;
				int cn = p.s;
				if (cn>=2)
					ans = 0;
			}
			printf("%d\n",ans );
		}
		else{
			int ans = 2;
			for(auto p : cnt){
				ll sz = p.f;
				int cn = p.s;
				if ( cn>=3 )
					ans = min(ans, 0);

				if ( cn>=2 && sz != mx )
					ans = min(ans, 1);

				if ( cn>=1 && cnt.find(sz*2)!=cnt.end())
					ans = min(ans,1);
			}
			printf("%d\n",ans );
		}
		cnt.clear();

	}
	return 0;
}