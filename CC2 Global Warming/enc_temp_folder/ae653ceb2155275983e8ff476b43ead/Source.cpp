#include<iostream>
#include<vector>
using namespace std;
void test(vector<int>list,vector<int>cycle,int input,int seq_pos,bool flag) {
	for (int x : list)cout << x << ' ';cout << endl;
	for (int x : cycle)cout << x << ' ';cout << endl;
	cout << input << ' ' << seq_pos << ' ' << flag << ' ' << endl;
}
int main() {
	int num = -1; cin >> num;
	while (num != 0) {
		vector<int>list(num);
		int input = -1;
		while (num-- > 0 && cin >> input)list.push_back(input);
		vector<int>cycle(num - 1);
		for (int i = 1; i < num; i++)cycle.push_back(list[i] - list[i - 1]);
		int seq_pos = 1;
		for (int i = 0; i < cycle.size(); i++)
			if (cycle[0] == cycle[i] && i != seq_pos)
				seq_pos = i;
		bool flag = false;
		if (seq_pos != 1)
			for (int i = seq_pos, j = 0; i < cycle.size() && j < seq_pos; i++, j++)
				if (cycle[j] != cycle[i])
					flag = true;
		
		cin >> num;
	}
}