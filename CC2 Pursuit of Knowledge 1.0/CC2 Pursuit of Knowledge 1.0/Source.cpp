#include<iostream>
#include<vector>

using namespace std;

int dis[1001][1001], N, M, T, Q;
bool vis[1001][1001];
vector<int>adj[1001];
vector<int>q;

void bfs()
{
	for (int i = 1; i <= N; i++)
	{
		memset(vis, false, sizeof(vis));
		q.clear();
		for (int j : adj[i])
		{
			q.push_back(i);
			q.push_back(j);
			dis[i][j] = 1;
			vis[i][j] = true;
			//cout << i << " " << j << endl;
		}
		//cout << endl;
		while (!q.empty())
		{
			int r = q.front(), c = q.front();
			//cout << r << " " << c << endl;
			q.erase(q.begin()); q.erase(q.begin());
			for (int j : adj[c])
			{
				if (!vis[c][j])
				{
					q.push_back(c);
					q.push_back(j);
					//cout << c << " " << j << endl;
					dis[c][j] = dis[r][c] + 1;
					vis[c][j] = true;
					//cout << dis[c][j] << " " << dis[r][c] << endl;
				}
			}
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
		cout << i << ": ";
		for (int i : adj[i])
		{
			cout << i << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << vis[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << dis[i][j];
		}
		cout << endl;
	}
	bfs();
	cin >> Q;
	for (int i = 0, a, b; i < Q; i++)
	{
		cin >> a >> b;
		if (dis[a][b]) cout << dis[a][b] * T << endl;
		else cout << "Not enough hallways!" << endl;
	}
}