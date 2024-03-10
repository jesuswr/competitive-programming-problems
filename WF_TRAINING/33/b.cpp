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

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define mkt make_tuple
const double PI = 2*acos(0.0);

T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

int N;
string S;
vector<pt> A, B;

T go(vector<pt> &poly) {
	int n = sz(poly);
	T ans = 0;
	FOR(i,0,n/2) ans += abs(poly[i] - poly[i + n/2]);
	return ans;
}

int main(){
	ri(N);
	cin >> S;
	FOR(i,0,N) {
		int a,b; rii(a,b);
		pt p(a,b);
		if (S[i] == 'B') A.pb(p);
		else B.pb(p);
	}

	T ans = go(A) + go(B);
	printf("%.10lF\n", ans);

	return 0;
}
