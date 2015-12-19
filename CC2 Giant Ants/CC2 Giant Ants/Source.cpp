#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N, M; cin >> N >> M;
	vector<vector<int>>adj_list;
	adj_list.resize(N + 1);
	for (int i = 0, x, y; i < M; ++i)
	{
		cin >> x >> y;
		adj_list.at(x).push_back(y);
	}
	vector<int>nodes(N + 1);
	nodes.at(1) = 1;
	int W; cin >> W;
	vector<int>spawn; spawn.reserve(W);
	for (int i = 0, z; i < W; ++i)
	{
		cin >> z;
		spawn.push_back(z);
	}
	vector<int>queue;
	for (vector<int>::iterator it = adj_list.at(1).begin(); it != adj_list.at(1).end(); ++it)
	{
		queue.push_back(1);
		queue.push_back(*it);
		nodes.at(*it) = 1;
	}
	vector<int>queue_s;
	int move_cnt = 1;
	while (!queue.empty())
	{
		int r_h = queue.front(); queue.erase(queue.begin());
		int c_h = queue.front(); queue.erase(queue.begin());
		for (vector<int>::iterator it = adj_list.at(c_h).begin(); it != adj_list.at(c_h).end(); ++it)
		{
			int nr_h = c_h;
			int nc_h = *it;
			if (nodes.at(nc_h) == 0)
			{
				nodes.at(nc_h) = 1;
				queue.push_back(nr_h);
				queue.push_back(nc_h);
			}
		}
		if (++move_cnt % 4 == 0)
		{
			if (move_cnt / 4 == 1)
			{
				for (int i = 0; i < spawn.size(); ++i)
				{
					for (int j = 0; j < adj_list.at(i).size(); ++j)
					{
						queue_s.push_back(spawn.at(i));
						queue_s.push_back(adj_list.at(i).at(j));
						nodes.at(i) = 2;
						nodes.at(j) = 2;
					}
				}
			}
			if (!queue_s.empty())
			{
				int r_s = queue_s.front(); queue_s.erase(queue_s.begin());
				int c_s = queue_s.front(); queue_s.erase(queue_s.begin());
				for (vector<int>::iterator it = adj_list.at(c_s).begin();it != adj_list.at(c_s).end(); ++it)
				{
					int nr_s = c_s;
					int nc_s = *it;
					if (nodes.at(nc_s) != 2)
					{
						nodes.at(nc_s) = 2;
						queue_s.push_back(nr_s);
						queue_s.push_back(nc_s);
					}
				}
			}
			move_cnt = 1;
		}
	}
	for (int& i : nodes)
	{
		cout << i << ' ';
	}
	cout << endl;
}