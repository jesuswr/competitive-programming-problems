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
#define X first
#define F first
#define Y second
#define S second

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 512;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
ii P[MAXN];

ll dist(ii p, ii q) {
	return 1ll * (p.X - q.X) * (p.X - q.X) + 1ll * (p.Y - q.Y) * (p.Y - q.Y); 
}
int get_median(vi &x) {
	int n = x.size();
	nth_element(x.begin(),x.begin() + n / 2,x.end());if (n & 1) return x[n / 2];
	return (*max_element(x.begin(),x.begin() + n / 2) + x[n / 2]) / 2;
}

map<pair<ii, ii>, pair<pair<ii,ii>, int>> DP;
pair<pair<ii, ii>, int> go(ii p, ii q) {
	if (p > q) swap(p, q);
	if (DP.find({p, q}) != DP.end()) return DP[{p, q}];

	vi xs_p, ys_p, xs_q, ys_q;
	FOR(i,0,N) {
		if (dist(P[i], p) < dist(P[i], q) || (dist(P[i], p) <= dist(P[i], q) && p < q)) {
			xs_p.pb(P[i].X);
			ys_p.pb(P[i].Y);
		} 
		else {
			xs_q.pb(P[i].X);
			ys_q.pb(P[i].Y);
		}
	}
	ii new_p = {get_median(xs_p), get_median(ys_p)}, new_q = {get_median(xs_q), get_median(ys_q)};
	if (new_p == p && new_q == q) return DP[{p,q}] = {{p,q}, 1};
	auto [pq, its] = go(new_p, new_q);
	return DP[{p, q}] = {pq, its+1};
}

map< pair<ii, ii> , ii > ANS;

int main(){
	ri(N);
	FOR(i,0,N) rii(P[i].X, P[i].Y);
	FOR(i,0,N) {
		P[i].X *= 2;
		P[i].Y *= 2;
	}
	FOR(i,0,N) FOR(j,i+1,N) {
		auto [p, its] = go(P[i], P[j]);
		ANS[p].F += its;
		ANS[p].S += 1;
	}

	for(auto [ps, exs] : ANS) {
		ii p = ps.F, q = ps.S;
		int sm = exs.F, its = exs.S;
		double two = 2, one = 1;
		printf("%.8lF %.8lF %.8lF %.8lF %.8lF\n", p.X / two, p.Y / two, q.X / two, q.Y / two, one * sm / its);
		// cout << p.X / 2.0 << " " << p.Y / 2.0 << " " << q.X / 2.0 << " " << q.Y / 2.0 << " " << 1.0 * sm / its << endl;
	}



	return 0;
}
