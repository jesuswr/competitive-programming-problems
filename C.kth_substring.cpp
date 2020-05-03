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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 5005; // CAMBIAR ESTE

// GJNM
char A[maxN];
set<string> unq;

int main(){
	int k;
	scanf("%s", A);
	ri(k);
	int n = strlen(A);
	priority_queue<string> pq;
	FOR(i,0,n){
		string s;
		int j = i;
		while(j<n && j-i <=5){
			s += A[j];
			j++;
			if ( unq.count(s) > 0 ){
				continue;
			}
			else{
				unq.insert(s);
			}
			
			if ( pq.size() < k ){
				pq.push(s);
			}
			else{
				if ( s.compare(pq.top()) < 0 ){
					pq.pop();
					pq.push(s);
				}
			}
		}
	}
	cout<< pq.top() << endl;
	return 0;
}