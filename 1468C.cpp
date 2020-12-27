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
const int MAXN = 6e5; // CAMBIAR ESTE

// GJNM
int Q, t = 1;
priority_queue< pii > pq;
queue< int > q;
bool served[MAXN];

int main() {
    ri(Q);
    while (Q--) {
        int type; ri(type);
        if (type == 1) {
            int m; ri(m);
            pq.push({m, -t});
            q.push(t);
            t++;
        }
        else if (type == 2) {
            while (served[ q.front() ]) q.pop();
            int ans = q.front(); served[ans] = true;
            printf("%d ", ans);
        }
        else {
            while (served[ -pq.top().S ]) pq.pop();
            int ans = -pq.top().S; served[ans] = true;
            printf("%d ", ans);
        }
    }
    printf("\n");

    return 0;
}