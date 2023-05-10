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


int main(){
	srand(time(0));
	int N = 1e5;
	int E = 2e5;
	int Q = 25000;
	cout << N << " " << E << " " << Q << endl;
	map<int, map<int, ll> > M;
	FOR(i,0,E) {
		int a,b;
		a = rand() % N + 1, b = rand() % 21 - 10;
		b = a + b;
		if (a > b) swap(a,b);
		if (a == b || M[a][b] != 0 || abs(a - b) > 10 || a <= 0 || a > N) {
			i--;
			continue;
		}
		M[a][b] = M[b][a] = rand() %1000000000 + 1;
		cout << a << " " << b << " " << rand() % 100 + 1 << endl;
	}
	while(Q--) {
		int a = rand() % N + 1, b = rand() % N + 1;
		if (a == b) {
			++Q;
			continue;
		}
		cout << a << " " << b << endl;
	}

	return 0;
}
