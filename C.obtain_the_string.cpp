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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
void solve() {
	set<int> alpha[30];
	int cnt[30];
	string s, t;
	cin >> s >> t;
	FOR(i, 0, s.size()) {
		alpha[s[i] - 'a'].insert(i);
	}
	FOR(i, 0, 30) {
		cnt[i] = 0;
	}
	for (auto c : t) {
		cnt[c - 'a']++;
	}
	FOR(i, 0, 30) {
		if (cnt[i] > 0 && alpha[i].size() == 0) {
			printf("-1\n");
			return;
		}
	}

	int curr = -1;
	int moves = 1;
	FOR(i, 0, t.size()) {
		auto it = alpha[t[i] - 'a'].lb(curr);
		if (it == alpha[t[i] - 'a'].end()) {
			moves++, i--, curr = -1; continue;
		}

		curr = *it + 1;
	}

	printf("%d\n", moves);
}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}