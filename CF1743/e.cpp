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
const int MAXN = 5010;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll P[2], T[2];
ll H, S;

ll DP[MAXN];

int main() {
	lrii(P[0], T[0]);
	lrii(P[1], T[1]);
	lrii(H, S);

	for (int h = 1; h <= H; ++h) {
		DP[h] = INFLL;
		ll d[2] = {0, 0};
		ll t[2] = {T[0], T[1]};
		ll tm = 0;
		FOR(_, 0, H) {
			DP[h] = min(
			            DP[h],
			            tm + max(t[0], t[1]) + DP[ max(0ll, h - (P[0] + P[1] - S) - d[0] * (P[0] - S) - d[1] * (P[1] - S)  ) ]
			        );

			if (t[0] == t[1]) break;
			if (t[0] < t[1]) {
				tm += t[0];
				t[1] -= t[0];
				t[0] = T[0];
				d[0]++;

				int rem_h = max(
				                0ll,
				                h - d[0] * (P[0] - S) - d[1] * (P[1] - S)
				            );
				if (rem_h == 0) {
					DP[h] = min(DP[h], tm);
					break;
				}
			}
			else {
				tm += t[1];
				t[0] -= t[1];
				t[1] = T[1];
				d[1]++;

				int rem_h = max(
				                0ll,
				                h - d[0] * (P[0] - S) - d[1] * (P[1] - S)
				            );
				if (rem_h == 0) {
					DP[h] = min(DP[h], tm);
					break;
				}
			}
		}
	}

	printf("%lld\n", DP[H]);
	return 0;
}