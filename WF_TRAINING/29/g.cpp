#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
 
const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e6+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
vi G[MAXN];
int cmp[MAXN];
vector<string> S;
int R, C;
 
void dfs(int v, int root) {
    if (cmp[v] != -1) return;
    cmp[v] = root;
    for (auto u : G[v]) dfs(u, root);
}
 
int neg(int i) { return i < R ? i+R : i-R;}
 
ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b&1) return a * binpow(a, b-1) % MOD;
    return binpow(a*a%MOD, b>>1);
}
 
int main() {
    int T; cin >> T;
    ms(cmp, -1);
    while (T--){
        S.clear();
 
        cin >> R >> C;
        FOR(i,0,R) { string s; cin >> s; S.pb(s); }
 
        vi cnt(C);
        FOR(i,0,R) FOR(j,0,C) cnt[j] += S[i][j] - '0';
 
        bool pos = true;
        FOR(i,0,C) if (cnt[i] + cnt[C-1-i] > 2) pos = false;
 
        if (!pos) {
            cout << 0 << endl;
            continue;
        }
 
        FOR(j,0,C) {
            FOR (i,0,R) if (S[i][j] == '1') {
                FOR(k,0,R) if (k != i && S[k][j] == '1') {
                    G[i].pb(neg(k));
                    G[neg(i)].pb(k);

                    // G[neg(k)].pb(i);
                    // G[k].pb(neg(i));

                    //printf("%d -> %d\n", i, neg(k));
                    // printf("%d -> %d\n", neg(i), k);
                    break;
                }
 
                FOR(k,0,R) if (k != i && S[k][C-1-j] == '1') {
                    G[i].pb(k);
                    G[neg(i)].pb(neg(k));

                    // G[k].pb(i);
                    // G[neg(k)].pb(neg(i));

                    // printf("%d -> %d\n", i, k);
                    // printf("%d -> %d\n", neg(i), neg(k));
                    break;
                }
            }
        }
 
        int CMP = 0;
        FOR(i,0,2*R) if (cmp[i] == -1) CMP++, dfs(i,i);
        FOR(i,0,R) if (cmp[i] == cmp[neg(i)]) pos = false;
 
        if (!pos) {
            cout << 0 << endl;
            continue;
        }

        // FOR(i,0,2*R) printf("%d ", cmp[i]);
        // printf("\n");
 
        // cout << CMP << endl;
        cout << binpow(2, CMP/2) << endl;
 
        FOR(i,0,2*R) G[i].clear(), cmp[i] = -1;
    }
 
    return 0;
}