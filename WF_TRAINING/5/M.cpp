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
const int MAXN = 52;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct ACfixed { // fixed alphabet
    static const int ASZ = 52;
    struct node { array<int, ASZ> to; int link; int out; bool leaf = false; int h;};
    vector<node> d = {{}};
    int add(string s) { // add word
        int v = 0;
		int hei = 0;
        for (auto C : s) {
            // if ((int)C >= 97) C -= 6; // por si es [A..Z] + [a..z]
            int c = C - 'A';
            if (!d[v].to[c]) d[v].to[c] = sz(d), d.emplace_back();
            v = d[v].to[c];
			d[v].h = ++hei;
        }
        d[v].leaf = true;
        return v;
    }
    void init() { // generate links
        d[0].link = -1;
        d[0].out = -1;
        queue<int> q; q.push(0);
        while (sz(q)) {
            int v = q.front(); q.pop();
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (v) {
                if (d[d[v].link].leaf) d[v].out = d[v].link;
                else d[v].out = d[d[v].link].out;
            }
        }
    }
};

int N, M, K;
char A[MAXN][MAXN];
ACfixed aho;
vii MVs = {{1,0}, {0,1}, {0, -1}, {-1, 0}}; // just use first 3

bool bad(int r, int c) {
	return !(min(r,c) >= 0 && r < N && c < M);
}
int op(int x) {
	if (x == 1) return 2;
	if (x == 2) return 1;
	return  3;
}

int DP[MAXN][MAXN][MAXN*MAXN][4];
int f(int r, int c, int e, int p = 3) {
	// cout << r << " " << c << " " << e << endl;
	int &ret = DP[r][c][e][p];
	if (ret != -1) return ret;
	if (r == N - 1) {
		if (aho.d[e].leaf) return ret = 1;
	}
	ret = INF;
	FOR(i,0,3) if (i != p) {
		int nr = r + MVs[i].F, nc = c + MVs[i].S;
		if (bad(nr, nc)) continue;
		int nxt = A[nr][nc] - 'A';
		int ne = aho.d[e].to[ nxt ];
		// cout << "\t" << nr << " " << nc << " " << ne << endl;
		if (aho.d[ne].h <= aho.d[e].h) continue;
		ret = min(ret, 1 + f(nr, nc, ne, op(i)));
		if (aho.d[ne].leaf) ret = min(ret, 1 + f(nr, nc, 0, op(i)));
	}
	return ret;
}

int main(){
	// fastIO();
	rii(N,M), ri(K);
	FOR(i,0,N) FOR(j,0,M) cin >> A[i][j];
	FOR(i,0,K) {
		string s; cin >> s;
		aho.add(s);
	}
	aho.init();
	ms(DP,-1);
	int ans = INF;
	FOR(c,0,M) {
		int nxt = A[0][c] - 'A';
		int ne = aho.d[0].to[ nxt ];
		if (aho.d[ne].h > 0) {
			ans = min(ans, f(0, c, ne));
			if (aho.d[ne].leaf) ans = min(ans, f(0, c, 0));
		}
	}
	if (ans >= INF) cout << "impossible" << endl;
	else cout << ans << endl;
	return 0;
}
