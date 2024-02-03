#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const int LOGN = 20;

void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
}

__int128 bin2dec(__int128 x) {
	__int128 ret = 0;
	ROF(i,LOGN-1,-1) {
		ret *= 10;
		ret += ((x >> i) & 1);
	}

	return ret;
}

bool check(__int128 x) {
	__int128 y = bin2dec(x);

	return (x&y) == x;
}

vi v;

int main() {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	int n; 

	FOR(i,0,1<<LOGN) {
		if (check(i)) v.pb(i);
		// if (sz(v) > n) break;
	}
	
	while(ri(n) != EOF) {
		int ans = v[n];

		bool p = false;
		ROF(i,LOGN-1,-1) {
			if (p || ((ans>>i)&1)) printf("%d", (ans>>i)&1), p = true;
		}
		printf("\n");
	}


	


	return 0;
}
