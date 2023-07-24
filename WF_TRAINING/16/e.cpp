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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q;
int T[MAXN], K[MAXN];


int main(){
	freopen("expect.in", "r", stdin); // redirects standard input
    freopen("expect.out", "w", stdout); // redirects standard output
	das = scanf("%d %d\n", &N, &Q);
	FOR(i,0,N) {
		char c;
		das = scanf("%c %d %d\n", &c, T+i, K+i);
		if (c == '-') K[i] = -K[i];
	}


	vector< ii > SEGS;
	int acum = 0;
	ll area = 0;
	int curr_h = 0;
	int curr_len = 0;
	FOR(i,0,N) {
		acum += K[i];
		if (i + 1 < N) {
			int len = T[i+1] - T[i];
			if (acum < 0) {
				SEGS.pb({-acum, len});
				curr_len += len;
				area -= 1ll * len * acum;
			}
		}
	}
	sort(all(SEGS));

	vector< ii > Qs;
	FOR(i,0,Q) {
		int h; ri(h);
		Qs.pb({h,i});
	}
	sort(all(Qs));

	vector<ll> ANS(Q);
	int j = 0;
	for(auto [qh, qi] : Qs) {
		while(j < sz(SEGS) && qh >= SEGS[j].F) {
			int len = 0;
			int h = SEGS[j].F;
			while(j < sz(SEGS) && h == SEGS[j].F) {
				len += SEGS[j].S;
				j += 1;
			}
			area -= 1ll * (h - curr_h) * curr_len;
			curr_len -= len;
			curr_h = h;
		}


		if (qh < -acum) ANS[qi] = -1;
		else {
			area -= 1ll * (qh - curr_h) * curr_len;
			curr_h = qh;
			ANS[qi] = area;
		}
	}

	FOR(i,0,Q) {
		if (ANS[i] == -1) printf("INFINITY\n");
		else printf("%lld\n", ANS[i]);
	}

	return 0;
}
