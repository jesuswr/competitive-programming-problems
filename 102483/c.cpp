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
const int MAXN = 1010;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N;
vi G[MAXN];
const double DELTA = 360.0 / (3 * MAXN);
double ANG = 0;
double A[MAXN];
double X[MAXN], Y[MAXN];
const double PI = acos(0);
int cnt;

double dist(int i, int j) {
    return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
}

void dfs(int u, int f = -1) {
    if (f != -1) {
        double aux = ((1.0 * cnt) / N) * PI;
        X[u] = X[f] + cos(aux);
        Y[u] = Y[f] + sin(aux);
        ++cnt;
    }
    for (auto v : G[u]) if (v != f) {
            dfs(v, u);
        }
}


int main() {
    ri(N);
    FOR(_, 1, N) {
        int a, b; rii(a, b);
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    dfs(0);
    double mn = 10;
    FOR(i, 0, N) FOR(j, i + 1, N) mn = min(mn, dist(i, j));
    assert(mn >= 1e-4);
    FOR(i, 0, N) printf("%.13lF %.13lF\n", X[i], Y[i]);
    return 0;
}
