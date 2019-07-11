#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color[2001];
int cond;

void bfs(vector<int> g[], int w){
	queue<int> cola;
	color[w] = 1;
	cola.push(w);
	int aux;
	while(!cola.empty() && cond ==1) {
	    aux = cola.front();
	    cola.pop();
	    for (int x: g[aux]){

	    	if (color[x]==color[aux])
	    	{
	    		cond = 0;
	    		return;
	    	}
	    	if (color[x]==-1)
	    	{
	    		color[x] = 1 - color[aux];
	    		cola.push(x);
	    	}

	    }
	}

}




int main(){
	int n;
	int v,e;
	int n1,n2;
	scanf("%d",&n);
	for (int l = 1; l <= n; l++)
	{
		scanf("%d %d",&v,&e);
		vector<int> graph[v+1];
		cond = 1;

		for (int i = 0; i < e; i++)
		{
			scanf("%d %d",&n1,&n2);
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}

		for (int i = 1; i <= v; i++)
		{
			color[i] = -1;
		}

		for (int i = 1; i <= v; i++)
		{
			if (color[i]==-1 && cond==1){
				bfs(graph,i);
			}
			if (cond==0) break;
		}

		printf("Scenario #%d:\n", l);

		if (cond==0)
		{
			printf("Suspicious bugs found!\n");
		}
		else{
			printf("No suspicious bugs found!\n");
		}
	}
}