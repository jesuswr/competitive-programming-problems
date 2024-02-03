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
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;

ii ops[16] = {
	{'+', '+'},
	{'+', '-'},
	{'+', '*'},
	{'+', '/'},
	{'-', '+'},
	{'-', '-'},
	{'-', '*'},
	{'-', '/'},
	{'*', '+'},
	{'*', '-'},
	{'*', '*'},
	{'*', '/'},
	{'/', '+'},
	{'/', '-'},
	{'/', '*'},
	{'/', '/'}
};

ii go(int l, int r, char op) {
	if (op == '+') return {true, l+r};
	if (op == '-') return {true, l-r};
	if (op == '*') return {true, l*r};
	if (op == '/' && l % r == 0) return {true, l/r};
	return {false,0};
}


void check(int a, int b, int c) {
	if (a == N || b == N || c == N) return;

	vi v = {a,b,c};
	FOR(_,0,6) {
		FOR(o,0,16) {
			auto [valid, res] = go(v[0], v[1], ops[o].F);
			if (valid) {
				if (res == N) return;
				auto [valid2, res2] = go(res, v[2], ops[o].S);
				if (valid2 && res2 == N) return;
			}

			{
				auto [valid, res] = go(v[1], v[2], ops[o].S);
				if (valid) {
					if (res == N) return;
					auto [valid2, res2] = go(v[0], res, ops[o].F);
					if (valid2 && res2 == N) return;
				}
			}

			{
			}
		}

		next_permutation(v.begin(), v.end());
	}
	cout << a << " " << b << " " << c << endl;
	exit(0);
}


int main(){
	ri(N);
	FOR(a,1,101) FOR(b,a+1,101) FOR(c,b+1,101) check(a,b,c);

	return 0;
}
