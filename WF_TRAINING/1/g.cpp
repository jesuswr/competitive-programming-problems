#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,p[400005],t[200005],pos[400005];
void add(int x){while(x<=n)++t[x],x+=(x&-x);}
int get(int x){int ret=0;while(x)ret+=t[x],x&=(x-1);return ret;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",p+i),p[n+i]=p[i];
		int k=1;
		for(int i=1;i<=n;++i)if(p[i]==1)k=i;
		for(int i=1;i<=n;++i)pos[p[i]=p[i+k-1]]=i;
		for(int i=1;i<=n;++i)t[i]=0;
		add(pos[1]),add(pos[2]);
		ll ans=0;
		for(int i=3;i<=n;++i){
			cout << "\t";
			cout << pos[i] << " " << pos[i-1] << endl;
			int k=get(pos[i])-get(pos[i-1]);
			if(k<0)k+=i-1;
			cout << "\t";
			cout << "\t";
			cout << k <<  "  " << (n - i + 1) << endl;
			ans+=k*1ll*(n-i+1);
			add(pos[i]);
		}
		printf("%lld\n",ans);
	}
    return 0;
}