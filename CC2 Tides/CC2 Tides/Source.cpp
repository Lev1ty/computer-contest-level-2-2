#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int>v;
int main()
{
	cin >> N;
	for (int i = 0, z; i < N; ++i)
	{
		cin >> z;
		v.push_back(z);
	}
	int min_pos = 0, max_pos = 0;
	int min_val = 10000, max_val = 1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] < min_val)
		{
			min_val = v[i];
			min_pos = i;
		}
		if (v[i] > max_val)
		{
			max_val = v[i];
			max_pos = i;
		}
	}
	bool flag = false;
	for (int i = min_pos; i < max_pos; ++i)
	{
		if (v[i + 1] < v[i])
		{
			flag = true;
		}
	}
	if (flag) cout << "unknown" << endl;
	else cout << (max_val - min_val) << endl;
}