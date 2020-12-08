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
const int MAXN = 5e5; // CAMBIAR ESTE

// GJNM
int n;
int m[MAXN];
int l[MAXN], r[MAXN];
ll cntl[MAXN], cntr[MAXN];
int outp[MAXN];

void buildl(int pos) {
    if (l[pos] == -1) {
        FOR(i, 0, pos + 1) {
            outp[i] = m[pos];
        }
    }
    else {
        FOR(i, l[pos] + 1, pos + 1) {
            outp[i] = m[pos];
        }
        buildl(l[pos]);
    }
}

void buildr(int pos) {
    if (r[pos] == -1) {
        FOR(i, pos, n) {
            outp[i] = m[pos];
        }
    }
    else {
        FOR(i, pos, r[pos]) {
            outp[i] = m[pos];
        }
        buildr(r[pos]);
    }
}

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(m[i]);
    }

    stack<int> st, st2;
    FOR(i, 0, n) {
        while (!st.empty() && m[st.top()] >= m[i])
            st.pop();
        if (st.empty())
            l[i] = -1;
        else
            l[i] = st.top();
        st.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st2.empty() && m[st2.top()] >= m[i])
            st2.pop();
        if (st2.empty())
            r[i] = -1;
        else
            r[i] = st2.top();
        st2.push(i);
    }

    FOR(i, 0, n) {
        if (l[i] == -1)
            cntl[i] = 1ll * m[i] * (i + 1);
        else
            cntl[i] = 1ll * m[i] * (i - l[i]) + cntl[l[i]];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (r[i] == -1)
            cntr[i] = 1ll * m[i] * (n - i);
        else
            cntr[i] = 1ll * m[i] * (r[i] - i) + cntr[r[i]];
    }

    ll ans = 0;
    FOR(i, 0, n) {
        ans = max(ans, cntr[i] + cntl[i] - m[i]);
    }
    FOR(i, 0, n) {
        if (ans == cntr[i] + cntl[i] - m[i]) {
            buildl(i);
            buildr(i);
            break;
        }
    }

    FOR(i, 0, n) {
        printf("%d%c", outp[i], " \n"[i == n - 1]);
    }
    return 0;
}