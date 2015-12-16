//graph cycle practice
#include<iostream>
#include<vector>
using namespace std;
struct node { int start, end; };
int N, adj[10002][10002];
vector<int>start;
int main() {
	cin >> N;
	node in;
	for (int i = 1; i <= N; i++) {
		cin >> in.start >> in.end;
		adj[in.start][in.end] = 1;
	}
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int j = 1; j <= N; j++)
			if (adj[j][i] == 1)
				flag = true;
		if (!flag) start.push_back(i);
	}
}