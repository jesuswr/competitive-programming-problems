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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
int L[MAXN];
int D[MAXN];
vi Lis[MAXN];
int Dis[MAXN];
int suf_cnt[MAXN]; // number of sticks
int suf_sum[MAXN]; // sum of ls


int main() {
    ri(N);
    FOR(i, 0, N) ri(L[i]);
    FOR(i, 0, N) ri(D[i]);
    FOR(i, 0, N) Lis[L[i]].pb(i);
    FOR(i, 0, N) suf_cnt[L[i]]++;
    FOR(i, 0, N) suf_sum[L[i]] += D[i];
    ROF(i, 100000, -1) suf_cnt[i] += suf_cnt[i + 1];
    ROF(i, 100000, -1) suf_sum[i] += suf_sum[i + 1];

    int ans = 1e8;
    for (int l = 1; l < MAXN; l++) {
        if (Lis[l].empty()) continue;

        int sz = min(2 * SZ(Lis[l]) - 1, N);
        int need_erase = N - sz;

        int cnt = suf_sum[l + 1];
        need_erase = max(need_erase - suf_cnt[l + 1], 0);

        FOR(c, 1, 201) {
            cnt += min(need_erase, Dis[c]) * c;
            need_erase -= min(need_erase, Dis[c]);
        }
        ans = min(ans, cnt);

        for (auto i : Lis[l]) Dis[D[i]]++;
    }



    printf("%d\n", ans);

    return 0;
}