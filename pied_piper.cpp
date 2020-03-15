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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int main(){
	int t;
	ri(t);
	while(t--){
		// A usuarios de mi empresa, ganan X usuarios
		// B usuarios de otra empresa, ganan Y usuarios
		// Z objetivo
		int N, A, B, X, Y, Z;
		riii(N,A,B);
		riii(X,Y,Z);
		priority_queue<int> pq;
		FOR(i,0,N){
			int aux;
			ri(aux);
			pq.push(aux);
		}
		int needsB, needsA;
		// turnos que necesitan B y A para ganar
		needsB = (Z-B)/Y + ( (Z-B)%Y == 0 ? 0 : 1 );
		needsA = (Z-A)/X + ( (Z-A)%X == 0 ? 0 : 1 );
		if (needsA<needsB)
			printf("0\n");
		else{
			bool good = false;
			int moves = 0;
			A += (needsB-1)*X;
			B += (needsB-1)*Y;
			while( !pq.empty() ){
				int aux = pq.top();
				pq.pop();
				if (aux>1)
					pq.push(aux>>1);

				A += aux;
				moves++;
				if (A>=Z){
					good = true;
					break;
				}
			}
			if ( good )
				printf("%d\n", moves);
			else
				printf("RIP\n");
		}
	}
	return 0;
}