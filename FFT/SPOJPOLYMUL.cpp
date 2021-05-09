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
const int MAXN = 1e7; // CAMBIAR ESTE

// GJNM
int N;
const long double TAU = 4.0 * acos(0);
const long double EPS = 1e-8;
struct cd{
    ld x=0, y=0;
    cd(ld _x, ld _y) : x(_x), y(_y) {}
    cd(ld z = 0) : x(z), y(0) {}
    cd operator +(cd z) {return cd(x + z.x, y + z.y);}
    cd operator -(cd z) {return cd(x - z.x, y - z.y);}
    cd operator *(cd z) {return cd(x*z.x - y*z.y, y*z.x + x*z.y);}
    cd operator /(ld z) {return cd(x/z, y/z);}
};
void FFT(cd *a, int rev){
    int n = N;
    for(int i = 1, j = 0; i < n; i++){
        int k = n>>1;
        for(; j&k; k>>=1) j^=k;
        j^=k;
        if(i < j) swap(a[i], a[j]);
    }
    for(int s = 2, ds = 1; s <= n; ds = s, s <<= 1){
        ld ang = TAU / s * rev;
        cd wn(cos(ang), sin(ang));
        for(int i = 0; i < n; i += s){
            cd w(1), t;
            for(int j = i; j < i + ds; j++, w = w*wn){
                cd u = a[j], v = a[j+ds] * w;
                a[j] = u + v;
                a[j + ds] = u - v;
            }
        }
    }
    if(rev == -1)
        FOR(i,0,n) a[i] = a[i] / n;
}
void mult(cd *p, cd *q, cd *r){
    FFT(p, 1); FFT(q, 1);
    FOR(i,0,N) r[i] = p[i] * q[i];
    FFT(r, -1);
}

bool eq(ld a, ld b){ return abs(a-b) < EPS; }

cd A[MAXN], B[MAXN], C[MAXN];

int main() {
    int t; ri(t);
    while (t--) {
        int n; ri(n);
        FOR(i, 0, n + 1) {
            int aux; ri(aux);
            A[i].x = aux, A[i].y = 0;
        }
        FOR(i, 0, n + 1) {
            int aux; ri(aux);
            B[i].x = aux, B[i].y = 0;
        }
        N = 1;
        while (N < 2 * n + 2) N <<= 1;
        FOR(i, n + 1, N) {
            A[i].x = A[i].y = B[i].x = B[i].y = 0;
        }

        mult(A, B, C);
        FOR(i, 0, 2 * n + 1) printf("%lld%c", (ll)(C[i].x + 0.5), " \n"[i == 2 * n]);
    }

    return 0;
}