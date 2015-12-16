#include<iostream>
#include<vector>
#include<string>

using namespace std;

int N, M, T, Q;
int dis[1001][1001];
bool vis[1001][1001];

vector<int>adj[1001];
vector<int>q;

void bfs(int index, int stop)
{
	//cout << endl << endl << endl;
	for (int i : adj[index])
	{
		q.push_back(index);
		q.push_back(i);
		vis[index][i] = true;
		dis[index][i] = true;
	}

	/*cout << "queue: ";
	for (int i : q)
	{
		cout << i << " ";
	}
	cout << endl;*/

	while (!q.empty())
	{
		int r = q.front(); q.erase(q.begin());
		int c = q.front(); q.erase(q.begin());

		//cout << "In while loop r and c: " << r << " " << c << endl << endl;

		for (int i : adj[c])
		{
			int nr = c, nc = i;

			if (!vis[nr][nc])
			{
				q.push_back(nr);
				q.push_back(nc);
				dis[index][nc] = dis[index][c] + 1;
				vis[nr][nc] = true;
				
				/*cout << "dis array" << endl;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= N; j++)
					{
						cout << dis[i][j];
					}
					cout << endl;
				}

				cout << "vis array" << endl;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= N; j++)
					{
						cout << vis[i][j];
					}
					cout << endl;
				}*/

			}

			//cout << "In while loop forea loop: " << nr << " " << nc << endl << endl;
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

	/*for (int i = 0; i < M; i++)
	{
		cout << i << ": ";
		for (int j : adj[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}*/

	/*for (int i = 1; i <= M; i++)
	{
		q.clear();
		memset(vis, false, sizeof(vis));
		bfs(i);
	}*/

	cin >> Q;
	for (int i = 0, a, b; i < M; i++)
	{
		cin >> a >> b;

		q.clear();
		memset(vis, false, sizeof(vis));
		//memset(dis, 0, sizeof(dis));
		bfs(a,b);

		//cout << "Distance: " << dis[a][b] << endl;
		if (dis[a][b]) cout << dis[a][b] * T << endl;
		else cout << "Not enough hallways!" << endl;
	}
}