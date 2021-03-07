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
struct book {
    ll pages, deadline;
    bool operator<(const book other) {
        return deadline < other.deadline;
    }
};

class Compare
{
public:
    bool operator()(book &a, book &b) {
        return a.pages < b.pages;
    }
};

int N, M;
vector<book> A;

bool f(ll k) {
    priority_queue<book, vector<book>, Compare> pq;
    ll cnt = 0;
    FOR(i, 0, N) {
        pq.push(A[i]);
        cnt += A[i].pages;
        while (cnt > A[i].deadline * k) {
            cnt -= pq.top().pages;
            pq.pop();
        }
    }
    return SZ(pq) >= N - M;
}



int main() {
    rii(N, M);
    FOR(i, 0, N) {
        ll p, d;
        rll(p, d);
        A.pb({p, d});
    }
    sort(ALL(A));
    ll lo = 1, hi = 1e15;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (f(mi)) hi = mi;
        else lo = mi + 1;
    }
    printf("%lld\n", hi);
    return 0;
}