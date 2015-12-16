#include<iostream>
#include<string>
using namespace std;
int mvt_cnt, o_row, o_col, n_row, n_col;
string usr_in;
char keybrd[5][6] = {
	{'A','B','C','D','E','F'},
	{'G','H','I','J','K','L'},
	{'M','N','O','P','Q','R'},
	{'S','T','U','V','W','X'},
	{'Y','Z',' ','-','.','n'}
};
int main() {
	getline(cin, usr_in);
	for (int k = 0; k < usr_in.length(); k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				if (keybrd[i][j] == usr_in[k]) {
					n_row = i;
					n_col = j;
					/*cout << n_row << ' ' << n_col << endl;
					cout << o_row << ' ' << o_col << endl;
					cout << endl;*/
				}
			}
		}
		mvt_cnt += abs(n_row - o_row);
		mvt_cnt += abs(n_col - o_col);
		o_row = n_row;
		o_col = n_col;
	}
	mvt_cnt += (5 - n_col);
	mvt_cnt += (4 - n_row);
	cout << mvt_cnt << endl;
}