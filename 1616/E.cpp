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
const int MAXN = 2e5 + 59; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

int N;
string S, T;

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < N + 3; p += p & -p)
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

queue<int> Q[30];

void solve() {
    ri(N);
    cin >> S;
    cin >> T;
    FOR(i, 0, N) Q[S[i] - 'a'].push(i);
    ll ans = LLINF;
    ll acum = 0;
    FOR(i, 0, N) {
        ll mn = LLINF;
        for (int c = 0; c < T[i] - 'a'; ++c) {
            if (!Q[c].empty())
                mn = min(mn, Q[c].front() - sumBIT(Q[c].front()));
        }
        ans = min(ans, acum + mn);
        if (Q[T[i] - 'a'].empty())
            break;
        int j = Q[T[i] - 'a'].front();
        Q[T[i] - 'a'].pop();
        acum += (j - sumBIT(j));
        updBIT(j, 1);
    }
    FOR(i, 0, N + 69) BIT[i] = 0;
    FOR(i, 0, 30) while (!Q[i].empty()) Q[i].pop();

    if (ans == LLINF)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}