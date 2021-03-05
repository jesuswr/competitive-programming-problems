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
string S;
int N;
int CNT[26];

bool valid(int k) {
    int need = 0;
    FOR(i, 0, 26) need += (CNT[i] + k - 1) / k;
    return need <= N;
}

int main() {
    cin >> S;
    ri(N);

    for (auto c : S) ++CNT[c - 'a'];

    int lo = 1, hi = 1e4;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (valid(mi)) hi = mi;
        else lo = mi + 1;
    }

    if (hi == 1e4) {
        printf("-1\n");
        return 0;
    }
    int need = 0;
    FOR(i, 0, 26) need += (CNT[i] + hi - 1) / hi;
    printf("%d\n", hi);
    FOR(i, 0, 26) FOR(j, 0, (CNT[i] + hi - 1) / hi) printf("%c", i + 'a');
    FOR(i, need, N) printf("z");
    printf("\n");
    return 0;
}