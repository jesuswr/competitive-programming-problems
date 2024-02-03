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
const int MAXN = 1e6+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N; 
int M;
int X[MAXN], Y[MAXN], D[MAXN];
ii VALS[MAXN];

void get_initial_vals(int x, int y, int d) {
	FOR(dx, 0, d+1) {
		int dy = d - dx;
		VALS[M++] = {x+dx, y+dy};
		if (dx) VALS[M++] = {x-dx, y+dy};
		if (dy) VALS[M++] = {x+dx, y-dy};
		if (dx && dy) VALS[M++] = {x-dx, y-dy}; 
	}
}

void update_vals(int x, int y, int d) {
	int new_m = 0;
	FOR(i,0,M) {
		if ( abs(x - VALS[i].F) + abs(y - VALS[i].S) == d ) VALS[new_m++] = VALS[i];
	}
	M = new_m;
}


int main(){
	ri(N);
	FOR(i,0,N) rii(X[i], Y[i]), ri(D[i]);
	vi ord;
	FOR(i,0,N) ord.pb(i);
	shuffle(ord.begin(), ord.end(), rng);
	int mn = 0;
	FOR(i,1,N) if (D[i] < D[mn]) mn = i;
	get_initial_vals(X[mn], Y[mn], D[mn]);
	FOR(_i,0,N) {
		int i = ord[_i];
		if (i == mn) continue;
		else update_vals(X[i], Y[i], D[i]);
	}	
	sort(VALS, VALS + M);
	FOR(i,0,M) printf("%d %d\n", VALS[i].F, VALS[i].S);
	cout << M << endl;
	return 0;
}
