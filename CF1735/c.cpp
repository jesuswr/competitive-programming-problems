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
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
string S;
vi NXT;

bool test() {
	vector<bool> VIS(26);

	FOR(i, 0, 26) if (!VIS[i]) {
		int sz = 0;
		int s = i;
		while (!VIS[s]) {
			VIS[s] = 1;
			sz++;
			if (NXT[s] != -1) {
				// printf("%c!!\n", 'a'+s);
				s = NXT[s];
				if (VIS[s] && sz != 26 && s == i) {
					// printf("AAA %c\n", 'a'+s);
					return false;
				}
			}
			else break;
		}
	}

	return true;
}

void solve() {
	ri(N);
	cin >> S;
	NXT.resize(26, -1);
	vector<bool> used(26);

	for (char c : S) {
		if (NXT[c - 'a'] != -1) {
			printf("%c", 'a' + NXT[c - 'a']);
			continue;
		};
		for (char l = 'a'; l <= 'z'; ++l) {
			if (l == c || used[l - 'a']) continue;
			NXT[c - 'a'] = l - 'a';
			used[l - 'a'] = 1;
			// printf("epa %c %c!\n", l, c);
			if (test()) break;
			used[l - 'a'] = 0;
			// printf("chao\n");
		}
		printf("%c", 'a' + NXT[c - 'a']);
	}
	printf("\n");

	NXT.clear();

}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}