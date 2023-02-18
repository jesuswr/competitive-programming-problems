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

int N,K;
int H[1 << 4];


int main(){
	rii(N,K);
	FOR(i,0,N){
		int a = 0;
		FOR(_,0,K) {
			int aux; ri(aux);
			a = 2 * a + aux;
		}
		H[a] = 1;
	}

	if (H[0]) printf("YES\n");
	else{
		FOR(i,1,1<<4) {
			FOR(j,1,1<<4) {
				if ( (i & j) == 0 && H[i] && H[j] ) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	if (!H[0])printf("NO\n");
	return 0;
}
