//void test(vector<int>list,vector<int>cycle,int input,int seq_pos,bool flag) {
//	for (int x : list)cout << x << ' ';cout << endl;
//	for (int x : cycle)cout << x << ' ';cout << endl;
//	cout << input << ' ' << seq_pos << ' ' << flag << ' ' << endl;
//}
//int main() {
//	int num = -1; cin >> num;
//	while (num != 0) {
//		vector<int>list(num);
//		vector<int>cycle(num - 1);
//		int input = -1;
//		while (num-- > 0 && cin >> input)list.push_back(input);
//		for (int i = 1; i < cycle.size(); i++)cycle.push_back(list[i] - list[i - 1]);
//		int seq_pos = 1;
//		for (int i = 0; i < cycle.size(); i++)
//			if (cycle[0] == cycle[i] && i != seq_pos)
//				seq_pos = i;
//		bool flag = false;
//		if (seq_pos != 1)
//			for (int i = seq_pos, j = 0; i < cycle.size() && j < seq_pos; i++, j++)
//				if (cycle[j] != cycle[i])
//					flag = true;
//
//		test(list, cycle, input, seq_pos, flag);
//		
//		cin >> num;
//	}
//}
#include<iostream>
#include<vector>
using namespace std;
vector<int>input;
vector<int>cycle;
vector<int>sub_cyc;
int sub_cyc_length, in_length, sub_cyc_num;
int main() {
	while (cin >> in_length&&in_length != 0) {
		sub_cyc.clear();
		sub_cyc_length = 1;
		input.resize(in_length);
		cycle.resize(in_length - 1);
		for (int i = 0; i < input.size(); i++)cin >> input[i];
		for (int i = 0; i < input.size() - 1; i++)cycle[i] = input[i + 1] - input[i];
		sub_cyc.push_back(cycle[0]);
		for (int i = 1; i < cycle.size(); i++, sub_cyc_length++) {
			if (cycle[i] == cycle[0])
				break;
			sub_cyc.push_back(cycle[i]);
		}
		sub_cyc_num = static_cast<int>(cycle.size()) / sub_cyc_length;
		bool flag = false;
		for (int i = 0, j = 0; i < cycle.size(); i++, j++) {
			if (j == sub_cyc_length)j = 0;
			if (cycle[i] != sub_cyc[j]) {
				flag = true;
				//cout << i << ' ' << j << endl;
			}
		}
		cout <</* "ouput: " << cycle.size() << ' ' << sub_cyc_length << ' ' << */(flag ? 1 : sub_cyc_num)/* << ' ' << sub_cyc_num */<< endl;
		//---------------------------------------------------------------------------------
		/*cout << "input" << endl;
		for (int&i : input)cout << i << ' ';cout << endl;
		cout << "cycle" << endl;
		for (int&i : cycle)cout << i << ' ';cout << endl;
		cout << "sub_cycle" << endl;
		for (int&i : sub_cyc)cout << i << ' ';cout << endl;
		cout << "sub_cycle length";
		cout << sub_cyc_length << endl;*/
	}
}