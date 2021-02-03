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
const int MAXN = 1e5 + 1e2; // CAMBIAR ESTE

// GJNM
int N, M, K;
string PAT[MAXN], STR[MAXN];
int MT[MAXN];
map<string, int> MP;

set<int> G[MAXN];
int DEG[MAXN];

void put(int i, int j) {
    if (j == K) {
        if (STR[i] != PAT[MT[i]] && MP.find(STR[i]) != MP.end()) {
            G[MT[i]].insert(MP[STR[i]]);
        }
    }
    else {
        char c = '_';
        swap(c, STR[i][j]);
        put(i, j + 1);
        swap(c, STR[i][j]);
        put(i, j + 1);
    }
}

set<int> FREE;
bool USED[MAXN];
int HELP[MAXN];

bool match(int i, int j) {
    FOR(k, 0, K) {
        if (PAT[j][k] == '_') continue;
        if (PAT[j][k] != STR[i][k]) return false;
    }
    return true;
}

int main() {
    riii(N, M, K);
    FOR(i, 0, N) cin >> PAT[i];
    FOR(i, 0, M) cin >> STR[i] >> MT[i], MT[i]--;
    FOR(i, 0, M) if (!match(i, MT[i])) {
        printf("NO\n");
        return 0;
    }

    FOR(i, 0, N) MP[PAT[i]] = i;
    FOR(i, 0, M) put(i, 0);

    queue<int> ord;
    FOR(i, 0, N) {
        for (auto y : G[i]) DEG[y]++;
    }
    FOR(i, 0, N) {
        if (DEG[i] == 0) ord.push(i);
    }
    vi P;
    while (!ord.empty()) {
        int x = ord.front();
        P.pb(x);
        for (auto y : G[x]) {
            DEG[y]--;
            if (DEG[y] == 0) ord.push(y);
        }
        ord.pop();
    }
    if (SZ(P) != N) printf("NO\n");
    else {
        printf("YES\n");
        for (auto p : P) printf("%d ", p + 1);
        printf("\n");
    }
    return 0;
}