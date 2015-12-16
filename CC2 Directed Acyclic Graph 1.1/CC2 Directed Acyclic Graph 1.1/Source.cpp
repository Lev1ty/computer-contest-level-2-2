#include<iostream>
#include<queue>
using namespace std;
int adj[1002][1002], N, nds[1002];
bool cyclic;
queue<int>q; queue<int>l;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 1) nds[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (nds[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int n = q.front(); q.pop(); l.push(n);
		for (int i = 1; i <= N; i++) {
			if (adj[n][i] == 1) {
				nds[i]--;
				if (nds[i] == 0) {
					q.push(i);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (nds[i] < 0) {
			cyclic = true;
		}
	}
	cout << (cyclic?"NO":"YES") << endl;
	/*while (!l.empty()) {
		cout << l.front() << " "; l.pop();
	}*/
}