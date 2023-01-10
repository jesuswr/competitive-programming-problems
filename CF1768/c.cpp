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

void solve(){
	int n; ri(n);
	map<int, vi> q;
	FOR(i,0,n) {
		int x; ri(x);
		q[x-1].pb(i);
	}
	vi a(n), b(n);
	queue<int> fa, fb;

	for(int i = n-1; i >= 0; --i) {
		if (q[i].size() > 2) {
			printf("NO\n");
			return;
		}
		if (q[i].size() == 2 ) {
			a[q[i][0]] = i;
			fb.push(q[i][0]);
			b[q[i][1]] = i;
			fa.push(q[i][1]);
		}
		else if (q[i].size() == 1) {
			a[q[i][0]] = b[q[i][0]] = i; 
		}
		else if (!fa.empty() && !fb.empty()) {
			a[fa.front()] = i;
			b[fb.front()] = i;
			fa.pop();
			fb.pop();
		}
		else {
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
	for(int x : a) printf("%d ", x+1);
	printf("\n");
	for(int x : b) printf("%d ", x+1);
	printf("\n");
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
