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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll gcd(ll a, ll b) {return a ? gcd(b % a, a) : b;}
ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
ll expmod(ll b, ll e, ll m) {
    if (!e)return 1;
    ll q = expmod(b, e / 2, m); q = mulmod(q, q, m);
    return e & 1 ? mulmod(b, q, m) : q;
}
bool is_prime_prob(ll n, int a) {
    if (n == a)return true;
    ll s = 0, d = n - 1;
    while (d % 2 == 0)s++, d /= 2;
    ll x = expmod(a, d, n);
    if ((x == 1) || (x + 1 == n))return true;
    FOR(_, 0, s - 1) {
        x = mulmod(x, x, n);
        if (x == 1)return false;
        if (x + 1 == n)return true;
    }
    return false;
}
bool rabin(ll n) { // true iff n is prime
    if (n == 1)return false;
    int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    FOR(i, 0, 9)if (!is_prime_prob(n, ar[i]))return false;
    return true;
}
ll rho(ll n) {
    if (!(n & 1))return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        if (x >= y)d = gcd(x - y, n);
        else d = gcd(y - x, n);
    }
    return d == n ? rho(n) : d;
}
void fact(ll n, map<ll, int>& f) { //O (lg n)^3
    if (n == 1)return;
    if (rabin(n)) {f[n]++; return;}
    ll q = rho(n); fact(q, f); fact(n / q, f);
}


ll a, m;

ll binpow(__int128 b, __int128 e) {
    __int128 ret = 1;
    while (e) {
        if (e & 1) ret = (ret * b) % m;
        e >>= 1;
        b = (b * b) % m;
    }
    return ret;
}

int main() {
    rll(a, m);
    if (__gcd(a, m) != 1) {
        printf("Maradona e muito mais grande que o Pele\n");
        return 0;
    }

    map<ll, int> f;
    fact(m, f);
    ll phi = m;
    for (auto [p, _] : f) {
        phi /= p;
        phi *= (p - 1);
    }

    f.clear();
    fact(phi, f);

    for (auto [p, p_cnt] : f) {
        FOR(_, 0, p_cnt) {
            if (binpow(a, phi / p) == 1)
                phi /= p;
            else
                break;
        }
    }

    printf("%lld\n", phi);
    return 0;
}