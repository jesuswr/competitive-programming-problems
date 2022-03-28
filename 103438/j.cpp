#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N;
int A[MAXN];
string S;

int main() {
    ri(N);
    cin >> S;
    FOR(i, 0, 2 * N) A[i] = S[i] - 'A';

    int cnt[3] = {0, 0, 0};
    FOR(i, 0, 2 * N) cnt[A[i]]++;

    if (cnt[2] < abs(cnt[0] - cnt[1]) || cnt[2] > cnt[0] + cnt[1]) {
        printf("NO\n");
        return 0;
    }

    int del[3] = {0, 0, 0};
    if (cnt[0] > cnt[1]) {
        del[0] += cnt[0] - cnt[1];
        cnt[2] -= del[0];
    }
    else if (cnt[1] > cnt[0]) {
        del[1] += cnt[1] - cnt[0];
        cnt[2] -= del[1];
    }

    if (cnt[2] & 1) {
        printf("NO\n");
        return 0;
    }

    del[0] += cnt[2] / 2;
    del[1] += cnt[2] / 2;


    vii ans;

    deque<int> dq[3];
    FOR(i, 0, 2 * N) {
        if (A[i] == 0) dq[0].push_back(i);
        else if (A[i] == 1) dq[1].push_back(i);
        else {
            if (del[1] && !dq[1].empty()) {
                del[1]--;
                ans.pb({dq[1].front(), i});
                dq[1].pop_front();
            }
            else if (del[0] && !dq[0].empty()) {
                del[0]--;
                ans.pb({dq[0].back(), i});
                dq[0].pop_back();
            }
            else {
                printf("NO\n");
                return 0;
            }
        }
    }

    while (!dq[0].empty()) {
        if (dq[0].front() > dq[1].front()) {
            printf("NO\n");
            return 0;
        }
        ans.pb({dq[0].front(), dq[1].front()});
        dq[0].pop_front();
        dq[1].pop_front();
    }

    printf("YES\n");
    for (auto [l, r] : ans) printf("%d %d\n", l + 1, r + 1);
    return 0;
}
