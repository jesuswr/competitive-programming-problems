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
#include <time.h>

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
double X[3], Y[3];
double M[2];
double XM[2], YM[2];
double B[2];
double A[3];
double centerx, centery;
double EPS = 0.0001;
double PI = 2 * acos(0);

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool same() {
    FOR(i, 0, 3) FOR(j, i + 1, 3) if (abs(Y[i] - Y[j]) < EPS || abs(X[i] - X[j]) < EPS) return true;
    return false;
}

void rotate() {
    srand(time(NULL));
    while (same()) {
        double alpha = fRand(0, PI);
        FOR(i, 0, 3) {
            double new_x = X[i] * cos(alpha) - Y[i] * sin(alpha);
            double new_y = Y[i] * cos(alpha) + X[i] * sin(alpha);
            X[i] = new_x, Y[i] = new_y;
        }
    }
}

bool valid(int v) {
    FOR(i, 0, 2) {
        if (abs(sin(v * (A[i] - A[i + 1]) / 2)) >= EPS)
            return false;
    }
    return true;
}

double dist() {
    return sqrt((X[0] - centerx) * (X[0] - centerx) + (Y[0] - centery) * (Y[0] - centery));
}

double area(int v) {
    double alpha = PI / v;
    double s = 2 * sin(alpha) * dist();
    s = v * s;
    double a = cos(alpha) * dist();
    return s * a / 2;
}

int main() {
    FOR(i, 0, 3) {
        dadsadasda = scanf("%lF %lF", X + i, Y + i);
    }
    rotate();
    FOR(i, 0, 2) {
        M[i] = - (X[i + 1] - X[i]) / (Y[i + 1] - Y[i]);
        XM[i] = (X[i] + X[i + 1]) / 2;
        YM[i] = (Y[i] + Y[i + 1]) / 2;
        B[i] = YM[i] - XM[i] * M[i];
    } // YM = XM * M + B
    centerx = (B[1] - B[0]) / (M[0] - M[1]);
    centery = centerx * M[0] + B[0];
    FOR(i, 0, 3) {
        A[i] = atan2(Y[i] - centery, X[i] - centerx);
    }

    int v = 3;
    while (true) {
        if (valid(v)) {
            printf("%lF\n", area(v));
            break;
        }
        v++;
    }
    return 0;
}