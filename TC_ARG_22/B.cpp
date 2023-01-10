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

string S;
int N;
vector<string> P;

bool have[MAXN];
bool havel[MAXN];
bool haver[MAXN];

int f(char a, char b){
	return 30 * (a - 'a' + 1) + (b - 'a' + 1);
}
int f(char a){
	return a - 'a';
}

void go(string s, int l, int r) {
	while(l + 1 < r) {
		if (!have[ f(s[l], s[l+1]) ]) return;
		l += 2;
	}
	if (l < r && !havel[f(s[l])]) return;
	printf("YES\n");
	exit(0);
}


int main(){
	cin >> S;
	ri(N);
	P.resize(N);
	FOR(i,0,N) cin >> P[i];
	
	FOR(i,0,N) {
		havel[f(P[i][0])] = 1;
		haver[f(P[i][1])] = 1;
		have[ f(P[i][0], P[i][1])] = 1;
	}

	go(S, 0, sz(S));
	if (haver[f(S[0])]) go(S, 1, sz(S));

	printf("NO\n");
	return 0;
}
