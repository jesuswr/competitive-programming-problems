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

bool go(const vi &a, int g) {
	for(auto x : a) {
		if (x % g == 0) continue;
		int opt = (x-1) / 2;
		if (1 <= g && g <= opt) continue;
		return false;
	}
	return true;
}

int main(){
	int n; ri(n);
	vi a(n);
	FOR(i,0,n) ri(a[i]);
	sort(all(a));

	if (a[0] == 1) {
		printf("1\n");
		return 0;
	}

	if (go(a, a[0])) printf("%d\n", a[0]);
	else printf("%d\n", a[0] / 2);

	return 0;
}
