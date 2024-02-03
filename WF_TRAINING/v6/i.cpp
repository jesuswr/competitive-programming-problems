#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+5 + 3e5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,Q; 
int P[MAXN];
set<int> ST;

int main(){
	ri(N);
	FOR(i,1,MAXN+2*N) ST.insert(i);
	FOR(i,0,N) ri(P[i+1]);
	FOR(i,0,N) ST.erase(P[i+1]);
	ri(Q);
	while(Q--) {
		int i; ri(i);
		
		auto it = ST.lower_bound(P[i]);
		int pi = *it;

		ST.erase(it);
		ST.insert(P[i]);
		
		P[i] = pi;
		cout << pi << endl;
	}

	return 0;
}
