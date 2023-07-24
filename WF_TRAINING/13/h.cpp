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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int K;

int main(){
	ri(K);
	if (K == 1) {
		printf("2 1\n1 2\n");
		return 0;
	}
	else if (K == 2) {
		printf("4 4\n1 2\n1 3\n2 3\n3 4\n");
		return 0;
	}
	else if (K <= 20) {
		printf("%d %d\n", K, K);
		FOR(i,1,K) printf("%d %d\n", i, i+1);
		printf("1 %d\n", K);
	}
	else {
		FOR(i, 3, 21) FOR(j,2,21) if (i + j <= 20) {
			if ( i * (i - 1) / 2 + j + 2 * i - 4 == K ) {
				printf("%d %d\n", i + j, i * (i - 1) / 2 + j - 1 + 2);
				FOR(k,1,i+1) FOR(k2, k+1,i+1) printf("%d %d\n", k, k2);
				FOR(k,1,j) printf("%d %d\n", i + k, i + k + 1);
				printf("%d %d\n", 1, i+1);
				printf("%d %d\n", 2, i+j);
				return 0;
			}
		}
	}
	
	return 0;
}
