#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2.5e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
ll W[MAXN];

ll DP[MAXN][4][11][11];
ll f() {
	// ll &ret = DP[i][crry][k1][k2];
	// if (ret != -1) return ret;

	// if (i == N && crry <= 1 && k1 == k2 && k1 <= K) return ret = 0;
	// if (i == N || crry >= 3 || max(k1, k2) > K) return ret = INFLL;

	// return ret = min({
	// 	f(i+1, 0, k1, k2) + W[i], // prender y dejar ahi
	// 	f(i+1, crry+1, k1+1, k2) + W[i], // prender y dejar para cambio
	// 	f(i+1, 0, k1, k2+1), // no prender pero cambiar por una prendida
	// 	f(i+1, crry+1, k1, k2) // n o hacer nada
	// });


	for(int i = N; i >= 0; --i) {
		for(int crry = 0; crry <= 3; ++crry) {
			for(int k1 = 0; k1 <= K+1; k1++) {
				for(int k2 = 0; k2 <= K+1; k2++) {
					ll &ret = DP[i][crry][k1][k2];
					if (i == N && crry <= 1 && k1 == k2 && k1 <= K) {
						ret = 0;
						continue;
					}
					if (i == N || crry >= 3 || max(k1, k2) > K) {
						ret = INFLL;
						continue;
					}
					ret = min({
						DP[i+1][0][k1][k2] + W[i], // prender y dejar ahi
						DP[i+1][crry+1][k1+1][k2] + W[i], // prender y dejar para cambio
						DP[i+1][0][k1][k2+1], // no prender pero cambiar por una prendida
						DP[i+1][crry+1][k1][k2] // n o hacer nada
					});
				}	
			}
		}
	}
	return DP[0][1][0][0];
}


int main(){
	rii(N,K);
	FOR(i,0,N) lri(W[i]);
	cout << f() << endl;
	return 0;
}
