#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


typedef double T; // long double, Rational, double + mod<P>...
const T EPS = 1e-8;

vector<int> X,Y;
vector<vector<T> > A;
vector<T> b,c;
T z;
int n,m;
void pivot(int x,int y){
    swap(X[y],Y[x]);
    b[x]/=A[x][y];
    FOR(i,0,m)if(i!=y)A[x][i]/=A[x][y];
    A[x][y]=1/A[x][y];
    FOR(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
        b[i]-=A[i][y]*b[x];
        FOR(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
        A[i][y]=-A[i][y]*A[x][y];
    }
    z+=c[y]*b[x];
    FOR(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
    c[y]=-c[y]*A[x][y];
}
bool simplex( // maximize c^T x s.t. Ax<=b, x>=0
        vector<vector<T> > _A, vector<T> _b, vector<T> _c){
    // returns pair (maximum value, solution vector)
    A=_A;b=_b;c=_c;
    n=b.size();m=c.size();z=0.;
    X=vector<int>(m);Y=vector<int>(n);
    FOR(i,0,m)X[i]=i;
    FOR(i,0,n)Y[i]=i+m;
    while(1){
        int x=-1,y=-1;
        double mn=-EPS;
        FOR(i,0,n)if(b[i]<mn)mn=b[i],x=i;
        if(x<0)break;
        FOR(i,0,m)if(A[x][i]<-EPS){y=i;break;}
       	if (y < 0) return false;
        pivot(x,y);
    }
    while(1){
        T mx=EPS;
        int x=-1,y=-1;
        FOR(i,0,m)if(c[i]>mx)mx=c[i],y=i;
        if(y<0)break;
        T mn=1e200;
        FOR(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
        assert(x>=0); // c^T x is unbounded creo que nunca pasa
        pivot(x,y);
    }
    return true;
}


void solve() {
	int n, m; rii(n, m);
	vi a(n);
	FOR(i,0,n) ri(a[i]);

	vector< vi > good_msks(n);
	FOR(msk,0,1<<n) {
		int sm = 0;
		FOR(i,0,n) if (msk & (1 << i)) {
			sm += a[i];
		}
		if (sm <= m) {
			FOR(i,0,n) if (msk & (1 << i)) {
				good_msks[i].pb(msk);
			}	
		}
	}

	double lo = 0, hi = 1;
	FOR(i,0,60) {
		double mi = (lo + hi) / 2;
		vector<vector<T>> A(2 * n + 2, vector<T>(1 << n, 0));
		vector<T> B(2 * n + 2);
		FOR(i,0,n) {
			for(int msk : good_msks[i]) {
				A[2 * i][msk] = 1;
				A[2 * i + 1][msk] = -1;
			}
			B[2*i] = mi + EPS;
			B[2*i+1] = -mi + EPS;
		}

		FOR(i,0,1 << n) {
			A[2*n][i] = 1;
			A[2*n+1][i] = -1;

			B[2*n] = 1 + EPS;
			B[2*n+1] = -1 + EPS;
		}

		vector<T> C(1 << n, 1);

		if (simplex(A, B, C))
			lo = mi;
		else
			hi = mi;

	}

	printf("%.10lF\n", lo);


}


int main(){
	int t; ri(t);
	FOR(i,1,t+1) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
