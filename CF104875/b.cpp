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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const long double PI = acos(0);
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int H, R, Dair, Dwat;


long double getMass(long double h, long double vol) {
	return h * PI * PI * R * vol;
}

long double f(long double h) {
	long double airMass = getMass((H-h), Dair), watMass = getMass(h, Dwat);
	long double airCenter = h + (H-h) / 2, watCenter = h / 2;
	long double ans = (airCenter * airMass + watCenter * watMass) / (watMass + airMass);
	return ans;
}

int main(){
	rii(H,R), rii(Dair, Dwat);

	long double lo = 0, hi = H;
	FOR(i,0,100) {
		long double a = lo + (hi - lo) / 3, b = lo + 2 * (hi - lo) / 3;
		if (f(a) > f(b)) 
			lo = a;
		else 
			hi = b;
	}

	printf("%.10Lf\n", hi);

	return 0;
}
