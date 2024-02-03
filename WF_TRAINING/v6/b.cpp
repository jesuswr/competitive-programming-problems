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
const int MAXN = 1e4+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2*acos(0.0);


T cross(pt v, pt w) {return (conj(v)*w).y;}

int N;
pt P[MAXN];
bool COVER[MAXN];
int CNT;

void possible(int e) {
	// cout << e << endl;
	cout << "possible" << endl;
	exit(0);
}

vi mark(const vi &inds, int ai, int bi) {
	vi ret;
	for(int i : inds) {
		if (cross(P[i] - P[ai], P[bi] - P[ai]) == 0) ret.pb(i);
	}
	return ret;
}

int main(){
	ri(N);
	if (N <= 6) possible(0);
	FOR(i,0,N) {
		int a,b; rii(a,b);
		P[i] = pt(a,b);
	}
	
	vi inds;
	FOR(i,0,N) inds.pb(i);
	FOR(_,0,1000) {
		int i = rng() % N;
		int j = i;
		while(i == j) j = rng() % N;

		auto marks = mark(inds, i, j);
		for(int k : marks) {
			COVER[k] = 1;
			CNT++;
		}

		if (CNT + 4 >= N) possible(1);

		vi rem;
		FOR(k,0,N) if (!COVER[k]) rem.pb(k);
		
		vii opts = {{0,1}, {0,2}, {1,2}};
		for(auto [i,j] : opts) {
			i = rem[i];
			j = rem[j];

			auto marks = mark(rem, i, j);
			for(int k : marks) {
				COVER[k] = 1;
				CNT++;
			}

			
			if (CNT + 2 >= N) possible(2);

			vi rem2;
			FOR(k,0,N) if (!COVER[k]) rem2.pb(k);
			{
				int i = rem2[0], j = rem2[1];
				auto marks = mark(rem2, i, j);
				for(int k : marks) {
					COVER[k] = 1;
					CNT++;
				}
				if (CNT == N) possible(4);
				for(int k : marks) {
					COVER[k] = 0;
					CNT--;
				}
			}




			for(int k : marks) {
				COVER[k] = 0;
				CNT--;
			}
		}
		

		for(int k : marks) {
			COVER[k] = 0;
			CNT--;
		}
	}

	cout << "impossible" << endl;
	return 0;
}
