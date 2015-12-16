#include<iostream>
#include<vector>
using namespace std;
struct node { int start, end; };
node input, search;
int N, M;
vector<vector<int>>r_adj;
vector<int>s_nodes;
vector<int>output;
int main() {
	cin >> N >> M;
	r_adj.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> input.start >> input.end;
		r_adj[input.end].push_back(input.start);
	}
	for (int i = 1; i <= N; i++) {
		if (r_adj[i].size()==0) {
			s_nodes.push_back(i);
		}
	}
	while (!s_nodes.empty()) {
		search.end = s_nodes.front();
		s_nodes.erase(s_nodes.begin());
		r_adj[search.end].push_back(-1);
		//cout << search.end << ' ';
		output.push_back(search.end);
		for (vector<int>&i : r_adj) {
			for (int j = 0; j < i.size(); j++) {
				if (i[j] == search.end) {
					i.erase(i.begin()+j);
				}
			}
		}
		/*for (vector<int>&i : r_adj) {
			for (int&j : i) {
				cout << j << ' ';
			}
			cout << endl;
		}*/
		for (int i = 1; i <= N; i++) {
			if (r_adj[i].size() == 0) {
				s_nodes.push_back(i);
			}
		}
		/*for (vector<int>&i : r_adj) {
			for (int&j : i) {
				cout << j << ' ';
			}
			cout << endl;
		}*/
	}
	/*for (int&i : output) {
		cout << i << ' ';
	}*/
	if (output.size() == N)cout << "Y" << endl;
	else cout << "N" << endl;
}