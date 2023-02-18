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

int N, Q;

ll BIT[MAXN];
void clearBIT() {
	FOR(i,0,2*N) BIT[i] = 0;
}
void updBIT(int p, ll val){ 
    p++;	
    for(; p < 2*N; p += p&-p) BIT[p] += val;
}

ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[p];
    return ret;
}

int sumDig(int x) {
	int ret = 0;
	while(x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

void solve() {
	rii(N,Q);
	vi a(N), c(N);
	FOR(i,0,N) ri(a[i]);
	clearBIT();
	while(Q--) {
		int t; ri(t);
		if (t == 1) {
			int l, r; rii(l, r);
			updBIT(l-1, 1);
			updBIT(r, -1);
		}
		else {
			int x; ri(x);
			--x;
			int aux = sumBIT(x);
			while(aux > c[x] && a[x] >= 10) {
				a[x] = sumDig(a[x]);
				c[x]++;
			}
			cout << a[x] << endl;
		}	
	} 
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
