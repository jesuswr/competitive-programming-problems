#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e4+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long double T;

const T PI = 2 * acos(0);
T getVolumeComp(T r, T h) {
	return PI * h * h * (3 * r - h) / 3;
}
T getVolume(T r, T h) {
	return 2 * getVolumeComp(r, r) - getVolumeComp(r, h);
}

int N, S;
T V = 100 * 100 * 100;
T R[MAXN], X[MAXN], Y[MAXN], Z[MAXN];

T getVol(T z) {
	T vol = z * 100 * 100;
	FOR(i,0,N) {
		if (Z[i] <= z) 
			vol -= getVolume(R[i], max(Z[i] + R[i] - z, (T)0) );
		else if (Z[i] - R[i] <= z) 
			vol -= getVolumeComp(R[i], z - (Z[i] - R[i]));
	}
	return vol;
}

int main(){
	cin >> N >> S;
	FOR(i,0,N) cin >> R[i] >> X[i] >> Y[i] >> Z[i];
	FOR(i,0,N) {
		R[i] /= 1000;X[i] /= 1000;Y[i] /= 1000;Z[i] /= 1000;
		V -= getVolume(R[i], 0);
	}
	V /= S;

	T acum = 0;
	T neededVol = V;
	FOR(_,0,S-1) {
		T lo = acum, hi = 100;
		FOR(__,0,60) {
			T mi = (lo + hi) / 2;
			if ( getVol(mi) <= neededVol )
				lo = mi;
			else
				hi = mi;
		}
		printf("%.10Lf\n", lo - acum);
		acum = lo;
		neededVol += V;
	}
	printf("%.10Lf\n", 100 - acum);


	return 0;
}
