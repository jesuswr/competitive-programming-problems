#include <iostream>
#include <queue>

using namespace std;

int dasds;

typedef long long ll;
typedef pair < int, int > ii;
 
const int MAXN = 1e5 + 5;

int n, m;
ll sum;
int a[MAXN], d[MAXN], cnt[MAXN];

ll getMaxTime(int x) {
	return ((cnt[x] + 1) * sum - 1) / a[x] + 1;
}

ll getMinTime(int x) {
	return cnt[x] * sum / a[x] + 1;
}

int main() {
	dasds=scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		dasds=scanf("%d", a + i);
		sum += a[i];
	}
	for(int i = 1; i <= m; i++) {
		dasds=scanf("%d", d + i);
		cnt[d[i]]++;
	}

	priority_queue < pair<ll,ll>, vector < pair<ll,ll> >, greater < pair<ll,ll> > > q1, q2;
	for(int i = 1; i <= n; i++) {
		q2.push({getMinTime(i), i});
	}

	for(int day = m + 1; day < 1e6; day++) {
		while(q2.size() and q2.top().first <= day) {
			int i = q2.top().second;
			q1.push({getMaxTime(i), i});
			q2.pop();
		}
		if(!q1.size() or q1.top().first < day) {
			printf("%d\n", day - 1 - m);
			return 0;
		}
		int i = q1.top().second;
		q1.pop();
		if(q1.size() and q1.top().first == day) {
			printf("%d\n", day - 1 - m);
			return 0;
		}
		cnt[i]++;
		q2.push({getMinTime(i), i});
	}
    printf("forever\n");

    return 0;
}
