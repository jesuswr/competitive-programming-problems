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
	int n, k;
	rii(n, k);
	string s;
	cin >> s;
	FOR(i, 0, k) {
		int btmsk = 0;
		int j = i;
		while (j < n) {
			if (s[j] != '?')
				btmsk |= (1 << (s[j] - '0'));
			j += k;
		}
		if (btmsk == 3) {
			printf("NO\n");
			return;
		}
		if (btmsk == 2) {
			int j = i;
			while (j < n) {
				s[j] = '1';
				j += k;
			}
		}
		if (btmsk == 1) {
			int j = i;
			while (j < n) {
				s[j] = '0';
				j += k;
			}
		}
	}
	int cnt[3] = {0, 0, 0};
	FOR(i, 0, k) {
		if (s[i] == '?')
			continue;
		cnt[ s[i] - '0' ]++;
	}
	if (cnt[0] > k / 2 || cnt[1] > k / 2) {
		printf("NO\n");
		return;
	}
	FOR(i, k, n) {
		if (s[i - k] != '?')
			cnt[s[i - k] - '0']--;
		if (s[i] != '?')
			cnt[s[i] - '0']++;
		if (cnt[0] > k / 2 || cnt[1] > k / 2) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");

}


int main() {
	int t;
	ri(t);
	while (t--)
		solve();

	return 0;
}