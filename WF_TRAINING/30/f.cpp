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
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
char S[MAXN];
int A[MAXN];

vector<vi> OPTS[10][10];
vi aux;

void go(int rem, int obj_sum, int curr_sum, vector<vi> &opts, int l, int r) {
	if (rem == 0) {
		if (obj_sum == curr_sum) opts.pb(aux);
		return;
	}
 
	for(int x = l; x <= r; ++x) {
		aux.pb(x);
		go(rem-1, obj_sum, curr_sum + x, opts, l, r);
		aux.pop_back();
	}
}
void go2(int rem, int obj_sum, int curr_sum, vector<vi> &opts, int l, int r, bool has2 = false) {
	if (rem == 0) {
		if (obj_sum == curr_sum && has2) opts.pb(aux);
		return;
	}
 
	for(int x = l; x <= r; ++x) {
		aux.pb(x);
		go2(rem-1, obj_sum, curr_sum + x, opts, l, r, has2 || (x == 2));
		aux.pop_back();
	}
}
 
 
void pre() {
	int mx = 0;
	for(int k = 2; k <= 7; ++k) {
		for(int m = 0; m < k; ++m) {
			go(k, m, 0, OPTS[k][m], -1, 1);
			if (m)
				go2(k, m, 0, OPTS[k][m], 0, 2);
			mx = max(mx, sz(OPTS[k][m]));
		}
	}
	// cout << mx << endl;
}


pair<vector<int>, bool> add(const vi &o, int base, int mx_sz) {
	int l = 0;
	vii ranges;
	
	for(int sz : o) {
		sz += base;
		if (sz < 1 || sz > mx_sz) return {{}, true};

		ranges.pb({l, l + sz - 1});

		l += sz;
	}

	vi result;
	result.reserve(3*base);

	int carry = 0;
	bool keep_going = true;
	int sm;
	while(keep_going) {
		keep_going = false;
		sm = carry;
		FOR(i,0,sz(ranges)) {
			if (ranges[i].S < ranges[i].F) continue;

			sm += A[ranges[i].S];
			
			ranges[i].S--;
			keep_going |= ranges[i].F <= ranges[i].S;
		}
		carry = sm / 10;
		sm %= 10;
		result.pb(sm);
	}
	if (carry) result.pb(carry);
	
	reverse(all(result));
	return {result, false};
}

bool first_smaller_than_second(const vi &first, const vi &second) {
	if (sz(first) < sz(second)) return true;
	if (sz(first) > sz(second)) return false;

	FOR(i,0,sz(first)) {
		if (first[i] < second[i]) return true;
		if (first[i] > second[i]) return false;
	}
	return false;
}

void _solve() {
	int mn_sz = INF;
	vector<int> mn;
	for(const vi &o : OPTS[K][N%K]) {
		auto [res, error] = add(o, N/K, mn_sz);
		if (error) continue;

		if (sz(mn) == 0) swap(mn, res);
		else if (first_smaller_than_second(res, mn)) swap(mn, res);
		mn_sz = sz(mn);
	}
	for(int d : mn) printf("%d", d);
	printf("\n");
}
 
 
void solve() {
	das=scanf("%d %d\n", &N, &K);
	++K;
	das=scanf("%s\n", S);
	FOR(i,0,N) A[i] = S[i] - '0';

	_solve();
 
}

int main(){
	pre();
	int t; 
	cin >> t;
	while(t--) solve();
	return 0;
}