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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N; 
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];

bool valid(long double k) {
	long double acum = 0;
	FOR(i,0,N) {
		acum += max( B[i] - A[i] * k, D[i] - C[i] * k);
	}
	return acum >= 0;
}

int main(){
	ri(N);
	FOR(i,0,N) lri(A[i]), lri(B[i]), lri(C[i]), lri(D[i]);

	long double lo = 0, hi = 1e18, mi;
	FOR(_,0,200) {
		mi = (lo + hi) / 2;
		if (valid(mi)) lo = mi;
		else hi = mi;
	}
	printf("%.12Lf\n", lo);

	return 0;
}
