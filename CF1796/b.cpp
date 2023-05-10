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


void solve() {
	string a, b;
	cin >> a >> b;

	if (a[0] == b[0]) {
		cout << "YES" << endl;
		cout << a[0] << '*' << endl;
		return;
	}
	if (a.back() == b.back()) {
		cout << "YES" << endl;
		cout << '*' << a.back() << endl;
		return;
	}

	for(int i = 0; i + 1 < sz(a); ++i) {
		for(int j = 0; j + 1 < sz(b); ++j) {
			if (a[i] == b[j] && a[i+1] == b[j+1]) {
				cout << "YES" << endl;
				cout << '*' << a[i] << a[i+1] << '*' << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
