#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int r, c;
};
Node node;
int dis[1001][1001], N, M, T, Q;
vector<int> adj[1001];
vector<Node>q;
void bfs(int&index)
{
	q.clear();
	for (int&i : adj[index])
	{
		node.r = index;
		node.c = i;
		q.push_back(node);
		dis[node.r][node.c] = 1;
	}
	while (!q.empty())
	{
		int r = q.front().r; int c = q.front().c;
		q.erase(q.begin());
		for (int&j : adj[c])
		{
			int nr = c; int nc = j;
			dis[nr][nc] = dis[r][c] + 1;
			node.r = nr; node.c = nc; q.push_back(node);
		}
	}
}
int main()
{
	cin >> N >> M >> T;
	for (int i = 0, x, y; i < M; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}
	cin >> Q;
	for (int i = 0, a, b; i < Q; i++)
	{
		cin >> a >> b;
		if (dis[a][b])
		{
			cout << dis[a][b] << endl;
		}
		else
		{
			cout << "Not enough hallways!" << endl;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << i << ": ";
		for (int&j : adj[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dis[i][j] << ' ';
		}
		cout << endl << endl;
	}
}