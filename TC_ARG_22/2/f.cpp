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

int pre(int siz) {
	vi a(siz);
	FOR(i,0,siz) a[i] = i;
	int cnt = 0;
	do{
		bool g = 1;
		FOR(i,0,siz) g &= a[i] != i;
		cnt += g;
	} while(next_permutation(all(a)));
	return cnt;
}

ll pick(int n, int k) {
	ll num = 1;
	FOR(i,0,k) num *= (n-i);
	FOR(i,0,k) num /= (k-i);
	return num;
}

int main(){
	int n,k; rii(n,k);
	ll ans = 1;
	if (k >= 2) ans += pre(2) * pick(n, 2);
	if (k >= 3) ans += pre(3) * pick(n, 3);
	if (k >= 4) ans += pre(4) * pick(n, 4);
	cout << ans << endl;

	return 0;
}
