#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	int N, Q;
	rii(N, Q);
	deque<int> I;
	FOR(i, 0, N) {
		I.pb(i);
	}
	vector<int> A(N);
	FOR(i, 0, N) {
		ri(A[i]);
	}

	vector<tuple<int, int, int>> Qs;
	FOR(i, 0, Q) {
		int j, r; rii(j, r); --j;
		Qs.pb({r, j, i});
	}
	sort(all(Qs));
	map<int,int> W;
	int t = 0;
	vector<int> ANS(Q);
	for (auto [round, ind, i] : Qs) {
		while (round > t && A[I[0]] != N) {
			int xi = I[0]; I.pop_front();
			int yi = I[0]; I.pop_front();

			if (A[xi] < A[yi]) swap(xi, yi);

			I.push_front(xi);
			I.push_back(yi);

			W[xi] += 1;

			t += 1;
		}

		ANS[i] = W[ind] + (A[ind] == N ? round - t : 0);
	}

	for(auto x : ANS) cout << x << endl;

}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}