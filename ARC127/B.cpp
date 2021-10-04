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
const int MAXN = 5e4 + 69; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
string ANS[3 * MAXN];
int CNT[20][3];

ll poww(ll b, ll e) {
    ll r = 1;
    FOR(_, 0, e) r *= b;
    return r;
}

string int_to_str_base_3(ll x) {
    string r;
    while (x > 0) {
        r.pb((x % 3) + '0');
        x /= 3;
    }
    reverse(ALL(r));
    return r;
}

bool bad(int N) {
    FOR(i, 1, 2 * N) if (ANS[i].compare(ANS[i - 1]) == 0)
        return true;
    return false;
}

int main() {
    int N, L; rii(N, L);
    FOR(i, 2 * N, 3 * N) ANS[i] = int_to_str_base_3(2 * poww(3, L - 1) + i % N);
    FOR(i, 2 * N, 3 * N) FOR(j, 1, L) CNT[j][ANS[i][j] - '0']++;
    FOR(i, 0, 2 * N) ANS[i].clear();
    FOR(i, 0, N) ANS[i].pb('0');
    FOR(i, N, 2 * N) ANS[i].pb('1');
    FOR(j, 1, L) {
        FOR(i, 0, N) {
            ANS[i].pb('?');
            ANS[N + i].pb('?');
            int d = ANS[2 * N + i][j] - '0';
            ANS[i][j] = '0' + (d + 1) % 3;
            ANS[N + i][j] = '0' + (d + 2) % 3;
        }
    }
    sort(ANS, ANS + 2 * N);
    FOR(i, 0, 3 * N) cout << ANS[i] << '\n';

    return 0;
}