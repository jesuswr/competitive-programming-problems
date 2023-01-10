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


int N;
int q(int i, const string &s) {
	cout << "? " << 1+i << " " << s << endl;
	int a; ri(a);
	return a;
}
int q(int i, const vi &inds) {
	string s(N, '0');
	for(int j : inds) s[j] = '1';
	cout << "? " << i+1 << " " << s << endl;
	int a; ri(a);
	return a;
}
void a(const string &s) {
	cout << "! " << s << endl;
	exit(0);
}


int main(){
	ri(N);
	string s(N, '1');
	vii degs;
	FOR(i,0,N) {
		s[i] = '0';

		int deg = q(i, s);
		degs.pb({i, deg});

		s[i] = '1';
	}
	sort(all(degs), [](ii a, ii b){
		return a.S > b.S;
	});

	s.clear();
	s.resize(N, '0');
	s[ degs[0].F ] = '1';
	for(int j = 1; j < N; ++j) {
		int i = degs[j].F;
		if ( q(i, s) ) {
			int k = j;
			while( s[ degs[k].F ] == '0' ) {
				s[ degs[k].F ] = '1';
				--k;
			}
		}
	}

	a(s);

	return 0;
}
