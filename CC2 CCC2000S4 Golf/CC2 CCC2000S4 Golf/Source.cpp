#include <iostream>
using namespace std;
short D, N, m[33], mm[5281];
int main() {
	cin >> D >> N;
	for (int i = 1; i <= N; ++i)
		cin >> m[i];
	//for (int&i : m) cout << i << ' ';
	for (int i = 0; i <= N; ++i)
		for (int j = D; j >= 0; --j)
			if (mm[j - m[i]] + m[i] > mm[j]) mm[j] = mm[j - m[i]] + m[i];
	//for (int k = 0; k <= D; ++k) cout << mm[k] << ' ';
	cout << mm[D];
}