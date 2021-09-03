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
const int MAXN = 2e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int ANS[MAXN];

int main() {
    int n; ri(n);
    vector<tuple<int, int, int>> sweep(n);
    FOR(i, 0, n) {
        int a, b; rii(a, b);
        sweep[i] = {a, b, i};
    }
    sort(ALL(sweep));
    priority_queue<pii> pq;
    queue<int> disp;
    int sz = 0;

    for (auto [l, r, i] : sweep) {
        while (!pq.empty() && -pq.top().F < l) {
            disp.push(pq.top().S);
            pq.pop();
        }
        if (disp.empty())
            disp.push(++sz);
        pq.push({ -r, disp.front()});
        ANS[i] = disp.front();
        disp.pop();
    }
    printf("%d\n", sz);
    FOR(i, 0, n) printf("%d ", ANS[i]);
    printf("\n");
    return 0;
}