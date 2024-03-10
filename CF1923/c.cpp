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
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 3e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q;
int A[MAXN];
ll PCNT[MAXN];
ll PSUM[MAXN];

void pre() {
	PCNT[0] = A[0] == 1;
	PSUM[0] = A[0];
	FOR(i,1,N) {
		PCNT[i] = PCNT[i-1] + (A[i] == 1);
		PSUM[i] = PSUM[i-1] + A[i];
	}
}

pair<ll,ll> q(int l, int r) {
	ll cnt = PCNT[r]; 
	ll sum = PSUM[r];
	if (l > 0) {
		cnt -= PCNT[l-1];
		sum -= PSUM[l-1];
	}
	return {cnt, sum};
}


void solve() {
	rii(N,Q);
	FOR(i,0,N) ri(A[i]);
	pre();
	while(Q--) {
		int l, r; rii(l,r); --l; --r;
		if (l == r) {
			printf("NO\n");
			continue;
		}

		auto [one_cnt, sum] = q(l,r);
		ll other_cnt = (r - l + 1) - one_cnt;
		if (2  * one_cnt + other_cnt <= sum) printf("YES\n");
		else printf("NO\n");

	}
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
