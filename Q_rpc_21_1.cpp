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
int q;
stack< tuple<int, int, int> > st;

void PUSH(int x) {
    if (st.empty()) {
        st.push({x, x, x});
    }
    else {
        int mn = get<1>(st.top()), mx = get<2>(st.top());
        st.push({x, min(x, mn), max(x, mx)});
    }
}

void POP() {
    if (!st.empty()) st.pop();
}

void PRINT() {
    if (st.empty()) printf("Empty!\n");
    else {
        int mn = get<1>(st.top()), mx = get<2>(st.top());
        printf("%d\n", mx - mn);
    }
}

void solve() {
    ri(q);
    FOR(_, 0, q) {
        int t; ri(t);
        if (t == 1) {
            int v; ri(v);
            PUSH(v);
        }
        else if (t == 2) {
            POP();
        }
        else {
            PRINT();
        }
    }
    while(!st.empty()) st.pop();
}


int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}