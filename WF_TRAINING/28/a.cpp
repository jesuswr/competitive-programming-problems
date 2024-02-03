#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e+5;

struct elem {
	int p, h, i;

	bool operator<(elem x) {
		return p < x.p;
	}

};

int N;
elem B[MAXN], F[MAXN];

vector< vector< set<ii> > > ST;
void group(elem A[]) {
	vector< set<ii> > res;
	int l = 0;
	while(l < N) {
		set<ii> nw;
		int r = l;
		while(r < N && A[l].p == A[r].p) {
			nw.insert({A[r].h, A[r].i});
			r++;
		}
		res.push_back(nw);
		l = r;
	}
	ST.push_back(res);
}

ii ANS[MAXN];

int main() {
	ri(N);
	FOR(i,0,N) ri(B[i].p);
	FOR(i,0,N) ri(B[i].h);
	FOR(i,0,N) ri(F[i].p);
	FOR(i,0,N) ri(F[i].h);
	FOR(i,0,N) B[i].i = F[i].i = i+1;

	sort(B,B+N); group(B);
	sort(F,F+N); group(F);

	int bi = 0, fi = 0;
	FOR(i,0,N) {
		if (sz(ST[0][bi]) == 0) bi++;
		if (sz(ST[1][fi]) == 0) fi++;

		if (sz(ST[0][bi]) >= sz(ST[1][fi])) {
			ii f = *ST[1][fi].begin();
			auto it = ST[0][bi].lower_bound({ f.F + 1, -1 });
			if (it == ST[0][bi].end()) {
				cout << "impossible" << endl;
				return 0;
			}
			ii b = *it;
			ANS[i] = {b.S, f.S};
			ST[1][fi].erase( ST[1][fi].find(f) );
			ST[0][bi].erase( ST[0][bi].find(b) );
		}
		else {
			ii b = *ST[0][bi].begin();
			auto it = ST[1][fi].lower_bound({b.F, -1}); 
			if (it == ST[1][fi].begin()){
				cout << "impossible" << endl;
				return 0;
			}
			--it;
			ii f = *it;
			ANS[i] = {b.S, f.S};
			ST[1][fi].erase( ST[1][fi].find(f) );
			ST[0][bi].erase( ST[0][bi].find(b) );
		}

	}
	FOR(i,0,N) printf("%d ", ANS[i].F);
	printf("\n");
	FOR(i,0,N) printf("%d ", ANS[i].S);
	printf("\n");

	return 0;
}
