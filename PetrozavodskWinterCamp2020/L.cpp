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

int main() {
    int t;
    ri(t);
    while (t--) {
        int n, k; rii(n, k);
        priority_queue<ll> pq;
        FOR(_, 0, n) {
            int aux; ri(aux);
            pq.push(aux);
        }
        ll time = 0;
        while (!pq.empty() && k > 0) {
            time = max(time, pq.top());
            --k;
            pq.pop();
        }
        if (!pq.empty()) {
            ll cnt = 0;
            while(!pq.empty()){
                cnt += pq.top();
                pq.pop();
            }
            time = max(time, cnt);
        }
        printf("%lld\n", time);
    }
    return 0;
}