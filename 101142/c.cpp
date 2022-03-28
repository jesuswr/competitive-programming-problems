#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N;
int X[MAXN], Y[MAXN];
vi G[MAXN];
vi GR[MAXN];

stack<int> st;
bool VIS[MAXN];
int CMP[MAXN];
int SZ[MAXN];
int ANS[MAXN];
void dfs(int u) {
    VIS[u] = 1;
    for (int v : G[u]) {
        if (VIS[v]) continue;
        dfs(v);
    }
    st.push(u);
}
void dfsr(int u, int c) {
    VIS[u] = 1;
    CMP[u] = c;
    SZ[c] += 1;
    for (int v : GR[u]) {
        if (VIS[v]) continue;
        dfsr(v, c);
    }
}
vi scc() {
    FOR(i, 0, N) if (!VIS[i]) dfs(i);
    FOR(i, 0, N) VIS[i] = 0;
    vi ret;
    int cc = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (VIS[u]) continue;
        dfsr(u, cc);
        ret.pb(cc++);
    }
    return ret;
}


int main() {
    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);
    ri(N);
    FOR(i, 0, N) rii(X[i], Y[i]);
    vi ord(N);
    FOR(i, 0, N) ord[i] = i;
    sort(all(ord), [](int i, int j) {
        return X[i] < X[j];
    });
    FOR(i, 1, N) G[ord[i - 1]].pb(ord[i]), GR[ord[i]].pb(ord[i - 1]);
    sort(all(ord), [](int i, int j) {
        return Y[i] < Y[j];
    });
    FOR(i, 1, N) G[ord[i - 1]].pb(ord[i]), GR[ord[i]].pb(ord[i - 1]);
    vi o = scc();
    int cnt = 0;
    for(int c : o){
        cnt += SZ[c];
        ANS[c] = cnt;
    }
    FOR(i,0,N) printf("%d\n", ANS[CMP[i]] - 1);
    return 0;
}
