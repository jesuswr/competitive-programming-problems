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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
queue<int> Q[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) {
        ri(A[i]);
        Q[A[i]].push(i);
    }
    FOR(i, 1, N + 1) Q[A[i]].push(INF);
    int lst[2] = {0, 0};
    int ans = 0;
    FOR(i, 0, N) {
        Q[A[i]].pop();
        if (A[i] == lst[0] && A[i] == lst[1]) continue;
        if (A[i] == lst[0]) {
            lst[1] = A[i];
            ++ans;
        }
        else if (A[i] == lst[1]) {
            lst[0] = A[i];
            ++ans;
        }
        else {
            if (Q[lst[0]].front() < Q[lst[1]].front()) lst[0] = A[i];
            else lst[1] = A[i];
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}