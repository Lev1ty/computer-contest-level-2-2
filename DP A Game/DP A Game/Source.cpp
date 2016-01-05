#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
vector<int> input;
vector<vector<int>> memo;
int dp(vector<vector<int>>& memo, vector<int>& input, int N)
{
	int a, b, c;
	for (int i = 0; i < N; ++i)
	{
		for (int m = 0, n = i, z = 0; n < N; ++m, ++n, (++z) %= 6)
		{
			a = m + 2 <= N - 1 ? 
				memo.at(m + 2).at(n) : 0;
			b = m + 1 <= N - 1 && n - 1 >= 0 ? 
				memo.at(m + 1).at(n - 1) : 0;
			c = n - 2 >= 0 ? 
				memo.at(m).at(n - 2) : 0;
			memo.at(m).at(n) = max(input.at(m) + min(a, b), input.at(n) + min(b, c));
			cout << a << ", " << b << ", " << c << endl;
			cout << m << ", " << n << ", " << memo.at(m).at(n) << endl;
		}
	}
	return memo.at(0).at(N - 1);
}
int main()
{
	while (true)
	{
		input.resize(0); memo.resize(0);
		int N; cin >> N; memo.resize(N);
		for (vector<int>& v : memo)
		{
			v.resize(N);
		}
		for (int i = 0; i < N; ++i)
		{
			int j; cin >> j; input.push_back(j);
		}
		cout << dp(memo, input, N) << endl;
		for (vector<int>& v : memo)
		{
			for (int& i : v)
			{
				cout << i << ' ';
			}
			cout << endl;
		}cout << endl;
		cout << endl;
	}
}