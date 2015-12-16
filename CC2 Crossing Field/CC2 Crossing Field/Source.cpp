#include<iostream>
#include<queue>
#include<utility>
int N, H, mat[1002][1002], vis[1002][1002], d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
std::queue<std::pair<int,int>>Q; std::pair<int, int>P;
int main()
{
	std::cin >> N >> H;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			std::cin >> mat[i][j];
	P.first = 1; P.second = 1; Q.push(P);
	vis[1][1] = 1;
	while (!Q.empty())
	{
		int r = Q.front().first; int c = Q.front().second; Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + d[i][0]; int nc = c + d[i][1];
			if (nr >= 1 && nc >= 1 && nr <= N + 1 && nc <= N + 1 && (mat[nr][nc] - H <= mat[r][c] || mat[nr][nc] + H >= mat[r][c]) && vis[nr][nc] == 0)
			{
				P.first = nr; P.second = nc; Q.push(P);
				vis[nr][nc] = 1;
				if (vis[N][N] == 1)
				{
					std::cout << "yes" << std::endl;
					return 0;
				}
			}
		}
	}
	std::cout << "no" << std::endl;
	/*for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			std::cout << vis[i][j];
		}
		std::cout << std::endl;
	}*/
	return 0;
}