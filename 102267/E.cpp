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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct pto {
    int x, y;
    pto() {}
    pto(int a, int b) {
        x = a,
        y = b;
    }
    void read() {
        rii(x, y);
    }
};
string S;
pto P[4];
void pre() {
    FOR(_, 0, 100) S += "DL";
    FOR(_, 0, 7) {
        S += "UUUUUUUUUUUUUUUUUU";
        S += "LLLLLLLLLLLLLLLLLL";
        S += "DDDDDDDDDDDDDDDDDD";
        S += "LLLLLLLLLLLLLLLLLL";
    }
}


void go() {
    S += "UUUUUUUUUUUUUUUUUUUUUUUU";
    S += "DDD";
    S += "RRRRRRRRRRRRRRRRR";
    S += "DDDDD";
    S += "L";
    S += "DDDDDDD";
    S += "UUU";
    S += "L";
    S += "DDDDD";
    S += "R";
    S += "UUUUU";
    S += "R";
    S += "DDDDD";
    S += "LL";
    S += "UUUUU";
}

void solve() {
    FOR(i, 0, 4) P[i].read();
    pre();
    go();
    cout << SZ(S) << endl;
    cout << S << endl;
    S.clear();
}

int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}