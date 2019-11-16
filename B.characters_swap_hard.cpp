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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 55; // CAMBIAR ESTE

// GJNM
char s[maxN], t[maxN];
int n;
int arr[30];
queue<pii> q;

int main()
{
	int k;
	ri(k);
	while(k--){
		bool ans = true;
		ri(n);
		scanf("%s",s);
		scanf("%s",t);
		FOR(i,0,n){
			arr[ (int)(s[i]-'a') ] ++;
			arr[ (int)(t[i]-'a') ] ++;
		}
		FOR(i,0,29){
			if ( arr[i] & 1 ) ans = false;
		}
		if ( ! ans ) printf("No\n");
		else{
			printf("Yes\n");
			FOR(i,0,n){
				if ( s[i] != t[i] ){
					for(int j = i+1; j < n ; j++){
						if ( s[j] == s[i] ){
							q.push({j+1,i+1});
							s[j] = t[i];
							break;
						}
						else if ( t[j] == t[i] ){
							q.push({i+1,j+1});
							t[j] = s[i];
							break;
						}
						else if ( s[j] == t[i]){
							q.push({j+1,j+1});
							char aux = s[j];
							s[j] = t[j];
							t[j] = aux;
							q.push({i+1,j+1});
							t[j] = s[i];
							break;
						}
						else if ( s[i] == t[j] ){
							q.push({j+1,j+1});
							char aux = s[j];
							s[j] = t[j];
							t[j] = aux;
							q.push({j+1,i+1});
							s[j] = t[i];
							break;
						}
					}
				}
			}
			printf("%d\n",(int)q.size() );
			while (!q.empty()){
				printf("%d %d\n", q.front().first, q.front().second);
				q.pop();
			}
		}

		FOR(i,0,29) arr[i] = 86420;
	}
	return 0;
}