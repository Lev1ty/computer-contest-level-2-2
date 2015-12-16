#include <iostream>
#include <string>
using namespace std;
int main() {
	string in, letters = "IOSHZXN";
	cin >> in;
	bool flag = true;
	//cout << in[0];
	for (unsigned int i = 0; i < in.length(); i++) {
		if (letters.find(in[i]) != string::npos)
			continue;
		else
			flag = false; break;
		/*if (letters.find(in[i]) == string::npos)
			flag = false; break;*/
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}