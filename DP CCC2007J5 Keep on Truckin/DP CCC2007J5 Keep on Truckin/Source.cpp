#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
void memoize(int pos, vector<int>& memo, vector<int>& motels, int MIN, int MAX)
{
	int val = 0;
	for (int i = pos - 1; abs(motels.at(pos) - motels.at(i)) >= MIN&&abs((motels.at(pos) - motels.at(i)) <= MAX) && i >= 0; --i)
		val += memo.at(i);
	memo.push_back(val);
	if (pos == 1 && memo.back() == 0) memo.resize(0);
	else if (++pos < motels.size())
		memoize(pos, memo, motels, MIN, MAX);
}
int main()
{
	vector<int> motels = { 0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000 };
	int MAX, MIN, N, counter = 0; cin >> MIN >> MAX >> N;
	if (N > 0)
		for (int i = 0, val; i < N; ++i)
		{
			cin >> val;
			for (int i = 0; i < motels.size(); ++i)
				if (motels.at(i) >= val)
				{
					motels.insert(motels.begin() + i, val);
					break;
				}
		}
	//for (int i : motels)
	//{
	//	cout << i << ' ';
	//}
	vector<int> memo; memo.push_back(0);
	memoize(1, memo, motels, MIN, MAX);
	for (int& i : memo)
	{
		cout << i << ' ';
	}cout << endl;
}