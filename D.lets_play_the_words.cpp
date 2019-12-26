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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
set<string> st;
vector<string> v;
int sw[maxN];
stack<int> zeroone, onezero;

void clean(){
	st.clear();
	v.clear();
	while(!zeroone.empty())
		zeroone.pop();
	while(!onezero.empty())
		onezero.pop();
}

int main()
{
	int t;
	ri(t);
	while( t-- ){
		int n;
		ri(n);
		int oo , zz , oz , zo ;
		oo = zz = oz = zo = 0;
		FOR(i,0,n){
			string s;
			cin >> s;
			if ( s[0] == '0' && s[s.length()-1] == '0'){
				zz++;
				sw[i] = 0;
			}
			else if ( s[0] == '1' && s[s.length()-1] == '0'){
				oz++;
				sw[i] = 2;
			}
			else if ( s[0] == '1' && s[s.length()-1] == '1'){
				sw[i] = 3;
				oo++;
			}
			else if ( s[0] == '0' && s[s.length()-1] == '1'){
				sw[i] = 1;
				zo++;
			}
			st.insert(s);
			v.pb(s);
		}
		FOR(i,0,n){
			if ( sw[i] == 0 || sw[i] == 3 ) continue;
			string x = v[i];
			reverse( x.begin() , x.end() );
			if ( st.find(x) == st.end()){
				if ( sw[i] == 1 ){
					zeroone.push(i+1);
				}
				else{
					onezero.push(i+1);
				}
			}
		}
		if ( zz > 0 && oo > 0 && zo == 0 && oz == 0 ){
			printf("-1\n");
		}
		else{
			if ( abs( zo - oz ) > 1 ){
				int need = (abs(zo-oz))/2;
				if ( zo > oz ){
					if ( zeroone.size() >= need ){
						printf("%d\n", need);
						FOR(i,0,need){
							printf("%d ", zeroone.top());
							zeroone.pop();
						}
						printf("\n");
					}
					else{
						printf("-1\n");
					}
				}
				else{
					if ( onezero.size() >= need ){
						printf("%d\n", need);
						FOR(i,0,need){
							printf("%d ", onezero.top());
							onezero.pop();
						}
						printf("\n");

					}
					else{
						printf("-1\n");
					}
				}
			}
			else{
				printf("0\n");
			}
		}
		clean();

	}
	return 0;
}