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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
const int ALPHA = 26;

// GJNM
int n;
string s;
bool removed[MAXN];

vi oc[ALPHA];
set<int> inds[ALPHA];
vi rem_oc[ALPHA];

vi query(int i, int j) {
    vi ret(ALPHA);
    FOR(k, 0, ALPHA) {
        ret[k] = ub(ALL(oc[k]), j) - lb(ALL(oc[k]), i);
        ret[k] -= (ub(ALL(rem_oc[k]), j) - lb(ALL(rem_oc[k]), i));
    }
    return ret;
}

int find_nxt(int i) {
    int c = s[i] - 'a';
    int ret = INF;
    FOR(j, c + 1, ALPHA) {
        auto it = inds[j].lb(i);
        if (it != inds[j].end())
            ret = min(ret, *it);
    }
    return ret;
}

void solve() {
    cin >> s;
    n = SZ(s);
    FOR(i, 0, ALPHA) oc[i].clear();
    FOR(i, 0, ALPHA) inds[i].clear();
    FOR(i, 0, ALPHA) rem_oc[i].clear();
    FOR(i, 0, n) {
        oc[s[i] - 'a'].pb(i);
        inds[s[i] - 'a'].insert(i);
        removed[i] = false;
    }

    vi cnt = query(0, n - 1);

    FOR(i, 0, n) {
        if (removed[i]) continue;

        int nxt = find_nxt(i);
        if (nxt == INF) {
            for (auto j : oc[s[i] - 'a']) {
                if (j != i) {
                    if (removed[j]) continue;
                    rem_oc[s[i] - 'a'].pb(j);
                    inds[s[i] - 'a'].erase(j);
                    removed[j] = true;
                    --cnt[s[j] - 'a'];
                }
            }
            continue;
        }


        vi subcnt = query(i, nxt - 1);

        bool rem = true;
        FOR(j, 0, ALPHA) {
            if (subcnt[j] > 0 && subcnt[j] == cnt[j])
                rem = false;
        }

        if (rem) {
            FOR(j, i, nxt) {
                if (removed[j]) continue;
                --cnt[s[j] - 'a'];
                inds[s[j] - 'a'].erase(j);
                rem_oc[s[j] - 'a'].push_back(j);
                removed[j] = true;
            }
        }
        else {
            for (auto j : oc[s[i] - 'a']) {
                if (j != i) {
                    if (removed[j]) continue;
                    rem_oc[s[i] - 'a'].pb(j);
                    inds[s[i] - 'a'].erase(j);
                    removed[j] = true;
                    --cnt[s[j] - 'a'];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (removed[i]) continue;
        if (cnt[s[i] - 'a'] > 1) {
            cnt[s[i] - 'a']--;
            removed[i] = true;
        }
    }

    FOR(i, 0, n) if (!removed[i]) printf("%c", s[i]);
    printf("\n");
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}