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
const ll MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int k, n;
int GO[6][4];

ll DP[69];
ll f(int h) {
    if (DP[h] != -1)
        return DP[h];
    if (h == k)
        return 1;
    return DP[h] = (16 * ((f(h + 1) * f(h + 1)) % MOD)) % MOD;
}

map< pair<ll, int> , ll > cnt;
set< pair<ll, int> > vis;
map< ll , int > original;

int main() {
    GO[0][0] = 1, GO[0][1] = 2, GO[0][2] = 3, GO[0][3] = 5;
    GO[4][0] = 1, GO[4][1] = 2, GO[4][2] = 3, GO[4][3] = 5;

    GO[1][0] = 0, GO[1][1] = 2, GO[1][2] = 4, GO[1][3] = 5;
    GO[3][0] = 0, GO[3][1] = 2, GO[3][2] = 4, GO[3][3] = 5;

    GO[2][0] = 0, GO[2][1] = 1, GO[2][2] = 3, GO[2][3] = 4;
    GO[5][0] = 0, GO[5][1] = 1, GO[5][2] = 3, GO[5][3] = 4;

    memset(DP, -1, sizeof(DP));
    ri(k);
    f(1);

    priority_queue< tuple<int, ll, int> > pq;

    ri(n);
    while (n--) {
        ll a; string s;
        cin >> a >> s;
        int h = 1;
        ll aux = a;
        while (aux > 1) {
            aux /= 2;
            h++;
        }
        if (s[0] == 'w') {
            pq.push({h, a, 1});
            vis.insert({a, 1});
            original[a] = 1;
        }
        else if (s[0] == 'y') {
            pq.push({h, a, 3});
            vis.insert({a, 3});
            original[a] = 3;
        }
        else if (s[0] == 'g') {
            pq.push({h, a, 0});
            vis.insert({a, 0});
            original[a] = 0;
        }
        else if (s[0] == 'b') {
            pq.push({h, a, 4});
            vis.insert({a, 4});
            original[a] = 4;
        }
        else if (s[0] == 'r') {
            pq.push({h, a, 2});
            vis.insert({a, 2});
            original[a] = 2;
        }
        else if (s[0] == 'o') {
            pq.push({h, a, 5});
            vis.insert({a, 5});
            original[a] = 5;
        }
    }

    while (!pq.empty()) {
        auto [h, u, c] = pq.top(); pq.pop();
        if (original.find(u) != original.end()) {
            if (original[u] != c) {
                cnt[ {u, c}] = 0;
                continue;
            }
        }
        // printf("%d %lld %d\n", h, u, c);

        ll aux = 1;
        if (h != k) {
            // printf("\tENTRE\n");
            ll l = 2 * u, r = 2 * u + 1;
            ll ansl = 0;
            bool pre = false;
            FOR(i, 0, 6) if (cnt.find({l, i}) != cnt.end())
                pre = true;
            if (pre) {
                // printf("\t\thizo izq\n");
                FOR(i, 0, 4) if (cnt.find({l, GO[c][i]}) != cnt.end()) {
                    ansl += cnt[ {l, GO[c][i]}];
                    ansl %= MOD;
                }
            }
            else {
                // printf("\t\tno hizo izq\n");
                ansl = 4 * f(h + 1) % MOD;
            }

            ll ansr = 0;
            pre = false;
            FOR(i, 0, 6) if (cnt.find({r, i}) != cnt.end())
                pre = true;
            if (pre) {
                // printf("\t\thizo der\n");
                FOR(i, 0, 4) if (cnt.find({r, GO[c][i]}) != cnt.end()) {
                    ansr += cnt[ {r, GO[c][i]}];
                    ansr %= MOD;
                }
            }
            else {
                // printf("\t\tno hizo der\n");
                ansr = 4 * f(h + 1) % MOD;
            }
            // printf("\t\t%lld %lld\n", ansl, ansr);
            aux = (ansl * ansr) % MOD;
        }
        // printf("\t\t\t\t%lld\n", aux);
        cnt[ {u, c}] = aux;
        if (u == 1)
            continue;
        FOR(i, 0, 4) if (vis.find({u / 2, GO[c][i]}) == vis.end()) {
            vis.insert({u / 2, GO[c][i]});
            pq.push({h - 1, u / 2, GO[c][i]});
        }
    }
    ll ans = 0;
    FOR(i, 0, 6) ans += cnt[ {1, i}];
    printf("%lld\n", ans % MOD);


    return 0;
}