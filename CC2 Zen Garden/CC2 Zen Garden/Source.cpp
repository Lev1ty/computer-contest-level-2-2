#include<iostream>
#include<vector>
#define MIN(a,b) (a>b?b:a)
using namespace std;
int main()
{
	int tot_val = 0;
	int N; cin >> N;
	vector<int>garden;
	for (int i = 0, z; i < N; ++i)
	{
		cin >> z;
		tot_val += z;
		garden.push_back(z);
	}
	int M; cin >> M;
	for (int i = 0, z, y; i < M; ++i)
	{
		cin >> z >> y; --z;
		int min_val = MIN(garden[z], garden[z + 1]);
		if (y > min_val)
		{
			tot_val -= min_val;
		}
		else
		{
			tot_val -= y;
		}
	}
	cout << tot_val << endl;
}