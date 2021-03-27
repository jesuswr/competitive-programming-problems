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
#include <ctime>

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
const int S = 100, Q = 10000;
// GJNM
int M[S + 10][Q + 10];
int PREQ[S + 10][Q + 10], SUFQ[S + 10][Q + 10];
int PRES[S + 10][Q + 10], SUFS[S + 10][Q + 10];
long double Si[S + 10], Qi[Q + 10];

long double f(int s) {
    vector<long double> fails;
    FOR(q, 1, Q + 1) {
        if (M[s][q] == 0 && (1 - Qi[q] / S) < Si[s] / Q) {
            fails.pb(1 - Qi[q] / S);
        }
    }
    long double ret = 0;
    sort(ALL(fails));
    FOR(i, 0, SZ(fails)) ret += abs(fails[i] - Si[s] / Q);
    return ret / SZ(fails);
}

void solve() {
    FOR(i, 0, S) FOR(j, 0, Q) dadsadasda = scanf("%1d", &M[i + 1][j + 1]);

    // calculos fastidiosos xD
    FOR(s, 0, S) FOR(q, 0, Q) {
        PREQ[s + 1][q + 1] = PREQ[s][q + 1] + M[s + 1][q + 1];
        PRES[s + 1][q + 1] = PRES[s + 1][q] + M[s + 1][q + 1];
    }
    for (int s = S - 1; s >= 0; --s)for (int q = Q - 1; q >= 0; --q) {
            SUFQ[s + 1][q + 1] = SUFQ[s + 2][q + 1] + M[s + 1][q + 1];
            SUFS[s + 1][q + 1] = SUFS[s + 1][q + 2] + M[s + 1][q + 1];
        }
    FOR(i, 1, S + 1) Si[i] = 0;
    FOR(i, 1, Q + 1) Qi[i] = 0;
    for (int s = 1; s <= S; ++s) {
        for (int q = 1; q <= Q; ++q) {
            Si[s] += M[s][q];
            Qi[q] += M[s][q];
        }
    }

    //int other = rand() % S;
    //other = 76;
    //FOR(q, 1, Q + 1) {
    //    printf("%d\t:\t%d\t(%Lf)\t%d\t:\t%d\t(%Lf)\n", q, M[59][q], Qi[q] / S, q, M[other][q], Qi[q] / S);
    //}
    //printf("%Lf\t%Lf\n", Si[59] / Q, Si[other] / Q);
    //printf("%Lf\t%Lf\n", f(59), f(other));


    long double mx = 0;
    int mxi;
    FOR(i, 1, S + 1) {
        if (f(i) > mx) {
            mx = f(i);
            mxi = i;
        }
    }
    printf("%d\n", mxi);
}


int main() {
    std::srand ( unsigned ( std::time(0) ) );
    int t, p; rii(t, p);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}