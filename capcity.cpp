#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

const int maxN = 100005;
int v, e;
int cont;

int visited[maxN];
int comp[maxN];
stack<int> st;
vector<int> graph[maxN];
vector<int> graphT[maxN];
vector<int> graphCC[maxN];
int answers[maxN];


void dfs1(int x)
{
	visited[x] = 1;

	for (int y: graph[x])
	{
		if ( !visited[y] ) dfs1(y);
	}

	st.push(x);
}


void dfs2(int x)
{
	visited[x] = 2;
	graphCC[comp[x]].push_back(x);

	for (int y: graphT[x])
	{
		if ( visited[y] == 1)
		{
			comp[y] = comp[x];
			dfs2(y);
		}
	}
}

void dfs3(int w){
	int count = 0;
	stack<int> pila;
	pila.push(w);
	int aux;
	visited[w] = 1;
	while(!pila.empty()) {
	    count++;
	    aux = pila.top();
	    pila.pop();
	    //printf("Entro con %d y visito a %d\n", w, aux );
	    for ( int x: graphT[aux]){
	    	if (!visited[x])
	    	{
	    		visited[x] = 1;
	    		pila.push(x);
	    	}
	    }
	}
 
	if (count==v)
	{
		answers[comp[w]] =1;
	}
}


void kosaraju()
{
	for (int i = 1; i <= v; ++i)
	{
		if ( !visited[i] ) dfs1(i);
	}

	cont = 0;
	int aux;

	while( !st.empty() ) 
	{
	    aux = st.top();
	    st.pop();

	    if ( visited[aux] == 1 )
	    {
	    	comp[aux] = cont;
	    	dfs2(aux);
	    	cont ++;
	    }
	}
}

int main(){
 
	scanf("%d %d", &v, &e);
 
	if (v==1){
		printf("1\n1\n");
		return 0;
	}
 
	int n1, n2;
 
	for (int i = 0; i < e; ++i)
	{
		scanf("%d %d", &n1, &n2);
		graph[n1].push_back(n2);
		graphT[n2].push_back(n1);
	}
 
	kosaraju();

	for (int i = 0; i < cont; ++i)
	{
		for (int i = 1; i <= v; ++i)
		{
			visited[i] = 0;
		}
		dfs3(graphCC[i][0]);
	}

	queue<int> print;

	for (int i = 1; i <= v; ++i)
	{
		if (answers[comp[i]] == 1)
		{
			print.push(i);
		}
	}
	n1 = print.size();
	printf("%d\n", n1 );
	while(!print.empty()) 
	{
	    n1 = print.front();
	    print.pop();
	    printf("%d ", n1);
	}
	printf("\n");
 
	
 
} 