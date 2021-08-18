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
const ll LLINF = 1e16;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
string N;
int K;

int count_bits(int k) {
    int cnt = 0;
    while (k > 0) {
        cnt += k & 1;
        k >>= 1;
    }
    return cnt;
}

ll go(vector<bool> digits) {
    // FOR(i, 0, 10) printf("%d ", (int)digits[i]);
    // printf("\n");
    bool cover_all = true;
    for (auto d : N) cover_all &= digits[d - '0'];
    if (cover_all)
        return stol(N);

    int smallest = 69;
    FOR(i, 0, 10) if (digits[i]) smallest = min(smallest, i);

    vi nxt(12, 69);
    FOR(i, 0, 10) if (digits[i]) nxt[i] = i;
    for (int i = 8; i >= 0; --i) nxt[i] = min(nxt[i], nxt[i + 1]);

    ll ans = LLINF;
    FOR(mid, 0, SZ(N)) {
        ll act = 0;
        bool put = true;
        FOR(l, 0, mid) {
            put = false;
            if (l == 0 && nxt[max(N[0] - '0', 1)] != 69) {
                act = 10 * act + nxt[max(N[0] - '0', 1)];
                put = true;
            }
            else if (nxt[N[l] - '0'] != 69) {
                act = 10 * act + nxt[N[l] - '0'];
                put = true;
            }

            if (!put)
                break;
        }
        if (!put)
            continue;
        put = false;
        if (nxt[N[mid] - '0' + 1] != 69) {
            act = act * 10 + nxt[N[mid] - '0' + 1];
            put = true;
        }
        if (!put)
            continue;


        FOR(r, mid + 1, SZ(N)) {
            put = false;
            act = 10 * act + smallest;
            put = true;
            if (!put)
                break;
        }
        if (!put)
            continue;
        ans = min(ans, act);
    }




    return ans;
}
void solve() {
    cin >> N >> K;
    ll ans = LLINF;
    FOR(i, 1, 1 << 10) if (count_bits(i) == K) {
        vector<bool> can_use(10);
        FOR(b, 0, 10) if ((i >> b) & 1)
            can_use[b] = 1;
        ans = min(ans, go(can_use));
    }
    printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}