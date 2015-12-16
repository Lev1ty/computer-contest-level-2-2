#include <iostream>
#include <queue>

int m[5][5], d[5][5];

void customBFS(int x, int y)
{
	x = y = 0;
	std::queue<int>Q;
	Q.push(x); Q.push(y);
	d[x][y] = 1;
	while (!Q.empty())
	{
		int x = Q.front(); Q.pop(); int y = Q.front(); Q.pop();
		if (x - 1 > 0 && m[x - 1][y] != 1 && d[x - 1][y] == 0)
		{
			Q.push(x - 1); Q.push(y);
			d[x - 1][y] = d[x][y] + 1;
		}
		if (x + 1 > 0 && m[x + 1][y] != 1 && d[x + 1][y] == 0)
		{
			Q.push(x + 1); Q.push(y);
			d[x + 1][y] = d[x][y] + 1;
		}
		if (y - 1 > 0 && m[x][y - 1] != 1 && d[x][y - 1] == 0)
		{
			Q.push(x); Q.push(y - 1);
			d[x][y - 1] = d[x][y] + 1;
		}
		if (y + 1 > 0 && m[x][y + 1] != 1 && d[x][y + 1] == 0)
		{
			Q.push(x); Q.push(y + 1);
			d[x][y + 1] = d[x][y] + 1;
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			std::cin >> m[i][j];
	/*for each (int i in m)
		for each (int j in m)
			std::cin >> m[i][j];*/
	customBFS(0, 0);
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			std::cout << d[i][j] << " ";
		std::cout << std::endl;
	}*/
	std::cout << d[4][4] << std::endl;
	return 0;
}