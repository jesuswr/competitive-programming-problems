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
const int MAXN = 2000+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int N,M,K;
ii LR[MAXN];
int MX_R[MAXN];
int NXT_L[MAXN];

void pre() {
	sort(LR, LR + M);
	ms(MX_R, -1);
	FOR(i,0,M) FOR(j,LR[i].F,LR[i].S+1) {
		if (MX_R[j] == -1)
			MX_R[j] = i;
		else if (LR[ MX_R[j] ].S < LR[ i ].S || (LR[ MX_R[j] ].S == LR[ i ].S && LR[ MX_R[j] ].F > LR[ i ].F))
			MX_R[j] = i;
	}
	FOR(i,0,M) {
		ii x = {LR[i].S+1, -1};
		auto it = lower_bound(LR, LR+M, x);
		NXT_L[i] = it - LR;
	}
}


int DP[MAXN][MAXN][2];
int f(int p, int k, int c) {
	int &ret = DP[p][k][c];
	if (k < 0) return -INF;
	if (ret != -1) return ret;
	if (p == M) return 0;

	ret = 0;
	if (c == 0) { // empezando uno nuevo
		ret = max(
			f(p+1, k, 0), // no hago nada y paso al siguiente
			LR[p].S - LR[p].F + 1 + f(NXT_L[p], k-1, 0) // tomo este y paso al siguiente que no se intersecte
		);
		if (MX_R[LR[p].S] != -1 && MX_R[LR[p].S] != p)
			ret = max(ret, f(MX_R[LR[p].S] , k-1, 1 )  - LR[p].F + 1 ); // empezar un segmento pero no cerrarlo aun 
	}
	else { // expandiendo uno anterior
		ret = LR[p].S + f(NXT_L[p], k-1, 0); // cierro aqui y paso al siguiente que no se intersecte
		if (MX_R[LR[p].S] != -1 && MX_R[LR[p].S] != p)
			ret = max(ret, f(MX_R[LR[p].S] , k-1, 1 )  ); // continuar el segmento 	
	}

	return ret;
}


void solve(int qlq) {
	rii(N,M); ri(K);
	FOR(i,0,M) rii(LR[i].F, LR[i].S);
	pre();
	ms(DP, -1);
	printf("Case #%d: %d\n", qlq, f(0,K,0));
}

int main(){
	int t; ri(t);
	int _i = 0;
	while(t--) solve(++_i);
	return 0;
}
