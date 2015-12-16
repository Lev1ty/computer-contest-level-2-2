#include<iostream>
#include<string>
using namespace std;
int N; string s[32][2]; bool good;
bool compare(string &first, string &second) {
	if (sizeof(first) != sizeof(second)) return false;
	else for (int i = 0; i < sizeof(first)+1; i++)
		if (first[i] != second[i]) return false;
	return true;
}
int main() {
	cin >> N;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= N; j++)
			cin >> s[j][i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; i++) {
			if (j == i) continue;
			else if (compare(s[j][0],s[i][1]) && compare(s[j][1],s[i][0])) {
				cout << s[i][0] << " " << s[i][1] << " " << s[j][0] << " " << s[j][1] << endl;
				good = true; break;
			}
			else good = false;
		}
	if (good) cout << "good" << endl;
	else cout << "bad" << endl;
}