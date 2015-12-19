#include<iostream>
#include<vector>
using namespace std;
int main()
{

	int N, M;
	cin >> N >> M;

	vector<vector<int>>adj(N + 1);
	for (int i = 0, x, y; i < M; ++i)
	{
		cin >> x >> y;
		adj.at(x).push_back(y);
		adj.at(y).push_back(x);
	}

	/*for (vector<int>& vec : adj)
	{
		for (int& i : vec)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	vector<int>node(N + 1);
	node.at(1) = 1;

	vector<int>dist(N + 1);

	/*for (int& i : dist)
	{
		cout << i << ' ';
	}
	cout << endl;*/

	int W;
	cin >> W;

	vector<int>q_a;
	for (int i = 0, n; i < W; ++i)
	{
		cin >> n;
		q_a.push_back(n);
		node.at(n) = 2;
	}

	/*for (int& i : q_a)
	{
		cout << i << ' ';
	}
	cout << endl;*/

	vector<int>q_h;
	for (int& i : adj.at(1))
	{
		/*q_h.push_back(1);*/
		q_h.push_back(i);
		node.at(i) = 1;
		dist.at(i) = 1;
	}

	/*for (int& i : q_h)
	{
		cout << i << ' ';
	}
	cout << endl;

	for (int& i : node)
	{
		cout << i << ' ';
	}
	cout << endl;*/

	for (int i = 2; !q_h.empty(); ++i)
	{
		/*int s_n = q_h.front();
		q_h.erase(q_h.begin());*/
		int n = q_h.front();
		q_h.erase(q_h.begin());
		for (int& i : adj.at(n))
		{
			if (node.at(i) == 0)
			{
				/*q_h.push_back(n_n);*/
				q_h.push_back(i);
				node.at(i) = 1;
				dist.at(i) = dist.at(n) + 1;
			}
		}

		if (i % 4 == 0)
		{
			int n = q_a.front();
			q_a.erase(q_a.begin());
			for (int& i : adj.at(n))
			{
				if (node.at(i) != 2)
				{
					q_a.push_back(i);
					node.at(i) = 2;
				}
			}
		}

		/*for (int& i : node)
		{
			cout << i << ' ';
		}
		cout << ' ' << ' ' << ' ' << i;
		cout << endl;*/

	}

	if (node.at(node.size() - 1) != 1)
	{
		cout << "sacrifice bobhob314" << endl;
	}
	else
	{
		cout << dist.at(dist.size() - 1) << endl;
	}

	/*for (int& i : dist)
	{
		cout << i << ' ';
	}
	cout << endl;*/
}