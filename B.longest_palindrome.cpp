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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
string words[101];
string wordsR[101];
bool used[101];

int main(){
	int n,m;
	rii(n,m);
	FOR(i,0,n){
		cin >> words[i];
		wordsR[i] = words[i];
		reverse(wordsR[i].begin(), wordsR[i].end());
	}

	string front, mid;
	FOR(i,0,n){
		if ( used[i] )
			continue;
		FOR(j,i+1,n){
			if ( used[j] )
				continue;
			if ( words[i] == wordsR[j] ){
				used[i] = used[j] = true;
				front += words[i];
			}
		}
		if ( !used[i] ){
			if ( words[i] == wordsR[i] && words[i].size() > mid.size() ){
				used[i] = true;
				mid += words[i];
			}
		}
	}
	cout << 2*front.size() + mid.size() << endl;
	cout << front << mid;
	reverse(front.begin(), front.end());
	cout << front << endl;
	
	return 0;
}