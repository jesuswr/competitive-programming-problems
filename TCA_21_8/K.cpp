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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;

int main() {
    vector<tuple<int, int, int>> Es;
    rii(N, M);
    if (N == 2){
        printf("2 2\n1 2 2\n");
        return 0;
    }
    for (int u = 3; u <= N; ++u) Es.pb({1, u, 2});
    Es.pb({1, 2, 203579 - (N - 2) * 2 });
    printf("%d %d\n", 2, 203579);
    M -= SZ(Es);
    for (int u = 2; u <= N; ++u) for (int v = u + 1; v <= N && M > 0; ++v) {
        Es.pb({u,v,405439});
        M--;
    }
    for(auto [u,v,c] : Es) printf("%d %d %d\n", u,v,c);

    return 0;
}