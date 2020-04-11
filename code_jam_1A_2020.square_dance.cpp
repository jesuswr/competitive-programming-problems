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
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
map<int,int> rows[maxN], cols[maxN];
map<pii,int> alive;

bool check(int r, int c){
	auto top = cols[c].lb(r);
	auto bottom = cols[c].lb(r);
	auto right = rows[r].lb(c);
	auto left = rows[r].lb(c);
	int total = 0;

	int to,bo,ri,le;
	to = bo = ri = le = 0;

	if ( top != cols[c].begin() ){
		top--;
		to = top->second;
		total++;
	}
	bottom++;
	if ( bottom != cols[c].end() ){
		bo = bottom->second;
		total++;
	}

	if ( left != rows[r].begin() ){
		left--;
		le = left->second;
		total++;
	}
	right++;
	if ( right != rows[r].end() ){
		ri = right->second;
		total++;
	}

	return alive[{r,c}]*total < to+bo+ri+le;
}

int main(){
	int t;
	ri(t);
	FOR(k,1,t+1){
		int r,c;
		rii(r,c);
		FOR(i,0,r){
			FOR(j,0,c){
				int aux;
				ri(aux);
				alive[{i,j}] = aux;
				rows[i][j] = aux;
				cols[j][i] = aux;
			}
		}
		ll total = 0;
		bool change = true;
		while( change ){
			vector< pii > delet;
			change = false;

			for(auto p : alive){
				total += p.s;

				if ( check(p.f.f, p.f.s) ){
					change = true;
					delet.push_back(p.f);
				}
			}

			for(auto p : delet){
				alive.erase(p);
				rows[p.f].erase(p.s);
				cols[p.s].erase(p.f);
			}
		}

		alive.clear();
		FOR(i,0,r)
			rows[i].clear();
		FOR(i,0,c)
			cols[i].clear();
		printf("Case #%d: %lld\n",k , total);
		
	}
	return 0;
}