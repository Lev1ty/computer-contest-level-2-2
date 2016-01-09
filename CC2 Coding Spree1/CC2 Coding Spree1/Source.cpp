#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> input[2];
vector<vector<int>> dp;
int main() {
	int N, T; cin >> N >> T;
	input[0].push_back(0);
	input[1].push_back(1);
	for (int i = 0, V, H; i < N; i++) {
		cin >> V >> H;
		input[0].push_back(V);
		input[1].push_back(H);
	}
	dp.resize(N + 1);
	for_each(dp.begin(), dp.end(), [T](vector<int>&v) {v.resize(T + 1);});
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < input[1].at(i)) dp.at(i).at(j) = dp.at(i - 1).at(j);
			else dp.at(i).at(j) = max(dp.at(i - 1).at(j), input[0].at(i) + dp.at(i - 1).at(j - input[1].at(i)));
		}
	}
	/*for_each(dp.begin(), dp.end(),
		[](vector<int>&vec) {
		for_each(vec.begin(), vec.end(), [](int i) {cout << i << ' ';}); 
		cout << endl;
	});*/
	cout << dp.back().back() << endl;
}