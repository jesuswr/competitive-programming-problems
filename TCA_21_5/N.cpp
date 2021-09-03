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
set<int> G[30];
int IN[30];
string S[110];

int main() {
    int n; ri(n);
    FOR(i, 0, n) {
        cin >> S[i];
    }
    FOR(i, 1, n) {
        bool added = false;
        FOR(j, 0, min(SZ(S[i]), SZ(S[i - 1]))) {
            if (S[i][j] != S[i - 1][j]) {
                G[S[i - 1][j] - 'a'].insert(S[i][j] - 'a');
                added = true;
                break;
            }
        }
        if (!added && SZ(S[i - 1]) > SZ(S[i])) {
            printf("Impossible\n");
            return 0;
        }
    }
    queue<int> ord;
    FOR(i, 0, 26) for (auto u : G[i]) IN[u]++;
    FOR(i, 0, 26) if (IN[i] == 0) ord.push(i);
    string ans;
    FOR(i, 0, 26) {
        if (ord.empty()) {
            printf("Impossible\n");
            return 0;
        }
        int let = ord.front(); ord.pop();
        ans.pb(let + 'a');
        for (auto u : G[let]) {
            IN[u]--;
            if (IN[u] == 0)
                ord.push(u);
        }
    }
    cout << ans << endl;
    return 0;
}