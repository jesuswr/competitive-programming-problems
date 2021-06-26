#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, Q;

map<string, int> STR_TO_I;
int T;
map<int, string> I_TO_STR;

vi G[MAXN];
bool NOT_ROOT[MAXN];


const int LOGN = 23;
int ANC[MAXN][23], H[MAXN], IN[MAXN], OUT[MAXN], TT;
void dfs(int u, int f) {
    ANC[u][0] = f;
    IN[u] = TT++;
    for (int l = 1; l < LOGN; l++)
        ANC[u][l] = ANC[ ANC[u][l - 1] ][l - 1];
    for (auto v : G[u]) {
        H[v] = H[u] + 1;
        dfs(v, u);
    }
    OUT[u] = TT++;
}

bool is_anc(int u, int v) {
    return IN[u] <= IN[v] && OUT[v] <= OUT[u];
}

int lca(int u, int v) {
    if (is_anc(u, v))
        return u;
    if (is_anc(v, u))
        return v;

    for (int l = LOGN - 1; l >= 0; --l) {
        if (!is_anc(ANC[u][l], v))
            u = ANC[u][l];
    }
    return ANC[u][0];
}

string basura(int x) {
    if (x == 11 || x == 12 || x == 13)
        return "th";
    if (x % 10 == 1) return "st";
    if (x % 10 == 2) return "nd";
    if (x % 10 == 3) return "rd";
    return "th";
}

void solve(int a, int b) {
    int c = lca(a, b);
    int m = H[a] - H[c], n = H[b] - H[c];
    //cout << I_TO_STR[a] << " : " << H[a] ;
    //cout << I_TO_STR[b] << " : " << H[b] ;
    //cout << I_TO_STR[c] << " : " << H[c] ;
    if (m > n) {
        swap(a, b);
        swap(m, n);
    }

    if (m == 0) {
        if (n == 1) {
            cout << I_TO_STR[b] << " is the child of " << I_TO_STR[a] ;
        }
        else {
            cout << I_TO_STR[b] << " is the ";
            FOR(i, 0, n - 2) cout << "great ";
            cout << "grandchild of " << I_TO_STR[a] ;
        }
    }
    else if (m == n) {
        if (n == 1) {
            cout << I_TO_STR[a] << " and " << I_TO_STR[b] << " are siblings" ;
        }
        else {
            cout << I_TO_STR[a] << " and " << I_TO_STR[b] << " are " << n - 1 << basura(n - 1) << " cousins" ;
        }
    }
    else {
        if (n - m > 1)
            cout << I_TO_STR[a] << " and " << I_TO_STR[b] << " are " << m - 1 << basura(m - 1) << " cousins, " << n - m << " times removed" ;
        else
            cout << I_TO_STR[a] << " and " << I_TO_STR[b] << " are " << m - 1 << basura(m - 1) << " cousins, " << n - m << " time removed" ;
    }
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) {
        string a, b;
        int m;
        cin >> a >> m;
        if (STR_TO_I.find(a) == STR_TO_I.end()) {
            I_TO_STR[T] = a;
            STR_TO_I[a] = T++;
        }

        int ai = STR_TO_I[a];
        FOR(j, 0, m) {
            cin >> b;
            if (STR_TO_I.find(b) == STR_TO_I.end()) {
                I_TO_STR[T] = b;
                STR_TO_I[b] = T++;
            }
            int bi = STR_TO_I[b];
            G[ai].pb(bi);
            NOT_ROOT[bi] = true;
        }
    }

    int root = 0;
    FOR(i, 0, T) if (!NOT_ROOT[i]) root = i;
    dfs(root, root);

    while (Q--) {
        string a, b;
        cin >> a >> b;
        solve(STR_TO_I[a], STR_TO_I[b]);
        cout << endl;
    }

    return 0;
}