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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int A[MAXN];
int main() {
    int n; ri(n);
    string s; cin >> s;
    s = '(' + s + ')';
    stack<int> st;
    st.push(0);

    for (int i = 0; i < SZ(s);) {
        if (s[i] == '(')
            ++i;
        else if (s[i] == ')') {
            st.pop();
            ++i;
        }
        else {
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + (s[i] - '0');
                ++i;
            }
            A[num] = st.top();
            st.push(num);
        }
    }
    FOR(i, 1, n + 1) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}