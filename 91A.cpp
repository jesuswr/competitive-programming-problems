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
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e4 + 10; // CAMBIAR ESTE
const int ALPHA = 26;

// GJNM
string S1;
string S2;
int aux, cnt;
bool cycle;

int NXT[MAXN][ALPHA];
int LST[MAXN], FST[MAXN];

int main() {
    cin >> S1 >> S2;
    FOR(i, 0, ALPHA) LST[i] = FST[i] = INF;
    FOR(i, 0, SZ(S1)) FST[S1[i] - 'a'] = min(FST[S1[i] - 'a'], i);
    for (int i = SZ(S1) - 1; i >= 0; --i) {
        FOR(j, 0, ALPHA) NXT[i][j] = LST[j];
        LST[S1[i] - 'a'] = i;
    }

    cycle = false;
    cnt = 1;
    int j = 0;
    FOR(i, 0, SZ(S2)) {
        cnt += cycle;
        cycle = false;
        aux = S2[i] - 'a';
        if (S2[i] == S1[j]) {
            ++j;
            if (j == SZ(S1)) cycle = true, j = 0;
        }
        else {
            if (FST[aux] == INF) {
                printf("-1\n");
                return 0;
            }
            if (NXT[j][aux] != INF) j = NXT[j][aux];
            else j = FST[aux], cycle = true;
            i--;
        }
    }
    printf("%d\n", cnt);

    return 0;
}