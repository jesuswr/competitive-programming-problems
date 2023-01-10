#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dadsda;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dadsda=scanf("%d\n", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dadsda=scanf("%lld", &a)
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


/**
 * Author: el vasito
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * Time: $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on CF-498C
 */

struct edge {int to,rev;int f,cap;};
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),dist(x),q(x),work(x),g(x){}
	void add_edge(int s, int t, int cap){
		g[s].pb((edge){t,sz(g[t]),0,cap});
		g[t].pb((edge){s,sz(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(all(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			FOR(i,0,sz(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	int dinic_dfs(int u, int f){
		if(u==dst)return f;
		for(int &i=work[u];i<sz(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				int df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	int max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		int result=0;
		while(dinic_bfs()){
			fill(all(work),0);
			while(int delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};


vector<string> split_spaces(string inp){
	vector<string> ret;
	string aux;
	inp.pb(' ');
	for(auto c : inp){
		if (c == ' '){
			ret.pb(aux);
			aux.clear();
		}
		else{
			aux.pb(c);
		}
	}
	return ret;
}


int N_CLUBS, N_PEOPLE, N_PARTIES;

map<string, int> CLUB_TO_INT, PEOPLE_TO_INT, PARTY_TO_INT;
map<int, string> INT_TO_CLUB, INT_TO_PEOPLE, INT_TO_PARTY;
vector<vector<string>> INP;


void input(){
	CLUB_TO_INT.clear(), PEOPLE_TO_INT.clear(), PARTY_TO_INT.clear();
	INT_TO_CLUB.clear(), INT_TO_PEOPLE.clear(), INT_TO_PARTY.clear();
	INP.clear();
	N_CLUBS = N_PEOPLE = N_PARTIES = 0;

	string line;
	while(getline(cin, line) && sz(line) > 0){
		auto tks = split_spaces(line);
		INP.pb(tks);

		string person = tks[0], party = tks[1];

		PEOPLE_TO_INT[person] = N_PEOPLE;
		INT_TO_PEOPLE[N_PEOPLE] = person;
		++N_PEOPLE;

		if (PARTY_TO_INT.find(party) == PARTY_TO_INT.end()){
			PARTY_TO_INT[party] = N_PARTIES;
			INT_TO_PARTY[N_PARTIES] = party;
			N_PARTIES++;
		}

		for(int i = 2; i < sz(tks); ++i){
			string club = tks[i];
			if (CLUB_TO_INT.find(club) == CLUB_TO_INT.end()){
				CLUB_TO_INT[club] = N_CLUBS;
				INT_TO_CLUB[N_CLUBS] = club;
				N_CLUBS++;
			}
		}
	}
}


void solve(){
	input();
	int sz = N_CLUBS + N_PARTIES + N_PEOPLE + 3;
	Dinic mxf(sz);
	mxf.add_edge(0,1,N_CLUBS);
	for(auto const [club, id] : CLUB_TO_INT){
		mxf.add_edge(1, id+2, 1);
	}
	for (auto const line : INP){
		auto person = line[0], party = line[1];
		mxf.add_edge(PEOPLE_TO_INT[person] + 2 + N_CLUBS, PARTY_TO_INT[party] + 2 + N_CLUBS + N_PEOPLE, 1);
		for(int i = 2; i < sz(line); ++i){
			auto club = line[i];
			mxf.add_edge(CLUB_TO_INT[club] + 2, PEOPLE_TO_INT[person] + 2 + N_CLUBS, 1);
		}
	}
	for(auto const [party, ind] : PARTY_TO_INT){
		mxf.add_edge(ind + 2 + N_CLUBS + N_PEOPLE, sz - 1, (N_CLUBS - 1) / 2);
	}

	int ans = mxf.max_flow(0, sz-1);


	if (ans < N_CLUBS){
		printf("Impossible.\n");
	}
	else{
		for(int p = 2; p < 2 + N_CLUBS; p++){
			for (auto e : mxf.g[p]){
				if (e.cap == 1 && e.f == 1){
					cout << INT_TO_PEOPLE[e.to - 2 - N_CLUBS] << " " << INT_TO_CLUB[p - 2] << endl;
				}
			}
		}
	}

}

int main(){
	int t; ri(t);
	while(t--) {
		solve();
		if (t > 0) printf("\n");
	}
	return 0;
}
