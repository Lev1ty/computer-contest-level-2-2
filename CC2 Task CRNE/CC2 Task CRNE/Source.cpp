#include<iostream>
using namespace std;
int N;
int main() {
	cin >> N;
	int a = N / 2;
	if (N == 1)
		cout << 2 << endl;
	if (N>1)
		cout << (N % 2 == 0 ? (a + 1)*(a + 1) : (a + 1)*(a + 2)) << endl;
}