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

void NO() {
    printf("NO\n");
    exit(0);
}

int V, E;
vi G[MAXN];
int DEG[MAXN];
vector<tuple<int, int, int>> EDG;

bool VIS[MAXN], COL[MAXN];
void col(int u) {
    VIS[u] = 1;
    for (auto v : G[u]) {
        if (VIS[v] && COL[v] == COL[u]) NO();
        else if (!VIS[v]) {
            COL[v] = COL[u] ^ 1;
            col(v);
        }
    }
}

int main() {
    rii(V, E);
    EDG.resize(E);
    FOR(i, 0, E) {
        int t, a, b; rii(t, a); ri(b); --t; --a; --b;
        G[a].pb(b);
        G[b].pb(a);
        EDG[i] = {t, a, b};
    }
    FOR(i, 0, V) if (!VIS[i]) col(i);
    FOR(i, 0, V) G[i].clear();
    for (auto [t, a, b] : EDG) {
        if (COL[a]) swap(a, b);
        if (t == 0) {
            G[a].pb(b);
            DEG[b]++;
        }
        else {
            G[b].pb(a);
            DEG[a]++;
        }
    }
    queue<int> ord;
    FOR(i, 0, V) if (DEG[i] == 0) ord.push(i);

    vi ans(V);
    FOR(i, 0, V) {
        if (ord.empty()) NO();
        int u = ord.front(); ord.pop();
        ans[u] = i;
        for (auto v : G[u]) {
            DEG[v]--;
            if (DEG[v] == 0) ord.push(v);
        }
    }
    printf("YES\n");
    FOR(i, 0, V) printf("%c %d\n", COL[i] ? 'R' : 'L', ans[i]);

    return 0;
}
