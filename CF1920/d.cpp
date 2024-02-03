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

struct pos {
	vi new_elems;
	long long prev_size;
	long long size;
	int type;
};


int N,Q;
vector<pos> A;

void solve() {
	A.clear();
	rii(N,Q);
	FOR(i,0,N) {
		pos p;
		int t, x; rii(t,x);

		if (sz(A) > 0 && A.back().size >= INFLL) continue; 
		if (sz(A) > 0 && t == 2) 
			x = min(INFLL / A.back().size + 2, 1ll * x);


		p.type = t;
		if (p.type == 2) {
			p.prev_size = A.back().size;
			p.size = (x + 1) * p.prev_size;
			A.pb(p);
		}
		else {
			if (sz(A) == 0) {
				p.prev_size = 0;
				p.size = 1;
				p.new_elems.pb(x);
				A.pb(p);
			}
			else if (A.back().type == 2) {
				p.prev_size = A.back().size;
				p.size = p.prev_size + 1;
				p.new_elems.pb(x);
				A.pb(p);
			}
			else {
				A.back().size += 1;
				A.back().new_elems.pb(x);
			}
		}
	}
	FOR(_,0,Q) {
		ll k; lri(k); --k;
		int i = sz(A) - 1;

		while(1) {
			if (A[i].type == 1) {
				if (k < A[i].prev_size) i--;
				else {
					cout << A[i].new_elems[k - A[i].prev_size] << ' ';
					break;
				}
			}
			else {
				k = k % A[i].prev_size;
				i--;
			}
		}

	}
	cout << endl;
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}