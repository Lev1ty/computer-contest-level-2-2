#ifndef BFS_H
#define BFS_H
#include "Algorithms.h"

class Bfs
{
public:
	Bfs();
	Bfs(const vector<vector<int>>& adj_list);
	Bfs(const vector<vector<int>>& adj_list, const int& start_row);
	~Bfs();
	vector<int> Queue() { return queue_; }
	vector<vector<int>> Adj_List() { return adj_list_; }
	vector<vector<int>> Dist() { return dist_; }
private:
	vector<int> queue_;
	vector<vector<int>> adj_list_;
	vector<vector<int>> dist_;
	void bfs(const int& row);
	inline const int max(const int a, const int b) { return (a < b ? b : a); }
};

#endif // !BFS_H

