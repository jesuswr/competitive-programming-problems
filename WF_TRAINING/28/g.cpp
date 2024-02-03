#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); }

stack<int> ord;

struct ACfixed{
	static const int ASZ = 26;
	struct node {array<int,ASZ> to; int link; int out; bool leaf = false; int cnt=0;};
	vector<node> d = {{}};
	int add(string s) {
		int v = 0;
		for (auto C : s) {
			int c = C - 'A';
			if (!d[v].to[c]) d[v].to[c] = sz(d), d.emplace_back();
			v=d[v].to[c];
		}
		d[v].leaf = true;
		return v;		
	}
	void init() {
		d[0].link = -1;
		d[0].out = -1;
		queue<int> q; q.push(0);
		while(sz(q)) {
			int v = q.front(); q.pop();
			ord.push(v);
			FOR(c,0,ASZ) {
				int u = d[v].to[c]; if (!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
				q.push(u);
			}
			if (v) FOR(c,0,ASZ) if (!d[v].to[c])
				d[v].to[c] = d[d[v].link].to[c];
			if (v) {
				if (d[d[v].link].leaf) d[v].out = d[v].link;
				else d[v].out = d[d[v].link].out;
			}
		}
	}
};


int N,Q;
char C[MAXN]; int F[MAXN];
int IND[MAXN];
int P[MAXN];


int main() {
	ACfixed aho;
	das = scanf("%d %d\n", &N, &Q);
	FOR(i,1,N+1) das=scanf("%c %d\n", C+i, F+i);
	FOR(i,0,Q) {
		string s; cin >> s; reverse(all(s));
		IND[i] = aho.add(s);
	}
	aho.init();
	FOR(i,1,N+1) {
		int p = P[F[i]];
		p = aho.d[p].to[C[i] - 'A'];
		aho.d[p].cnt++;
		P[i] = p;
	}
	while(!ord.empty()) {
		int u = ord.top(); ord.pop();
		if (!u) continue;
		aho.d[ aho.d[ u ].link ].cnt += aho.d[u].cnt;
	}
	FOR(i,0,Q) printf("%d\n", aho.d[IND[i]].cnt);
	return 0;
}
