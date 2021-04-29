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

using namespace std;

typedef long long ll;
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
struct ACfixed { // fixed alphabet
    static const int ASZ = 10;
    struct node { array<int, ASZ> to; int link; bool leaf = false;};
    vector<node> d = {{}};
    int add(const string &s) { // add word
        int v = 0;
        for (auto C : s) {
            int c = C - '0';
            if (!d[v].to[c]) d[v].to[c] = SZ(d), d.emplace_back();
            v = d[v].to[c];
        }
        d[v].leaf = true;
        return v;
    }
    void init() { // generate links
        d[0].link = -1;
        queue<int> q; q.push(0);
        while (SZ(q)) {
            int v = q.front(); q.pop();
            FOR(c, 0, ASZ) {
                int u = d[v].to[c]; if (!u) continue;
                d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
                q.push(u);
            }
            if (v) FOR(c, 0, ASZ) if (!d[v].to[c])
                    d[v].to[c] = d[d[v].link].to[c];
            if (v)
                d[v].leaf |= d[d[v].link].leaf;
        }
    }
};

ll L, R, K, N;
ACfixed AHO;

int NA;
vi A;
ll DP[20][1200][3][2];
ll f(int p, int ahop, int c, int v) {
    if (DP[p][ahop][c][v] != -1) return DP[p][ahop][c][v];
    ll &ret = DP[p][ahop][c][v];
    if (p == NA) return ret = 0;


    ret = 0;
    if (c == 0) { // lower than A[0..p-1]
        FOR(i, 0, 10) {
            int nxt = AHO.d[ahop].to[i];
            int newv = v | AHO.d[nxt].leaf;
            if (newv)
                ret++;
            ret += f(p + 1, nxt, 0, newv);
        }
    }
    else if (c == 1) { // same than A[0..p-1]
        FOR(i, p == 0, 10) {
            int nxt = AHO.d[ahop].to[i];
            int newv = v | AHO.d[nxt].leaf;
            if (newv && (p + 1 < NA || i <= A[p]))
                ret++;
            if (i < A[p])
                ret += f(p + 1, nxt, 0, newv);
            else if (i == A[p])
                ret += f(p + 1, nxt, 1, newv);
            else
                ret += f(p + 1, nxt, 2, newv);
        }
    }
    else { // higher than A[0..p-1]
        FOR(i, 0, 10) {
            int nxt = AHO.d[ahop].to[i];
            int newv = v | AHO.d[nxt].leaf;
            if (newv && p + 1 < NA)
                ret++;
            ret += f(p + 1, nxt, 2, newv);
        }
    }
    return ret;
}

bool valid(ll x) {
    memset(DP, -1, sizeof(DP));
    A.clear();
    while (x > 0) {
        A.pb(x % 10);
        x /= 10;
    }
    reverse(ALL(A));
    NA = SZ(A);
    ll hicnt = f(0, 0, 1, 0);

    memset(DP, -1, sizeof(DP));
    A.clear();
    x = L;
    while (x > 0) {
        A.pb(x % 10);
        x /= 10;
    }
    reverse(ALL(A));
    NA = SZ(A);
    ll locnt = f(0, 0, 1, 0);

    return (hicnt - locnt >= K);
}

int main() {
    rll(L, R), rll(K, N); --L;
    FOR(_, 0, N) {
        string s; cin >> s;
        AHO.add(s);
    }
    AHO.init();

    if (!valid(R)) {
        printf("no such number\n");
        return 0;
    }

    ll lo = L + 1, hi = R;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (valid(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    printf("%lld\n", lo);
    return 0;
}