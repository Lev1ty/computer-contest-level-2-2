#include <iostream>
#include <string>
using namespace std;
int main() {
	string in[9];
	string final;
	for (int i = 0; i < 10; i++) {
		getline(cin, in[i]);
		final += in[i];
	}
	cout << final << endl;
}