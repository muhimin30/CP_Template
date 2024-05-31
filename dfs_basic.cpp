#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 23;
vector<int> g[N];
bool vis[N];
void dfs(int vertex){
	vis[vertex] = true;

	for(auto child:g[vertex]){
		if(vis[child]){
			continue;
		}	
		dfs(child);
	}
}