#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 67183; // CAMBIAR ESTE

// GJNM
map<string, int> cnt_name;
int cnt_letter[30];

int main() {
	int n;
	ri(n);
	FOR(i, 0, n) {
		string a;
		cin >> a;
		cnt_name[a]++;
		cnt_letter[ a[0] - 'A' ]++;
	}
	ll ans = 0;
	for (auto s : cnt_name) {
		ans += s.S * (cnt_letter[s.F[0] - 'A'] - s.S);
	}
	printf("%lld\n", ans);
	return 0;
}