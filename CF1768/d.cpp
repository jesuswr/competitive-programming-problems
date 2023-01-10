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


int father[MAXN], siz[MAXN], sz[MAXN];
void makeSet(int n, int m){
	for (int i = n; i <= m; ++i){
		father[i] = -1;
		siz[i] = 0;
		sz[i] = 1;
	}
}
int find(int x){
	if (father[x]==-1)  return x;
	return father[x] = find(father[x]);
}
void unio(int x, int y){ 
	if (siz[x] > siz[y]) {
		father[y] = x;
		sz[x]  += sz[y];
	}
	else{
		father[x] = y;
		sz[y]  += sz[x];
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}


void solve() {
	int n; ri(n);
	vi a(n);
	FOR(i,0,n) {
		ri(a[i]);
		--a[i];
	}
	makeSet(0,n-1);
	int ans = INF; 
	int cnt = 0;
	FOR(i,0,n) {
		if (find(i) != find(a[i])) {
			unio(find(i), find(a[i]));
		}
	}

	FOR(i,0,n) if (i == find(i)) {
		cnt += sz[i] - 1;
	}

	FOR(i,1,n) {
		if (find(i) != find(i-1)) {
			// int minus = a[i] == i-1 || a[i-1] == i;
			ans = min(ans, cnt + 1);
		} else {
			int minus = a[i] == i-1 || a[i-1] == i;
			ans = min(ans, cnt - 1);
		}
	}
	cout << ans << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();

	return 0;
}
