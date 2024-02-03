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
const int MOD[2] = {1000000007, 1000000009};
const int P = 1002191;
const int MAXN = 4e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
int CNT[MAXN];
int ON;
int POW[2][MAXN];
int HSH[2];
map< ii , int > MP;


void pre() {
	POW[0][0] = POW[1][0] = 1;
	FOR(i,1,MAXN) {
		POW[0][i] = 1ll * POW[0][i-1] * P % MOD[0];
		POW[1][i] = 1ll * POW[1][i-1] * P % MOD[1];
	}
}

void add(int i) {
	if (CNT[i] == 0) ON++;
	CNT[i] += 1;
	FOR(p,0,2) HSH[p] = (HSH[p] + POW[p][i]) % MOD[p];
}
void rem(int i) {
	if (CNT[i] == 1) ON--;
	CNT[i] -= 1;
	FOR(p,0,2) HSH[p] = (HSH[p] - POW[p][i] + MOD[p]) % MOD[p]; 
}


int main(){
	pre();
	rii(N,K);

	int ans = 0;
	MP[{0,0}] = -1;
	FOR(i,0,N) {
		int ci; ri(ci);
		add(ci);
		if (ON == K) FOR(j,1,K+1) rem(j);
		
		if (MP.find({HSH[0], HSH[1]}) == MP.end()) MP[{HSH[0], HSH[1]}] = i;
		else ans = max(ans, i - MP[{HSH[0], HSH[1]}]);
	}
	cout << ans << endl;
	return 0;
}
