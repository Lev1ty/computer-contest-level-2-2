#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int num_pos = 1;
	while (num_pos > 0)
	{
		cin >> num_pos;
		if (num_pos <= 0) continue;
		else if (num_pos == 1)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			vector<stack<int>> vec(num_pos);
			for (int i = 0, j; i < num_pos; ++i)
			{
				cin >> j; vec.at(i).push(j);
			}
			if (num_pos == 2)
			{
				if (vec.at(0).top() > vec.at(1).top())
				{
					cout << "IMPOSSIBLE" << endl;
				}
				else
				{
					cout << 0 << endl;
				}
				continue;
			}
			else
			{
				int cnt = 0;
				queue<int> starts;
				if (vec.at(1).top() < vec.at(0).top())
				{
					starts.push(0);
				}
				if (vec.at(num_pos - 1).top() < vec.at(num_pos - 2).top())
				{
					starts.push(num_pos - 1);
				}
				for (int i = 1; i < num_pos - 1; ++i)
				{
					if (vec.at(i - 1).top() < vec.at(i).top())
					{
						starts.push(-1 * i);
					}
					else if (vec.at(i + 1).top() < vec.at(i).top())
					{
						starts.push(i);
					}
				}
				while (!starts.empty())
				{
					int pos = starts.front(); starts.pop();
					if (pos < 0)
					{
						pos *= -1;
						vec.at(pos - 1).push(vec.at(pos).top());
						vec.at(pos).pop();
						pos -= 1;
					}
					else
					{
						vec.at(pos + 1).push(vec.at(pos).top());
						vec.at(pos).pop();
						pos += 1;
					}
				}
			}
		}
	}
}