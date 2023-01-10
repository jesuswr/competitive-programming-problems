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
#define ri(a) dasdas=scanf("%d\n", &a)
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

char A[30];
int G[30];

void solve(){
	dasdas = scanf("%s\n", A);
	for(int i = 0; i < 26; ++i) G[i] = A[i] - 'A';

	vi siz(30);
	vector<bool> vis(30);

	for(int u = 0; u < 26; ++u){
		if (vis[u]) continue;
		int start = u;
		int len = 0;
		while(!vis[start]) {
			++len;
			vis[start] = 1;
			start = G[start];
		}
		siz[len]++;
	}

	bool good = 1;
	for(int i = 2; i < 26; i += 2) {
		if (siz[i] & 1) good = false;
	}
	if (good) printf("Yes\n");
	else printf("No\n");
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
