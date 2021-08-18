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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N;

void solve() {
    ri(N);
    priority_queue<int> pqa, pqb, pqa2;
    FOR(i, 0, N) {
        int a; ri(a);
        pqa.push(a);
    }
    FOR(i, 0, N) {
        int a; ri(a);
        pqb.push(a);
    }

    int m = N - N / 4;
    ll suma = 0;
    ll sumb = 0;
    FOR(i, 0, m) {
        pqa2.push(-pqa.top());
        suma += pqa.top(); pqa.pop();
        sumb += pqb.top(); pqb.pop();
    }

    if (suma >= sumb) {
        printf("0\n");
        return;
    }

    int i = 1;
    while (true) {
        int new_m = (N + i) - (N + i) / 4;
        if (new_m > m) {
            suma += 100; pqa2.push(-100);
            pqb.push(0);
            sumb += pqb.top(); pqb.pop();
            if (suma >= sumb) {
                printf("%d\n", i);
                return;
            }
        }
        else {
            suma += pqa2.top(); pqa2.pop();
            suma += 100; pqa2.push(-100);
            if (suma >= sumb) {
                printf("%d\n", i);
                return;
            }
        }
        i++;
        m = new_m;
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}