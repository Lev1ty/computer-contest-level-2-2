#include "Algorithms.h"

int main()
{
	vector<vector<int>> adj_list;
	adj_list.push_back(vector<int>());
	vector<int> first_row;
	first_row.push_back(10);
	first_row.push_back(2);
	adj_list.push_back(first_row);
	vector<int> second_row;
	second_row.push_back(1);
	for (int i = 3; i <= 9; i++)
	{
		adj_list.push_back(vector<int>());
	}
	vector<int> tenth_row;
	tenth_row.push_back(1);
	adj_list.push_back(tenth_row);
	Bfs bfs1{ adj_list };
	for (vector<int>& vec : bfs1.Adj_List())
	{
		for (int& i : vec)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
	for (vector<int>& vec : bfs1.Dist())
	{
		for (int& i : vec)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}