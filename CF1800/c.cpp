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
const ll MOD = 999999929;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct Hash {
    int P=1777771,MOD[2],PI[2];
    vector<int> h[2],pi[2], pp[2];
    Hash(string& s){
        MOD[0]=999727999;MOD[1]=1070777777;
        PI[0]=325255434;PI[1]=10018302; // inversa de P en MOD0 y MOD1
        FOR(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1),pp[k].resize(s.size()+1);
        FOR(k,0,2){
            h[k][0]=0;pi[k][0]=1;pp[k][0] = 1;
            ll p=1;
            FOR(i,1,s.size()+1){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
                p=(p*P)%MOD[k];
                pp[k][i] = p;
            }
        }
    }
    ll get(int s, int e, int x){ // [s,e)
        ll h0=(h[x][e]-h[x][s]+MOD[x])%MOD[x];
        h0=(1LL*h0*pi[x][s])%MOD[x];
        return h0;
    }
    ll get(int s1, int e1, int s2, int e2) {
        ll hsh0 = 0;
        if (e1 > s1) hsh0 = get(s1, e1, 0);
        if (s2 < e2) hsh0 = (hsh0 + 1ll * pp[0][e1 - s1] * get(s2, e2, 0)) % MOD[0];
        ll hsh1 = 0;
        if (e1 > s1) hsh1 = get(s1, e1, 1);
        if (s2 < e2) hsh1 = (hsh1 + 1ll * pp[1][e1 - s1] * get(s2, e2, 1)) % MOD[1];
        return (hsh0 << 32) | hsh1;
    }

};


void solve() {
    int n; ri(n);
    string s; cin >> s;
    set<ll> hshs;
    Hash h(s);
    FOR(i,0,n-1) hshs.insert(h.get(0,i,i+2,n));
    cout << sz(hshs) << endl;
}


int main(){
	int t; ri(t);
	while(t--) {
        solve();
	}
	return 0;
}
