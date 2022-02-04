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
#include <random>
#include <chrono>

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
const int MAXN = 410; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
string T;
int N;
string S[MAXN];

bool is_pal(int l, int r) {
    while (l < r) {
        if (T[l] == T[r]) {
            ++l;
            --r;
        }
        else
            return false;
    }
    return true;
}

bool kmp(string s, int m) {
    int n = SZ(s);
    vi pi(n);
    bool fnd = false;
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = j + 1;
        fnd |= s[i] == '$';
        if (fnd && pi[i] == m)
            return true;
    }
    return false;
}



// A from 1 to A
// B from A+1 to A+B < MAXN
vi G[MAXN]; // edges A->B  //clear G for several test cases
int A, B, match[MAXN], dist[MAXN];
bool bfs() {
    queue<int> q;
    FOR(i, 1, A + 1) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        } else dist[i] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v != 0) {
            FOR(i, 0, SZ(G[v])) {
                int u = G[v][i];
                if (dist[match[u]] == INF) {
                    dist[match[u]] = dist[v] + 1;
                    q.push(match[u]);
                }
            }
        }
    }
    return (dist[0] != INF);
}
bool dfs(int v) {
    if (v != 0) {
        FOR(i, 0, SZ(G[v])) {
            int u = G[v][i];
            if (dist[match[u]] == dist[v] + 1) {
                if (dfs(match[u])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        dist[v] = INF;
        return false;
    }
    return true;
}
int HK() {
    memset(match, 0, sizeof(match));
    int MBM = 0;
    while (bfs())
        FOR(i, 1, A + 1)
        if (match[i] == 0 && dfs(i))
            MBM++;
    return MBM;
}


int main() {
    cin >> T;
    for (int i = 0; i < SZ(T); ++i) {
        int len = 1;
        for (int j = 2; j <= i + 1; ++j) {
            if (is_pal(i - j + 1, i)) {
                len = j;
            }
        }

        string sub = T.substr(i - len + 1, len);
        bool add = 1;
        FOR(j, 0, N) if (S[j] == sub) {
            add = 0;
            break;
        }
        if (add) {
            S[N] = sub;
            N++;
        }
    }
    sort(S, S + N, [](const string & a, const string & b) {
        return a.size() < b.size();
    });

    A = B = N;
    // FOR(i, 0, N) cout << S[i] << endl;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (SZ(S[i]) != SZ(S[j]) && kmp(S[j] + '$' + S[i], SZ(S[j]))) {
                G[j + 1].pb(i + 1 + N);
                // cout << S[j] << " -> " << S[i] << endl;
            }
        }
    }

    int mtch = HK();
    int cnt = 0;
    FOR(i, 1, N + 1) cnt += match[i] == 0;
    printf("%d\n", N - mtch);



    return 0;
}



// nfmxysillrofnhqnwqrqkpksauxefojcmbgaafylqlvymokzsiskmgoevxhssxutdmfyopukonfevdnaicxkmkimziivhewhlkgpeovtabyjnkzerfmfvbbjgxmithckvgqlrkacpfifujenfditgnjgeogrivnjikdmuyvigrzoogpifzouptwhnhrqatsjitjiqpul