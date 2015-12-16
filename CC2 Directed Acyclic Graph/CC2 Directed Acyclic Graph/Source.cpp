//Cyclic?
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>list;
queue<int>s_node;
int adj[1002][1002], N, nodes[1002];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adj[i][j];
		}
	}
	//input
	for (int c = 1; c <= N; c++) {
		for (int r = 1; r <= N; r++) {
			if (adj[r][c]==1) break;
			if (r = N) s_node.push(c);
		}
	}
	//find s_node
	if (s_node.empty()) {
		if (adj[N - 1][N] == adj[N][1]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	//case s_node is empty
	else {
		while (!s_node.empty()){
			int node = s_node.front(); s_node.pop(); list.push_back(node);
			//set first layer of search, hold for output first layer of search
			nodes[node] = -1;
			for (int i = 1; i <= N; i++) {
				if (adj[node][i]==1) {
					adj[node][i] = 0;//erase edge
					bool flag = false;
					for (int j = 1; j <= N; j++) {
						if (adj[j][i] == 1) {
							flag = true;
						}
					}
					if (!flag) s_node.push(i);
					//check if degree is 0
				}
				//if found edge
			}
			//search for 2nd layer connections
		}
		//While there are remaining edges
		for (int i = 1; i <= N; i++) {
			if (nodes[i] != -1) {
				cout << "YES" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;
		for (int i = 0; i < list.size() - 1; i++)
			cout << list[i] << " ";
		cout << endl;
	}
	//case s_node is not empty
}