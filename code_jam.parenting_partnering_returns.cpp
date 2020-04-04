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
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1005; // CAMBIAR ESTE

// GJNM
piii arr[maxN];
char s[maxN];

int main(){
	int t, t2;
	t = 1;
	ri(t2);

	while(t<=t2){
		int n;
		ri(n);
		FOR(i,0,n){
			rii(arr[i].f, arr[i].s.f);
			arr[i].s.s = i;
		}

		sort(arr,arr+n);

		priority_queue< pair<int,char> > pq;

		bool ans = true;

		FOR(i,0,n){
			while ( !pq.empty() && -pq.top().f <= arr[i].f )
				pq.pop();

			int sz = pq.size();
			if ( sz == 2 ){
				ans = false;
				break;
			}
			else if ( sz == 1 ){
				if ( pq.top().s == 'C' ){
					pq.push( {-arr[i].s.f, 'J'} );
					s[arr[i].s.s] = 'J';
				}
				else{
					pq.push( {-arr[i].s.f, 'C'} );
					s[arr[i].s.s] = 'C';
				}
			}
			else{
				pq.push( {-arr[i].s.f, 'C'} );
				s[arr[i].s.s] = 'C';
			}
		}
		s[n] ='\0';

		printf("Case #%d: ", t++);
		if (ans)
			cout << s << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}