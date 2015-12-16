#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int start, end;
};
int adj[9][9];
queue<int>startlist; queue<int>order;
int main() {
	adj[1][7] = 1;adj[1][4] = 1;adj[2][1] = 1;adj[3][4] = 1;adj[3][5] = 1;
	node in;cin >> in.start >> in.end;
	while (in.start != 0) {
		adj[in.start][in.end] = 1;
		cin >> in.start >> in.end;
	}
	for (int j = 1; j <= 7; j++) {
		bool inedge = false;
		for (int i = 1; i <= 7; i++)
			if (adj[i][j] == 1)
				inedge = true;
		if (!inedge)startlist.push(j);
	}
	node check;
	while (!startlist.empty()) {
		check.start = startlist.front();startlist.pop();order.push(check.start);
		for (int i = 1; i <= 7; i++) {
			if (adj[check.start][i] == 1) {
				bool incoming = false;
				for (int j = 1; j <= 7; j++) {
					if (adj[j][i] == 1)
						incoming = true;
				}
				if (!incoming)startlist.push(check.start);
			}
		}
		for (int i = 1; i <= 7; i++)
			adj[check.start][i] = 0;
	}
	bool flag = false;
	for (int i = 1; i <= 7; i++)
		for (int j = 1; j <= 7; j++)
			if (adj[i][j] == 1)
				flag = true;
	if (flag)cout << "Cannot complete these tasks. Going to bed." << endl;
	else while (!order.empty()) {
		cout << order.front() << endl;
		order.pop();
	}
}