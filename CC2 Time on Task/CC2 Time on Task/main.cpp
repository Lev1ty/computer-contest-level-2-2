#include <iostream>
//#include <vector>

int T, C, m, c;//Total, Cases, multiplier, counter
int V[100001];

//std::vector<int>V;
//
//int main()
//{
//	std::cin >> T >> C;
//	for (int i = 0, temp; i < C; i++)
//	{
//		std::cin >> temp;
//		V.push_back(temp);
//	}
//	min = V[0];
//	V.resize(V.size() + 2);
//
//	while (T>0)
//	{
//		for (int i : V)
//			if (V[i] < min)
//				min = V[i];
//		for (int i : V)
//			if (V[i] == min)
//			{
//				T -= min;
//				V.erase(V.begin() + i);
//				c++;
//			}
//	}
//	std::cout << c << std::endl;
//}

int main()
{
	std::cin >> T >> C;
	for (int i = 0, temp; i < C; i++)
	{
		std::cin >> temp;
		V[temp]++;
	}
	while (T>0)
	{
		for (int i = 0; i < 100001; i++)
			if (V[i] != 0)
			{
				if (T > 0)
				{
					T -= i;
					V[i]--;
					c++;
				}
				break;
			}
	}
	std::cout << c << std::endl;
}