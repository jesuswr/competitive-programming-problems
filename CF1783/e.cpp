#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 4e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll BIT[MAXN];
void updBIT(int p, ll val){ 
    p++;	
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}

ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}


struct qry{
	int a, b, i;

	bool operator<(qry other) {
		return a < other.a;
	}
};

int N;
qry Q[MAXN];


void solve(){
	ri(N);
	FOR(i,0,N) ri(Q[i].a);
	FOR(i,0,N) ri(Q[i].b);

	FOR(i,0,N) {
		if (Q[i].b < Q[i].a) {
			updBIT(Q[i].b, 1);
			updBIT(Q[i].a, -1);
		}
	}

	vi ans;

	FOR(k,1,N+1) {
		bool g = 1;
		int x = k;
		while(x < N) {
			if (sumBIT(x) > 0) {
				g = 0;
				break;
			}
			x += k;
		}

		if (g) ans.pb(k);
	}


	printf("%d\n", sz(ans));
	for(int x : ans) printf("%d ", x);
	printf("\n");

	FOR(i,0,N) {
		if (Q[i].b < Q[i].a) {
			updBIT(Q[i].b, -1);
			updBIT(Q[i].a, 1);
		}
	}
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
