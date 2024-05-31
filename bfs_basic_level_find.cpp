#include <bits/stdc++.h>
using namespace std;

const int N = 123;
vector<int> g[N];
bool vis[N];
int level[N];

void bfs(int vertex){
	queue<int> q;

	q.push(vertex);
	level[vertex] = 1;
	vis[vertex] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(auto ch: g[cur]){
			if(vis[ch]) continue;
			q.push(ch);
			level[ch] = level[cur] + 1;
			vis[ch] = true;
		}
	}
}