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
const int MAXN = 1e5 + 69 + 73; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
pair<ll, ll> A[MAXN];

bool valid(int t) {
    if (t == 0)
        return true;
    priority_queue<pair<ll, ll>> pq;
    ll sm = 0;
    ll sm2 = 0;
    ll sm3 = 0;
    // printf("%d : \n", t);
    vector<ll> aux(N), aux2(N);
    FOR(i, 0, 2 * t) {
        sm3 += A[i].S;
        if (SZ(pq) < t || -pq.top().F < (A[i].F + A[i].S) ) {
            if (SZ(pq) == t) {
                sm += pq.top().F;
                sm2 += pq.top().S;
                pq.pop();
            }
            sm += (A[i].F + A[i].S);
            sm2 += A[i].S;
            pq.push({ -(A[i].F + A[i].S), -A[i].S});
        }
        aux[i] = sm;
        aux2[i] = sm3;
        // printf("\t%lld %lld\n", aux[i], aux2[i]);
    }
    set<pair<ll, ll>> aux3;
    ll sm4 = 0;
    FOR(i, t, N) {
        if (SZ(aux3) < t) {
            aux3.insert({A[i].S, i});
            sm4 += A[i].S;
        }
        else {
            pair<ll, ll> _aux = *aux3.rbegin();
            if (_aux.F >= A[i].S) {
                aux3.erase(aux3.find(_aux));
                aux3.insert({A[i].S, i});
                sm4 -= _aux.F;
                sm4 += A[i].S;
            }
        }
    }
    FOR(i, t, 2 * t) {
        if (aux[i - 1] - aux2[i - 1] - sm4 >= 0 )
            return true;


        if (i == 2 * t - 1)
            break;
        pair<ll, ll> __epaa = {A[i].S, i};
        if (aux3.find(__epaa) != aux3.end()) {
            aux3.erase(aux3.find(__epaa));
            sm4 -= A[i].S;
        }
        else {
            pair<ll, ll> _aux = *aux3.rbegin();
            sm4 -= _aux.F;
            aux3.erase(aux3.find(_aux));
        }
    }


    return false;

}

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i].F);
    FOR(i, 0, N) rl(A[i].S);
    sort(A, A + N); reverse(A, A + N);
    // FOR(i, 0, N) printf("%d %d\n", A[i].F, A[i].S);

    int lo = 0, hi = N / 2;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%d\n", lo);
    return 0;
}