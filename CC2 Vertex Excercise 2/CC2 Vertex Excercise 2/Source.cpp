#include <iostream>
#include <queue>

int Distance[6], Visited[6], Matrix[6][6], V, E;
std::queue<int>Q;

int main()
{
	std::cin >> V >> E;
	//input
	for (int i = 0, x, y; i < E; i++)
	{
		std::cin >> x >> y;
		Matrix[--x][--y]++; 
		Matrix[y][x]++;
	}
	//print
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//BFS
	Q.push(1);
	Visited[1] = 1;
	while (!Q.empty())
	{
		int temp = Q.front(); Q.pop();
		for (int i = 0; i < 6; i++)
		{
			if (Matrix[temp][i] == 1 && Visited[i] == 0)
			{
				Q.push(i);
				Visited[i] = 1;
				Distance[i] = Distance[temp] + 1;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		std::cout << Distance[i] << " ";
		std::cout << Visited[i] << " ";
	}
}