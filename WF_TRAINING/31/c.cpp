#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
string S;

struct PalTree {
    static const int ASZ = 10;
    struct node {
        array<int, ASZ> to = array<int, ASZ>();
        int len, link, oc = 0; // # occurrences of pal
        int slink = 0, diff = 0;
        array<int, 2> seriesAns;
        node(int _len, int _link) : len(_len), link(_link) {}
    };
    string s = "@"; vector<array<int, 2>> ans = {{0, INF}};
    vector<node> d = {{0, 1}, { -1, 0}}; // dummy pals of len 0,-1
    int last = 1;
    int getLink(int v) {
        while (s[sz(s) - d[v].len - 2] != s.back()) v = d[v].link;
        return v;
    }
    void addChar(char C, int x) {
        s += C; int c = C - '0'; last = getLink(last);
        if (!d[last].to[c]) {
            d.emplace_back(d[last].len + 2, d[getLink(d[last].link)].to[c]);
            d[last].to[c] = sz(d) - 1;
        } 
        last = d[last].to[c]; d[last].oc += x;
    }
    void numOc() { for (int i = sz(d) - 1; i >= 2; --i) d[d[i].link].oc += d[i].oc; }
	int solve() {
		int sm = 0;
		for(int i = sz(d) - 1; i >= 2; --i) {
			if (d[i].len > N) continue;
			int oc = 1ll * d[i].oc * d[i].oc % MOD;
			int val = 1ll * d[i].len * oc % MOD;
			sm += val;
			if (sm >= MOD) sm -= MOD;
		}
		return sm;
	}
};

PalTree pt[2];

int main(){
	ri(N);
	cin >> S;
	PalTree p;
	for(auto c : S) p.addChar(c,0); 
	for(auto c : S) p.addChar(c,1); 
	// p.last = 1;
	// for(auto c : S) p.addChar(c,-1);
	p.numOc();
	cout << p.solve() << endl;

	return 0;
}
