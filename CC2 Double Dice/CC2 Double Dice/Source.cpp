#include<iostream>
#define comp(a, b, c) (a == b ? c : (a > b ? a : b))
using namespace std;
int n, A, D, A_s, D_s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A >> D;
		comp(A, D, 0) == 0 ? 0: (comp(A,D,0) == A? A_s += A : D_s += D);
	}
	cout << 100 - D_s << endl << 100 - A_s << endl;
}