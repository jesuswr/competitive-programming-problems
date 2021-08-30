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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
vi INIT(7), GOAL(7);
map<vi, int> IND_OF;
map<int, vi> VEC_OF;
vii MOVES = {{0, 1}, {0, 3}, {1, 4}, {2, 3}, {2, 5}, {3, 4}, {3, 6}, {5, 6}};
ll D[6000];

int main() {
    FOR(i, 0, 6000) D[i] = LLINF;
    FOR(i, 0, 7) ri(INIT[i]);
    FOR(i, 0, 7) ri(GOAL[i]);

    {
        int b = 0;
        vi aux = INIT;
        sort(ALL(aux));
        do {
            IND_OF[aux] = b;
            VEC_OF[b++] = aux;
        } while (next_permutation(ALL(aux)));
    }


    D[IND_OF[INIT]] = 0;
    priority_queue<pair<ll, int>> pq; pq.push({0, IND_OF[INIT]});
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        c = -c;
        if (D[u] < c)
            continue;
        vi vec = VEC_OF[u];

        for (auto [i, j] : MOVES) {
            swap(vec[i], vec[j]);
            int v = IND_OF[vec];
            if (D[v] > D[u] + vec[i] + vec[j]) {
                D[v] = D[u] + vec[i] + vec[j];
                pq.push({ -D[v], v});
            }

            swap(vec[i], vec[j]);
        }
    }
    printf("%lld\n", D[IND_OF[GOAL]]);
    return 0;
}