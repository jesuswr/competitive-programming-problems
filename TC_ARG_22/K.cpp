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
const int MAXN = 1e6 + 10;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int SV[MAXN];
void pre() {
	for(int i = 2; i < MAXN; ++i) {
		if (SV[i]) continue;
		for(int j = i; j < MAXN; j += i) SV[j] = i;
	}
}

int N;
int A[MAXN];
string S;

map<int, stack<int>> ST;
set<int> MN[MAXN];

int main(){
	pre();
	ri(N);
	FOR(i,0,N) ri(A[i]);
	cin >> S;

	for(int i = 0; i < N; ++i) {
		while(A[i] > 1) {
			int d = SV[A[i]];
			A[i] /= d;

			if (S[i] == '/') {
				if (ST[d].empty()) ST[d].push(-1);
				int l = ST[d].top(); ST[d].pop();
				MN[l+1].insert(i);
			}
			else {
				ST[d].push(i);
			}
		}
	}
	
	ll ans = 0;
	set<int> mn;
	mn.insert(N);
	for(int i = 0; i < N; ++i) {
		for(int x : MN[i]) mn.insert(x);

		int r = *mn.lower_bound(i);
		ans += r - i;
	}

	cout << ans << endl;

	return 0;
}
