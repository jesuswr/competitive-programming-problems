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

int N, M, K, L;
char S[MAXN];


int NXT_ZERO[MAXN];
int SUF_SUM[MAXN];
void pre() {
	int nxt_zero = N;
	NXT_ZERO[N] = N;
	for(int i = N-1; i >= 0; --i) {
		NXT_ZERO[i] = nxt_zero;
		if (S[i] == '0') nxt_zero = i;
		SUF_SUM[i] = SUF_SUM[i+1] + (S[i] == '0');
	}
}
int count_zeros(int l, int r) {
	return SUF_SUM[l] - SUF_SUM[r+1];
}

int DP[MAXN][6];
int f(int p, int k) {
	if (k == 0) return 0;
	if (N - p < L) return INF; // dont have L elements remaining
	if (DP[p][k] != -1) return DP[p][k];

	int zeros = count_zeros(p, p+L-1);
	int nxt = NXT_ZERO[p+L-1]+1;

	DP[p][k] = min(
		f(p+1,k),
		zeros + f(nxt, k-1)
	);

	return DP[p][k];
}

bool go(int l) {
	L = l;
	FOR(i,0,N) FOR(j,0,K+1) DP[i][j] = -1;
	return f(0,K) <= M;
}

int main(){
	das=scanf("%d %d %d\n", &N, &M, &K);
	das=scanf("%s\n", S);
	pre();

	int lo = 0, hi = N;
	while(lo < hi) {
		int mi = lo + (hi - lo + 1) / 2;
		if (go(mi)) lo = mi;
		else hi = mi - 1;
	}
	if (lo == 0) lo = -1;
	printf("%d\n", lo);
	return 0;
}
