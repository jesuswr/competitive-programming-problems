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

ll query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	ll x; lri(x);
	return x;
}

int main() {
	FOR(i, 2, 6969) {
		ll q1 = query(i, i + 1), q2 = query(i + 1, i);
		if (q1 == -1) {
			printf("! %d", i);
			break;
		}
		if (q1 != q2) {
			printf("! %lld", q1 + q2);
			break;
		}
	}
	cout << endl;


	return 0;
}