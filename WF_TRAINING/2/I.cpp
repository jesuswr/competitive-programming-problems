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
const int MAXN = 4000;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string get_msk(int x) {
	string r = "";
	FOR(i,0,7) {
		r.push_back('0' + (x&1));
		x >>= 1;
	}
	return r;
}

string int_to_roman(int a) // marico el que lo lea
{
    string ans;
    string M[] = {"","M","MM","MMM"};
    string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    ans = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
    return ans;
}

int remove_bit(int msk, int a, int b) {
	return msk & ((1 << 7) - 1 - (1 << a)) & ((1 << 7) - 1 - (1 << b));
}

string A = "MDCLXVI";
array<ll, 7> CNT;

bool add(vector< tuple< string, ll, int > > & ret, array<ll, 7> &cnt, int p, int p_oc, int extra = -1) {
	vector< tuple< string, ll, int > > new_r;
	for(auto &[str, occ, msk] : ret) {
		if (~msk & (1 << p) || cnt[p] == 0)
			new_r.emplace_back(str, occ, msk);
		else {
			if (p_oc == 1) {
				ll add = min(cnt[p], occ);
				cnt[p] -= add;
				occ -= add;
				if (add > 0) new_r.emplace_back(str + A[p], add, msk);
				if (occ > 0) new_r.emplace_back(str, occ, msk);
			}
			else { // p_oc == 3
				ll add = min(cnt[p] / 3, occ);
				cnt[p] -= 3 * add;
				occ -= add;
				if (add > 0) new_r.emplace_back(str + A[p] + A[p] + A[p], add, msk);
				if (cnt[p] > 0 && occ > 0) {
					--occ;
					assert(cnt[p] <= 2);
					if (cnt[p] == 1) new_r.emplace_back(str + A[p], 1, msk);
					if (cnt[p] == 2) new_r.emplace_back(str + A[p] + A[p], 1, msk);
					cnt[p] = 0;

				}
				if (occ > 0) new_r.emplace_back(str, occ, msk);
			}
		}
	}
	ret = new_r;
	if (extra != -1 && cnt[p] > 0 && cnt[extra] >= cnt[p]) {
		// cout << "*";
		new_r.clear();
		for(auto &[str, occ, msk] : ret) {
			if (cnt[p] == 0)
				new_r.emplace_back(str, occ, msk);
			else {
				ll add = min(cnt[p], occ);
				cnt[p] -= add;
				cnt[extra] -= add;
				occ -= add;
				if (add > 0) new_r.emplace_back(str + A[extra] + A[p], add, remove_bit(msk, p+1, p+2));
				if (occ > 0) new_r.emplace_back(str, occ, msk);
			}
		}
		ret = new_r;
	}
	// cout << A[p] << "  " << cnt[p] << endl;
	// for(auto [str, occ, _] : ret) cout << "    " << str << " " << occ << " " << get_msk(_) << endl;
	return cnt[p] == 0;
}

vector< tuple< string, ll, int > > go(ll sz) {
	vector< tuple< string, ll, int > > ret = { {"", sz, (1 << 7) - 1} };
	array<ll, 7> CNT_AUX = CNT;
	if (
		   !add(ret, CNT_AUX, 0, 3, 2) 
		|| !add(ret, CNT_AUX, 1, 1)
		|| !add(ret, CNT_AUX, 2, 3, 4)
		|| !add(ret, CNT_AUX, 3, 1)
		|| !add(ret, CNT_AUX, 4, 3, 6)
		|| !add(ret, CNT_AUX, 5, 1)
		|| !add(ret, CNT_AUX, 6, 3)
		) {
			ret.clear();
			return ret;
		}
	return ret; 
}

int main(){
	FOR(i,0,7) lri(CNT[i]);

	ll lo = 1, hi = 1e18;
	while(lo < hi) {
		ll mi = lo + (hi - lo) / 2;
		if (!go(mi).empty()) hi = mi;
		else lo = mi + 1;
	}
	cout << lo << endl;
	auto ans = go(lo);
	cout << sz(ans) << endl;
	for(auto [str, occ, _] : ans) {
		cout << str << " " << occ << endl;
	}

	return 0;
}
