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
#define ri(a) das=scanf("%d\n", &a)
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
const int MAXN = 4e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N,Q;
char S[MAXN];
bool P[MAXN];

void press(int i) {
    int aux = i;
    while(aux <= N) {
        if (S[aux] == '0') S[aux] = '1';
        else S[aux] = '0';
        aux += i;
    }
}

void solve() {
    ri(N);
    das=scanf("%s\n", S+1);
    ri(Q);
    FOR(i,0,Q) {
        int b; ri(b);
        P[b] = P[b] ^ true;
    }

    FOR(i,1,N+1) if (P[i]) {
        press(i);
    }

    int ans = 0;
    FOR(i,1,N+1) if (S[i] == '1') {
        ans++;
        press(i);
    }
    printf("%d\n", ans);
    FOR(i,1,N+1) P[i] = 0;
}


int main(){
	int t; ri(t);
	FOR(i,1,t+1) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
