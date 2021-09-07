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
void NO() {
    printf("NO\n");
    exit(0);
}

int N, M;
int A[510], B[510];

void check(int l, int r) {
    if (l == r - 1)
        return;
    int mn = 1e7, mx = 0;
    FOR(i, l, r) {
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    if (mn == mx)
        NO();
}

void solve(int l, int r) {
    if (l == r - 1)
        return;
    int mn = 1e7, mx = 0;
    FOR(i, l, r) {
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    if (mn == mx)
        NO();

    int mxi;
    int del_l = 0, del_r = 0;
    FOR(i, l, r) {
        if (A[i] == mx) {
            if (i - 1 >= l && A[i - 1] < A[i]) {
                mxi = i;
                del_l++;
                break;
            }
            else if (i + 1 < r && A[i + 1] < A[i]) {
                mxi = i;
                del_r++;
                break;
            }
        }
    }
    int aux = mxi;
    if (del_l) {
        printf("%d L\n", mxi-- + 1);
        FOR(_, 0, aux - l - 1) {
            printf("%d L\n", mxi-- + 1);
        }
        FOR(_, 0, r - aux - 1) {
            printf("%d R\n", mxi + 1);
        }
    }
    else {
        FOR(_, 0, r - aux - 1) {
            printf("%d R\n", mxi + 1);
        }
        FOR(_, 0, aux - l) {
            printf("%d L\n", mxi-- + 1);
        }
    }
}


int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    ri(M);
    FOR(i, 0, M) ri(B[i]);

    vii segs;
    int i = 0, j = 0;
    while (i < N && j < M) {
        int k = i, sm = 0;
        while (k < N && sm < B[j])
            sm += A[k++];
        if (sm != B[j])
            NO();
        segs.pb({i, k});
        i = k;
        ++j;
    }

    if (i != N || j != M)
        NO();

    reverse(ALL(segs));
    for (auto[l, r] : segs)
        check(l, r);
    printf("YES\n");
    for (auto[l, r] : segs)
        solve(l, r);

    return 0;
}