#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

/**
 * Author: bomba de tenedores
 * Description: fft
 */

const double TAU = 4.0 * acos(0);
const int MAXN = 1 << 20; // ONLY POWERS OF 2!!!
typedef double ld;
struct cd{
    ld x, y;
    cd(ld x, ld y) : x(x), y(y) {}
    cd(ld z = 0) : x(z), y(0) {}
    cd operator +(cd z) {return cd(x + z.x, y + z.y);}
    cd operator -(cd z) {return cd(x - z.x, y - z.y);}
    cd operator *(cd z) {return cd(x*z.x - y*z.y, x*z.y + y*z.x);}
    cd operator /(ld z) {return cd(x/z, y/z);}
};
void FFT(cd *a, int rev){
    int n = MAXN;
    for(int i = 1, j = 0; i < n; i++){
        int k = n >> 1;
        for(; j & k; k >>= 1) j ^= k;
        j ^= k;
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
                a[j+ds] = u - v;
            }
        }
    }
    if(rev == -1)
        FOR(i,0,n) a[i] = a[i] / n;
}
void mult(cd *p, cd *q, cd *r){
    FFT(p,1); FFT(q,1);
    FOR(i,0,MAXN) r[i] = p[i]*q[i];
    FFT(r,-1);
	FOR(i,0,MAXN) {
		if (r[i].x > 0.5) {
			r[i] = 1;
		} else {
			r[i] = 0;
		}
	}
}
void mult(cd *p, cd *r) {
	FFT(p,1); 
    FOR(i,0,MAXN) r[i] = p[i]*p[i];
    FFT(r,-1);
	FOR(i,0,MAXN) {
		if (r[i].x > 0.5) {
			r[i] = 1;
		} else {
			r[i] = 0;
		}
	}
}

cd ans[MAXN], b[MAXN], aux[MAXN];

int main(){
	int n,k; rii(n,k);
	ans[0] = 1;
	FOR(i,0,n) {
		int a; ri(a);
		b[a] = aux[a] = 1;	
	}

	while(k) {
		// cout << k << endl;
		if (k & 1) {
			FOR(i,0,MAXN) aux[i] = b[i];
			mult(ans, aux, ans);
		}
		k /= 2;
		mult(b, b);
	}

	FOR(i,0,MAXN) if (ans[i].x > 0.5) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
