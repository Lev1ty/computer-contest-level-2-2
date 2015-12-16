#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, adj[1002][1002];
vector<int>vec;
bool vis[1002];
void dfs(int u) {
	vis[u] = 1; vec.push_back(u);
	for (int i = 1; i <= N; i++)
		if (adj[u][i] && !vis[i])
			dfs(i);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> adj[i][j];
	for (int i = 1; i <= N; i++)
		if (!vis[i]) {
			dfs(i);
			sort(vec.begin(), vec.end());
			for (int j = 0; j < vec.size(); j++)
				cout << vec[j] << " ";
			cout << endl;
			vec.clear();
		}
}