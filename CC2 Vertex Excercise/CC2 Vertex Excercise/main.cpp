//Adam Yu

#include <iostream>
#include <queue>

int M[7][7], V, E, Distance[7][7], end;
std::queue<int>Q;

void BFS(int u)
{
	Q.push(1);
	int counter = 1;
	Distance[1][1] = 0;
	while (!Q.empty())
	{
		int temp = Q.front(); Q.pop();
		for (int i = 0; i < 7; i++)
		{
			if (M[temp][i] == 1)//check adj matrix to see if there is path
			{
				Q.push(i);
				Distance[temp][i] = counter;
				if (i == u)
				{
					std::cout << Distance[temp][i] << std::endl;
					break;
				}
			}
		}
		counter++;
	}
}

int main()
{
	std::cin >> V >> E;
	for (int i = 0, x, y; i < E; i++)
	{
		std::cin >> x >> y;
		M[x][y]++;
		M[y][x]++;
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			std::cout << M[i][j] << " ";
		std::cout << std::endl;
	}
	std::cin >> end;
	BFS(end);
	/*do
	{
		int x = Q.front(); Q.pop(); c++;
		std::cout << x << std::endl;
		for (int i = 0; i < E; i++)
			if (M[x][i] == 1)
			{
				Q.push(i);
				D[x][i] = c;
			}
	} while (!Q.empty());
	std::cout << c << std::endl;*/
	//for (int i = 0; i < 7; i++)
	//	for (int j = 0; j < 7; j++)
	//		//check if all connectors are present for row i
	//		if (M[i][j] == 1)
	//		{
	//			Q.push(i);
	//			Q.push(j);
	//		}
	//while (!Q.empty())
	//{
	//	int counter = 1;
	//	int x = Q.front(); Q.pop();
	//	int y = Q.front(); Q.pop();
	//	if (x == counter && y == counter + 1)
	//		counter++;
	//	if (counter == 3)
	//		counter = 6;
	//}
}