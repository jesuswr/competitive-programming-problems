#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=998244353,MAXN=505;

ll dp[MAXN][MAXN];
ll comb[MAXN][MAXN];

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

vector<ll> a,sump;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(a))return res=1;
	res=0;
	if(a[x]==0)res=f(x+1,y);
	else{
		// cout<<"f "<<x<<" "<<y<<"\n";
		res=f(x+1,y);
		// cout<<"-> "<<res<<"\n";
		fore(i,1,a[x]+1){
			fore(j,i,sump[x+1]-y-(a[x]-i)){
				res=(res+f(x+1,y+j)*comb[j-1][i-1])%MOD;
			}
		}
		fore(i,1,a[x]+1){
			fore(j,i,sump[x+1]-y-(a[x]-i)){
				cout << "\t" << x + 1 << " " << y + j << " " << dp[x+1][y+j] << endl;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	sump={0};
	for(auto i:a)sump.pb(sump.back()+i);
	fore(i,0,MAXN){
		fore(j,0,i+1){
			if(j==0||j==i)comb[i][j]=1;
			else comb[i][j]=add(comb[i-1][j],comb[i-1][j-1]);
		}
	}
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}