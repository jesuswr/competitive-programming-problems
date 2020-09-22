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
const int MAXN = 2e6 + 19; // CAMBIAR ESTE

// GJNM
string s;
string s2;
int n;
int m;

pair<int, int> manacher() {
	vector<int> d1(m, 0);
	for (int i = 0, l = 0, r = -1; i < m; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s2[i - k] == s2[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}

	vector<int> d2(m, 0);
	for (int i = 0, l = 0, r = -1; i < m; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s2[i - k - 1] == s2[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	int left = 0, right = 0;
	FOR(i, 0, m) {
		if (i + 1 - d1[i] == 0)
			left = max(left, 2 * d1[i] - 1);
		if (m - i == d1[i])
			right = max(right, 2 * d1[i] - 1);

		if (i - d2[i] == 0)
			left = max(left, 2 * d2[i]);
		if (m - i == d2[i]) 
			right = max(right, 2 * d2[i]);
	}
	return {left, right};
}





void solve() {
	s2.clear();
	cin >> s;
	n = s.size();

	int l = 0, r = n - 1;
	while (l <= r && s[l] == s[r])
		l++, r--;
	if (l > r) {
		FOR(i, 0, n) {
			printf("%c", s[i]);
		}
		printf("\n");
		return;
	}
	FOR(i, l, r + 1) {
		s2.pb(s[i]);
	}
	m = s2.size();
	pair<int, int> p = manacher();

	if (p.F >= p.S) {
		FOR(i, 0, l + p.F) {
			printf("%c", s[i]);
		}
		FOR(i, r + 1, n) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	else {
		FOR(i, 0, l) {
			printf("%c", s[i]);
		}
		FOR(i, r - p.S + 1, n) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}