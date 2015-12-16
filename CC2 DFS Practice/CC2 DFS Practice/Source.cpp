#include <iostream>
using namespace std;
int adj[9][9], vis[9], V, E;
void DFS(int v) {
	vis[v] = 1;
	for (int i = 1; i <= V; i++)
		if (adj[v][i] == 1 && vis[i] == 0)
			DFS(i);
}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int f, s; cin >> f >> s;
		adj[f][s]++; adj[s][f]++;
	}
	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << adj[i][j];
		cout << endl;
	}*/
	DFS(1);
	/*for (int i = 0; i < 9; i++)
		cout << vis[i];*/
	if (vis[7])cout << "Yes";
	else cout << "No";
}