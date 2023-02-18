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

int X[3], Y[3];

int main(){
	FOR(i,0,3) rii(X[i], Y[i]);

	printf("3\n");
	FOR(i,0,3) {
		printf("%d %d\n", 
			X[i] + (-X[i] + X[(i+1) % 3]) + (-X[i] + X[(i+2) % 3]),
			Y[i] + (-Y[i] + Y[(i+1) % 3]) + (-Y[i] + Y[(i+2) % 3])
		);
	}

	return 0;
}
