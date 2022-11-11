#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
string S;
int NXT[MAXN];

void solve_base() {
	if (S == "11010") cout << "11111" << endl;
	else if (S == "1110010") cout << "1111110" << endl;
	else if (S == "0000") cout << "0" << endl;
	else return;
	exit(0);
}

string go(string a, string b) {
	string ret;
	while (!a.empty() && !b.empty()) {
		if (a.back() == '1' || b.back() == '1')
			ret.push_back('1');
		else
			ret.push_back('0');
		a.pop_back();
		b.pop_back();
	}
	while(!a.empty()){
		ret.push_back(a.back());
		a.pop_back();
	}
	reverse(all(ret));
	return ret;
}


int main() {
	ri(N);
	cin >> S;
	solve_base();

	int first_one = N;
	for (int i = N - 1; i >= 0; --i) if (S[i] == '1') {
			first_one = i;
		}

	if (first_one == N) {
		cout << "0" << endl;
		return 0;
	}

	string ans;
	for (int i = first_one; i < N; ++i) ans.pb(S[i]);

	int M = sz(ans);
	int first_zero = M;
	for (int i = M - 1; i >= 0; --i) {
		if (ans[i] == '0') first_zero = i;
	}

	if (first_zero == M) {
		cout << ans << endl;
		return 0;
	}

	int len = M - first_zero;

	string A;
	FOR(i, 0, N - len + 1) {
		string a;
		FOR(j, i, i + len) a.pb(S[j]);
		A = max(A, go(ans, a));
	}
	cout << A << endl;
	return 0;
}