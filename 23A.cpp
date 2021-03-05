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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N;
string S;

bool find(int l, int r) {
    int l2 = 0, r2 = r - l;
    while (r2 <= N) {
        if (l == l2) ++l2, ++r2;
        else {
            bool eq = true;
            FOR(i, 0, r - l) eq &= S[l + i] == S[l2 + i];
            if (eq) return true;
            ++l2, ++r2;
        }
    }
    return false;
}

int main() {
    cin >> S;
    N = SZ(S);
    int mx = 0;
    FOR(l, 0, N) FOR(r, l + 1 + mx, N + 1) if (find(l, r)) mx = max(mx, r - l);
    printf("%d\n", mx);
    return 0;
}