#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Bag
{
	int weight, value;
};
void fill_memo(vector<vector<int>>& memo, vector<Bag>& choices, int items, int N)
{
	if (items == 0) for (auto& num : memo.at(0)) num = 0;
	else if (items == 1) for (auto it = memo.at(1).begin() + choices.at(1).weight; it != memo.at(1).end(); ++it) *it = choices.at(1).value;
	else
	{
		Bag current = choices.at(items);
		int t_i = 0; auto it = memo.at(items).begin();
		for (; it != memo.at(items).begin() + current.weight; ++it, ++t_i) *it = memo.at(items - 1).at(t_i);
		for (; it != memo.at(items).end(); ++it, ++t_i)
		{
			if (memo.at(items - 1).at(t_i - current.weight) + current.value > memo.at(items - 1).at(t_i)) *it = current.value + memo.at(items - 1).at(t_i - current.weight);
			else *it = memo.at(items - 1).at(t_i);
		}
	}
	if (++items <= N) fill_memo(memo, choices, items, N);
	else return;
}
int main()
{
	int N, W; cin >> N >> W;
	vector<vector<int>> memo(N + 1);
	for (auto& vec : memo) vec.resize(W + 1);
	vector<Bag> choices(N + 1);
	int t_weight, t_value;
	for (auto bag = choices.begin() + 1; bag != choices.end(); ++bag)
	{
		cin >> t_value >> t_weight;
		bag->weight = t_weight;
		bag->value = t_value;
	}
	fill_memo(memo, choices, 0, N);
	for (auto& vec : memo)
	{
		for (auto& num : vec)
		{
			cout << num << ' ';
		}
		cout << endl;
	}
}