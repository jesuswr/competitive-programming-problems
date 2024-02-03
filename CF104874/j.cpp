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
const int MAXN = 500+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN][MAXN];
bool ANS[MAXN][MAXN];

void go(int i) {
	FOR(j,i+1,N) {
		if (A[i][j] == 0) continue;
		assert(A[i][j] == 1);

		ANS[i][j] = 1;
		FOR(k,j+1,N) A[i][k] = (A[i][k] - A[j][k] + 10) % 10;
	}
}

int main(){
	ri(N);
	FOR(i,0,N) FOR(j,0,N) das = scanf("%1d", &A[i][j]);

	FOR(i,0,N-1) go(i);

	FOR(i,0,N) {
		FOR(j,0,N) printf("%1d", ANS[i][j]);
		printf("\n");
	}

	return 0;
}
