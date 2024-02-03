#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

__int128 one = 1;
__int128 MX = one << 63;
vi Ps;
vector<ll> Vs;
vector<vi> Ds;
vi Ns;
void calc(int p, int pow, __int128 v = 1) {
	Vs.pb(v);
	if (p == sz(Ps)) return;
	__int128 base = Ps[p];
	FOR(i,0,pow) {
		if (v * base >= MX) break;
		calc(p+1, i+1, v * base);
		base = base * Ps[p];
	}
}

void go(int i);

void pre() {
	FOR(i,2,1000) {
		bool bad = 0;
		FOR(j,2,i) if (i % j == 0) bad = 1;
		if (!bad) Ps.pb(i);
	}
	calc(0,63);
	FOR(i,0,sz(Vs)) {
		Ns.pb(0);
		Ds.pb({});
		ll v = Vs[i];
		for(int p : Ps) {
			int cnt = 0;
			while(v % p == 0) {
				v /= p;
				cnt++;
			}
			if (cnt) Ds[i].pb(cnt);
			Ns[i] += cnt;
		}
		go(i);
	}

}

map<ll,ll> ans;
void go(int x) {
	vector<int> pow(70);
	FOR(i,2,Ns[x]+1) {
		int aux_i = i;
		FOR(j,0,70) {
			int d = Ps[j];
			while(aux_i % d == 0) {
				aux_i /= d;
				pow[j] += 1;
			}
		}
	}

 
	for(int cnt : Ds[x]) {
		FOR(i,2,cnt+1) {
			int aux_i = i;
			FOR(j,0,70) {
				int d = Ps[j];
				while(aux_i % d == 0) {
					aux_i /= d;
					pow[j] -= 1;
				}
			}
		}
	}

	__int128 comb = 1;
	FOR(i,0,70) {
		while(pow[i] && comb < MX) {
			comb *= Ps[i];
			pow[i]--;
		}
	}

	if (comb >= MX) return;
	if (ans.find(comb) == ans.end() || ans[comb] > Vs[x]) ans[comb] = Vs[x];
 }

int main(){
	pre();

	ll n;
	while(lri(n) != EOF) {
		if (n == 1) printf("1 2\n");
		else printf("%lld %lld\n", n, ans[n]);
	}

	return 0;
}
