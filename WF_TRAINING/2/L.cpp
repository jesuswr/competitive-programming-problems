#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

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

ld i;
int n, k;

ld pow(ld b, int e) {
	ld r = 1;
	while(e) {
		if (e & 1) r = (r * b);
		e >>= 1;
		b = b * b;
	}
	return r;
}

int main(){
	cin >> n >> i >> k;
	ld ans = i * pow( (i - 1) / n , k);
	FOR(a, i, n+1) {
		ld x = ((ld)a + 1) / 2;
		ld y = pow((ld)a / n, k) - pow(((ld)a - 1) / n, k);
		ans += x * y;
	}
	printf("%.10Lf\n", ans);
	return 0;
}
