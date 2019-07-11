#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10001];
int v,e;
int parent[10001];
int visited[10001];
int ans;

void dfs(int node){
    visited[node] = 1;

    if (ans == 1){
    	for (int w: graph[node]){
    		if (!visited[w]){
    			parent[w] = node;
    			dfs(w);
    		}
    		else{
    			if (parent[node]!=w){
    				
    				ans = 0;
    			}
    		}
    	}
    }

    visited[node] = 0;

}

void checkForTree(){
	for (int i = 1; i <= v; i++)
	{
		visited[i] = 0;
		parent[i] = -1;
	}

	dfs(1);

	if (ans == 1){
		for (int i = 2; i <= v; i++)
		{
			if (parent[i]==-1){
				ans = 0;
				break;
			}
		}
	}
}



int main(){
	scanf("%d %d",&v,&e);

	int n1,n2;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d",&n1,&n2);
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	ans = 1;

	checkForTree();

	if (ans ==1 ){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}


}

