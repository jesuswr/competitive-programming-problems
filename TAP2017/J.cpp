#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <bitset>
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
int N, M; // N es contests y M nombres
map<string, vi> inds;
map<vi, int> cnt;

vi get_op(const vi &v) {
    vi ret(SZ(v));
    FOR(i, 0, SZ(v)) ret[i] = 1 ^ v[i];
    return ret;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) {
        FOR(_, 0, M) {
            string s; cin >> s;
            inds[s].pb(i);
        }
    }

    if (SZ(inds) > 2 * M) {
        printf("N\n");
        return 0;
    }

    for (auto [_, v] : inds) {
        vi oc(N, 0);
        for (auto i : v) oc[i] = 1;
        cnt[oc]++;
    }

    vector<int> all1(N, 1);
    if (cnt.find(all1) != cnt.end()) cnt.erase(all1);

    while (!cnt.empty()) {
        vi a = cnt.begin()->F;
        vi b = get_op(a);
        if (cnt.find(b) == cnt.end()) {
            printf("N\n");
            return 0;
        }
        cnt[a]--;
        cnt[b]--;
        if (cnt[a] == 0) cnt.erase(a);
        if (cnt[b] == 0) cnt.erase(b);
    }
    printf("S\n");


    return 0;
}