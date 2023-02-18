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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ii q(int i) {
	cout << "? " << i << endl;
	int v, nxt;
	cin >> v >> nxt;
	return {v, nxt};
}
void ans(int x){
	cout << "! " << x << endl;
	exit(0);
}


int N, S, X;

int main(){
	rii(N,S), ri(X);

	ii s = q(S);
	if (s.F >= X) {
		ans(s.F);
	}

	int mn = s.F, mni = s.S;
	FOR(_,0,999){
		int i = rng() % N + 1;
		s = q(i);
		if (s.F > mn && s.F < X) {
			mn = s.F;
			mni = i;
		}
	}
	while(mn < X && mni != -1) {
		s = q(mni);
		mn = s.F;
		mni = s.S;
	}
	if (mn >= X)
		ans(mn);
	else
		ans(-1);

	return 0;	
}
