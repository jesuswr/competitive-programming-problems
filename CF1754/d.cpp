#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
int P_SZ;
vi P;


void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int N, X;
int A[MAXN];
int F[MAXN];

void pre() {
	FOR(i, 0, 100) {
		P_SZ++;
		P.pb( (rng() % 3124567) + MAXN );
	}
}

bool good(const int ind) {
	F[0] = 1;
	FOR(i, 1, X + 1) F[i] = (1ll * F[i - 1] * i) % P[ind];
	int SM_MOD = 0;
	FOR(i, 0, N) SM_MOD = (SM_MOD + F[A[i]]) % P[ind];
	int X_MOD = F[X] % P[ind];

	int aux = X_MOD;
	FOR(_, 0, N) {
		if (aux == SM_MOD) return true;
		aux = (aux + X_MOD) % P[ind];
	}
	return false;
}

void solve() {
	rii(N, X);
	FOR(i, 0, N) ri(A[i]);
	pre();
	bool g = 1;
	FOR(i, 0, P_SZ) {
		if (!good( i )) {
			g = 0;
			break;
		}
	}
	if (g) printf("Yes\n");
	else printf("No\n");
}

int main() {
	solve();
	return 0;
}