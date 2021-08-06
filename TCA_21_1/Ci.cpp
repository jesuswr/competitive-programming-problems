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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int N;
string MAT[MAXN];

bool valid(int i, int j) {
    return min(i, j) >= 0 && max(i, j) < N && MAT[i][j] == 'o';
}

bool check(int i, int j) {
    int cnt = 0;
    for (auto di : {1, 0, -1}) for (auto dj : {1, 0, -1}) {
        if (abs(di) == abs(dj))
            continue;
        cnt += valid(i + di, j + dj);
    }
    return ~cnt & 1;
}

int main() {
    ri(N);
    FOR(i, 0, N) cin >> MAT[i];

    FOR(i, 0, N) FOR(j, 0, N) {
        if (!check(i, j)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}