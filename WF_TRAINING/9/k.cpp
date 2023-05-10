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


int main(){
	int t = 0;
	set<ii> st;
	st.insert({0, 0});

	while(1) {
		++t;
		set<ii> new_st;
		for(auto [x,y] : st) {
			new_st.insert({x+1, y+2});
			new_st.insert({x+1, y-2});
			new_st.insert({x-1, y+2});
			new_st.insert({x-1, y-2});
			new_st.insert({x+2, y+1});
			new_st.insert({x+2, y-1});
			new_st.insert({x-2, y+1});
			new_st.insert({x-2, y-1});
		}
		int aux = sz(st);
		for(auto [x,y] : new_st) st.insert({x,y});
		aux = sz(st) - aux;
		cout << t << " " << sz(st) << "    " << aux << endl;

		string f; cin >> f;
	}

	return 0;
}
