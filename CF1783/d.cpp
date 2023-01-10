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
const int MOD = 998244353;
const int MAXN = 303;
const int H = MAXN*MAXN;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, A[MAXN];

int DP[MAXN][2 * MAXN*MAXN];
int f(int i, int a) {
	int &ret = DP[i][a+H];
	if (i >= N - 2) return 1;
	if (ret != -1) return ret;
	ret = 0;
	if (a == 0) ret = f(i+1, A[i+2]);
	else {
		ret = f(i+1, A[i+2] - a) + f(i+1, A[i+2] + a);
		if (ret >= MOD) ret -= MOD;
	}
	return ret;
}


int main(){
	ms(DP, -1);
	ri(N);
	FOR(i,0,N) ri(A[i]);
	printf("%d\n", f(0, A[1]));
	return 0;
}
