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
const int MAXN = 1010;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
int IN[MAXN];
int C[MAXN];
vi G[MAXN];


int go(int a, int b) {
	bitset<MAXN> V;
	queue<int> q;
	q.push(a);
	q.push(b);
	V[a] = V[b] = 1;
	int sm = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		sm += C[x];
		for(int y : G[x]) {
			if (V[y]) continue;
			q.push(y);
			V[y] = 1;
		}
	}
	return sm;
}


int main(){	
	rii(N, M);
	FOR(i,0,N) ri(C[i]);
	FOR(_,0,M) {
		int a, b; rii(a,b); --a; --b;
		G[b].pb(a);
		IN[a]++;
	}
	int ans = 1e8;
	FOR(a,0,N) if (IN[a] == 0) {
		FOR(b,a+1,N) if (IN[b] == 0) {
			ans = min(ans, go(a,b));
		}
	}
	cout << ans << endl;
	return 0;
}
