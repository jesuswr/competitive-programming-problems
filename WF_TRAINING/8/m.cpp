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

int f(int x) {
	if (x == 0) return 1;

	int aux[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
	int res = 0;

	while(x) {
		int d = x % 10;
		x /= 10;
		res += aux[d];
	}
	return res;
}


void solve() {
	int x,k; rii(x,k);
	map<int,int> steps;
	int c = 0;

	while(k) {
		x = f(x);
		++c;
		--k;
		if (steps.find(x) != steps.end()) {
			int dff = c - steps[x];
			k = k % dff;
			if (k == 0) break;
		}
		steps[x] = c;
	}
	printf("%d\n", x);
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
