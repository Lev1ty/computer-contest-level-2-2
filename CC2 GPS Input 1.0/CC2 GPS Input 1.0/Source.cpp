#include<iostream>
#include<string>
using namespace std;
int main() {
	string usr_in;
	getline(cin, usr_in);
	int cnt = 0, r = 0, c = 0;
	for (int i = 0; i < usr_in.size(); i++) {
		int nr, nc;
		if (usr_in[i] >= 'A'&&usr_in[i] <= 'Z') {
			nr = (usr_in[i] - 'A') / 6;
			nc = (usr_in[i] - 'A') % 6;
		}
		else if (usr_in[i] == ' ') {
			nr = 4;
			nc = 2;
		}
		else if (usr_in[i] == '-') {
			nr = 4;
			nc = 3;
		}
		else if (usr_in[i] == '.') {
			nr = 4;
			nc = 4;
		}
		cnt += abs(nr - r);
		cnt += abs(nc - c);
		r = nr;
		c = nc;
	}
	cnt += (5 - c);
	cnt += (4 - r);
	cout << cnt << endl;
}