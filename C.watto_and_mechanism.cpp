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
const int MAXN = 6e5 + 10; // CAMBIAR ESTE
const ll mod[2] = {999727999, (ll)1e9 + 7};

// GJNM
int n, m;
set<pii> hashes;
int cnt[MAXN];

ll aux[2][MAXN];
pii get_hash(string &s) {
    ll p[2] = {1, 1};
    ll ret[2] = {0, 0};
    FOR(i, 0, SZ(s)) {
        FOR(j, 0, 2) {
            aux[j][i] = (s[i] * p[j]);
            if (aux[j][i] >= mod[j])
                aux[j][i] %= mod[j];
            p[j] = (p[j] * 491);
            if (p[j] >= mod[j])
                p[j] %= mod[j];
            ret[j] = (ret[j] + aux[j][i]);
            if (ret[j] >= mod[j])
                ret[j] -= mod[j];
        }
    }
    return {ret[0], ret[1]};
}

bool test(string &s) {
    pii h = get_hash(s);
    ll p[2] = {1, 1};
    FOR(i, 0, SZ(s)) {
        pair<ll, ll> hs[3];
        for (char c = 'a'; c <= 'c'; c++) {
            if (c == s[i])
                continue;
            hs[c - 'a'].F = (h.F - aux[0][i] + c * p[0] + mod[0]) ;
            if (hs[c - 'a'].F >= mod[0])
                hs[c - 'a'].F %= mod[0];
            hs[c - 'a'].S = (h.S - aux[1][i] + c * p[1] + mod[1]) ;
            if (hs[c - 'a'].S >= mod[1])
                hs[c - 'a'].S %= mod[1];
            if (hashes.count(hs[c - 'a']))
                return true;
        }
        p[0] = (p[0] * 491);
        if (p[0] >= mod[0])
            p[0] %= mod[0];
        p[1] = (p[1] * 491);
        if (p[1] >= mod[1])
            p[1] %= mod[1];

    }
    return false;
}


int main() {
    rii(n, m);
    FOR(i, 0, n) {
        string s; cin >> s;
        hashes.insert(get_hash(s));
        cnt[SZ(s)]++;
    }
    FOR(i, 0, m) {
        string s; cin >> s;
        if (cnt[SZ(s)] > 0 && test(s))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}