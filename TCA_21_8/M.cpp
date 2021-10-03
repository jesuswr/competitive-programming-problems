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
const int MAXN = 1069; // CAMBIAR ESTE
const int OFFSET = 2 * 1069;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
string S, T;

bool VIS[MAXN][OFFSET];
void dfs(int p, int diff) {
    VIS[p][diff] = 1;
    if (p == N) {
        if (diff == OFFSET - K || diff == OFFSET + K) {
            cout << T << endl;
            exit(0);
        }
        else
            return;
    }
    if (diff == OFFSET - K || diff == OFFSET + K)
        return;

    if ((S[p] == 'L' || S[p] == '?') && !VIS[p + 1][diff - 1]) {
        T.pb('L');
        dfs(p + 1, diff - 1);
        T.pop_back();
    }
    if ((S[p] == 'W' || S[p] == '?') && !VIS[p + 1][diff + 1]) {
        T.pb('W');
        dfs(p + 1, diff + 1);
        T.pop_back();
    }
    if ((S[p] == 'D' || S[p] == '?') && !VIS[p + 1][diff]) {
        T.pb('D');
        dfs(p + 1, diff);
        T.pop_back();
    }
}

int main() {
    rii(N, K);
    cin >> S;
    dfs(0, OFFSET);
    printf("NO\n");
    return 0;
}