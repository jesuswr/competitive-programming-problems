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
const int MAXN = 35198992;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int IND[MAXN];
int FATHER[MAXN];
float LIS[MAXN];

int main(){
	ri(N);

	// vector<float> lis;
	// lis.reserve(N);
	// FOR(i,0,MAXN) {
	// 	float val = sin(i);
	// 	int ind = lower_bound(all(lis), val) - lis.begin();
	// 	if (ind == sz(lis)) lis.pb(0);
	// 	lis[ind] = val;

	// 	if (ind > 0) 
	// 		FATHER[i] = IND[ind-1];
	// 	else
	// 		FATHER[i] = -1;

	// 	IND[ind] = i;

	// 	if (sz(lis) == N) break;
	// }

	int sz = 0;
	FOR(i,0,MAXN) {
		float val = sin(i);
		if (i >= 18030549 && val <= 0) continue;
		else if (i <= 18030549 && val > 0) continue;
		int ind = lower_bound(LIS, LIS + sz, val) - LIS;
		if (ind == sz) sz++;
		LIS[ind] = val;

		if (ind > 0) 
			FATHER[i] = IND[ind-1];
		else
			FATHER[i] = -1;

		IND[ind] = i;

		if (sz == N) break;
	}

	vi ans;
	int i = IND[N-1];
	while(i != -1) {
		ans.pb(i);
		i = FATHER[i];
	}
	reverse(all(ans));
	for(int x : ans) printf("%d\n", x);

	return 0;
}
