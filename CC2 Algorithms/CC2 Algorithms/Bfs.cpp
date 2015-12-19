#include "Bfs.h"


Bfs::Bfs()
{
	queue_.clear();
	adj_list_.clear();
	dist_.clear();
}

Bfs::Bfs(const vector<vector<int>>& adj_list)
	:adj_list_(adj_list)
{
	Bfs();
	bfs(1);
}

Bfs::Bfs(const vector<vector<int>>& adj_list, const int & start_row)
	:adj_list_(adj_list)
{
	Bfs();
	bfs(start_row);
}

Bfs::~Bfs()
{
}

void Bfs::bfs(const int& row)
{
	if (adj_list_[row].empty())
	{
		cerr << "adj_list_ is empty." << endl;
	}
	else
	{
		for (int& i: adj_list_[row])
		{	
			const int max_n = max(row, i) + 2;
			dist_.resize(max_n);
			for (vector<int>& vec : dist_)
			{
				vec.resize(max_n);
			}
			dist_[row][i] = 1;
			queue_.push_back(row);
			queue_.push_back(i);
		}
	}
	while (!queue_.empty())
	{
		int r = queue_.front(); queue_.erase(queue_.begin());
		int c = queue_.front(); queue_.erase(queue_.begin());
		for (int& i : adj_list_[c])
		{
			if (dist_[c][i] == 0)
			{
				queue_.push_back(c);
				queue_.push_back(i);
				const int max_n = max(c, i) + 2;
				if (max_n > dist_.size())
				{
					dist_.resize(max_n);
					for (vector<int>& vec : dist_)
					{
						vec.resize(max_n);
					}
				}
				dist_[c][i] = dist_[r][c] + 2;
			}
		}
	}
}
