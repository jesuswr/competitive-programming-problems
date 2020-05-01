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
const int maxN = 1e5+20; // CAMBIAR ESTE

// GJNM
int cnt[30];
char inp[maxN];

int main(){
	int t;
	ri(t);
	while(t--){
		FOR(i,0,30)
			cnt[i] = 0;
			
		int n,k;
		rii(n,k);
		scanf("%s",inp);
		sort(inp,inp+n);
		int last = -1;
		FOR(i,k,n){
			cnt[inp[i]-'a']++;
			last = max(last, inp[i]-'a');
		}
		
		if ( inp[0] != inp[k-1] ){
			printf("%c\n",inp[k-1] );
			continue;
		}

		string s;
		s.push_back(inp[k-1]);
		int j = 0;
		bool equal = true;

		while(j<30){
			if ( cnt[j] == 0 ){
				j++;
				continue;
			}

			if ( equal ){
				if ( j == last ){
					while( cnt[j] > 0 ){
						s.push_back(j+'a');
						cnt[j] -= k;
					}
					j = 40;
				}
				else{
					equal = false;
				}
			}
			else{
				while( cnt[j] > 0 ){
					s.push_back(j+'a');
					cnt[j]--;
				}
				j++;
			}
		}

		cout << s << endl;
	}
	return 0;
}