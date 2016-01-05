#include <iostream>
#include <vector>
using namespace std;
void dp(int pos, vector<int>& memo)
{
	int in; cin >> in;
	if (pos <= 2) 
		memo.push_back(in);
	else
	{
		if (memo.at(pos - 2) > memo.at(pos - 3))
			memo.push_back(in + memo.at(pos - 2));
		else
			memo.push_back(in + memo.at(pos - 3));
	}
	if (++pos < memo.capacity())
		dp(pos, memo);
	else
		return;
}
int main()
{
	int N; cin >> N;
	vector<int> memo; memo.reserve(N + 1);
	memo.push_back(0);
	dp(1, memo);
	/*for (int& i : memo)
	{
		cout << i << ' ';
	}cout << endl;*/
	vector<int>::reverse_iterator it1 = memo.rbegin(), it2 = memo.rbegin() + 1;
	*it1 >= *it2 ? cout << *it1 : cout << *it2; cout << endl;
}