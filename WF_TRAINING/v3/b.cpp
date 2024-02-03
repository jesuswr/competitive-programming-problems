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
const int MAXN = 1000+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int C, N;
int A[MAXN];

bool DP[MAXN][MAXN];
void f() {
	DP[0][0] = 1;

	int ans = -1;
	int v1 = 0, v2 = 0;

	for(int p = 0; p < N; ++p) {
		for(int c1 = C; c1 >= 0; c1--) {
			for(int c2 = C; c2 >= 0; c2--) {
				if (c1 >= A[p]) DP[c1][c2] = max(DP[c1][c2], DP[c1-A[p]][c2]);
				if (c2 >= A[p]) DP[c1][c2] = max(DP[c1][c2], DP[c1][c2-A[p]]);
				if (DP[c1][c2]) {
					if (ans < c1 + c2) {
						ans = c1 + c2;
						v1 = max(c1, c2);
						v2 = min(c1, c2);
					}
					else if (ans == c1 + c2 && abs(v1-v2) > abs(c1-c2)) {
						v1 = max(c1, c2);
						v2 = min(c1, c2);
					}
				}
			}
		}
	}

	printf("%d %d\n", v1, v2);
}

int main(){
	rii(C,N);
	FOR(i,0,N) ri(A[i]);
	f();
	return 0;
}
