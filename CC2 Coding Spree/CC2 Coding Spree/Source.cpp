#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void dp(vector<vector<int>>&memo, vector<pair<int,int>>& input,
	int row, int N) {
	if (row == 0) for (auto&num : memo.at(0)) num = 0;
	else if (row == 1) for (auto it = memo.at(1).begin() + input.at(1).second;
	it != memo.at(1).end(); ++it) *it = input.at(1).first;
	else {
		pair<int, int> current = input.at(row);
		int t_i = 0; auto it = memo.at(row).begin();
		for (; it != memo.at(row).begin() + current.second;++it, ++t_i)
			*it = memo.at(row - 1).at(t_i);
		for (; it != memo.at(row).end(); ++it, ++t_i) {
			if (memo.at(row - 1).at(t_i - current.second) + current.first >
				memo.at(row - 1).at(t_i)) 
				*it = current.first + memo.at(row - 1).at(t_i - current.second);
			else *it = memo.at(row - 1).at(t_i);
		}
		if (++row <= N)dp(memo, input, row, N);
		else return;
	}
}
int main() {
	//N number of problems
	//T total amount of time
	//V_i points
	//H_i time cost
	int N, T; cin >> N >> T;
	vector<pair<int,int>>input; input.reserve(N);
	for (int i = 0, V, H; i < N ; i++)
	{
		cin >> V >> H;
		pair<int, int> temp; temp.first = V; temp.second = H;
		input.push_back(temp);
	}
	vector<vector<int>>memo(N+1);
	for (vector<int>&vec : memo)  vec.resize(T + 1);
	dp(memo, input, 0, N);
	for (auto&vec : memo) {
		for (auto& num : vec) cout << num << ' ';
		cout << endl;
	}
}