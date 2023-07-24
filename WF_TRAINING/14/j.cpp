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
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 3e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int H[MAXN];
ll S, E;

int L[MAXN], R[MAXN];
void calc_l_r() {
    stack<int> st;
    FOR(i,0,N) {
        while(!st.empty() && H[st.top()] > H[i]) st.pop();
        if (st.empty()) L[i] = 0;
        else L[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = N-1; i >= 0; --i) {
        while(!st.empty() && H[st.top()] >= H[i]) st.pop();
        if (st.empty()) R[i] = N-1;
        else R[i] = st.top() - 1;
        st.push(i);
    }
}

ll g(ll w, ll len) { // get_number_of_rectangles_whith_leq_width_than
    w = min(w, len);
    return w * (len + 1) - w * (w+1) / 2;
}
ll g2(ll len, ll w) { // get_number_of_rectangles_whith_less_width_than
    return max(0ll, len - w + 1);
}

ll f(ll a) {
    ll ans = 0;
    FOR(i,0,N) {
        ll mx_w = a / H[i];
        ans += g(mx_w, R[i] - L[i] + 1) - g(mx_w, i - L[i]) - g(mx_w, R[i] - i);
    }
    return ans;
}

int main(){
    ri(N);
    FOR(i,0,N) ri(H[i]);
    lrii(S, E);
    calc_l_r();

    ll lo = 0, hi = 1e15;
    while(lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        if (f(mi) >= S) hi = mi;
        else lo = mi + 1;
    }

    ll lft = S - 1 - (lo == 1 ? 0 : f(lo - 1));

    priority_queue< tuple<ll, ll, ll, int> > pq;
    FOR(i,0,N) {
        ll w = (lo + H[i] - 1) / H[i];
        ll cap = g2(R[i] - L[i] + 1, w) - g2(R[i] - i, w) - g2(i - L[i], w);
        if (w * H[i] == lo) {
            ll take = min(cap, lft);
            lft -= take;
            cap -= take;
        }
        pq.push({-H[i] * w, w, cap, i});
    }

    while(1) {
        auto [area, width, cap, i] = pq.top(); pq.pop();
        while(cap-- && S <= E) {
            printf("%lld ", -area);
            ++S;
        }
        if (S > E) break;

        width++;
        auto new_cap = g2(R[i] - L[i] + 1, width) - g2(R[i] - i, width) - g2(i - L[i], width);
        if (new_cap > 0) {
            pq.push({-H[i] * width, width, new_cap, i});
        }
    }
    printf("\n");
    

	return 0;
}
