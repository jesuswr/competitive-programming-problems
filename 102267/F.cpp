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
const int MAXN = 1e5; // CAMBIAR ESTE
const ld PI = 2 * acos(0);
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct pto {
    int x, y, a, r;
    void read() {
        rii(x, y), rii(a, r);
    }
    ld get_angle(pto p) {
        ld ang = atan((1.0 * p.y - y) / (p.x - x));
        ang = abs(ang);
        if (p.x >= x && p.y >= y)
            return ang;
        if (p.x <= x && p.y >= y)
            return PI - ang;
        if (p.x <= x && p.y <= y)
            return PI + ang;
        if (p.x >= x && p.y <= y)
            return 2 * PI - ang;
        return 69;
    }
};

int N;
pto P[3010];
vi G[MAXN];
int IN[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) P[i].read();
    FOR(i, 0, N) FOR(j, 0, N) if (i != j) {
        auto ang = P[i].get_angle(P[j]) * (180 / PI);
        if (ang >= P[i].a)
            ang = min(ang - P[i].a, 360 - (ang - P[i].a));
        else
            ang = min(P[i].a - ang, 360 - (P[i].a - ang));

        if (ang <= P[i].r + 1e-6) {
            G[i].pb(j);
            // printf("%d -> %d\n", i + 1, j + 1);
            IN[j]++;
        }
    }
    queue<int> ord;
    FOR(i, 0, N) if (IN[i] == 0) {
        ord.push(i);
    }
    vi ans;

    FOR(i, 0, N) {
        if (ord.empty()) {
            printf("-1\n");
            return 0;
        }
        int u = ord.front();
        ans.pb(u + 1);
        ord.pop();
        for (auto v : G[u]) {
            IN[v]--;
            if (IN[v] == 0)
                ord.push(v);
        }
    }

    for (auto u : ans) printf("%d ", u);
    printf("\n");


    return 0;
}